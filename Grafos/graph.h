#ifndef GRAPH_H_
#define GRAPH_H_

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Graph{
  private:
  int nodes;
  std::vector<int> *adjList;
  int *adjMat;

  public:
  Graph();
  void loadGraphList(string,int, int);
  void loadGraphMat(string, int, int);
  void List(int, int);
  void Matrix(int, int);
  void nprintAdjList();
  void nprintAdjMat();
  std::string printAdjList();
  std::string printAdjMat();
  string DFS(int, int);
  void DFSHelper(int current, int goal, stack<int> &st, bool visited[], int paths[], vector<int> &visitedOrder);
  string printVisited(vector<int> &visitedOrder);
  string printPath(int[], int, int);
  void sortAdjList();
};

Graph::Graph(){
  nodes = 10;
  adjList = new vector<int>[100];
  adjMat = new int [nodes * nodes];
  for (int i = 0; i < nodes*nodes; i++)
    adjMat[i] = 0;
}

void Graph::loadGraphList(string file, int vert, int arc){
  string archivo = file;
  int partida, destino;
  nodes = vert;
  string line, partTemp, destTemp;
 
  
  ifstream leerArchivo (archivo);
  if (leerArchivo.is_open()){
    while (getline(leerArchivo, line) ){
      partTemp = line.substr(1,1);
      partida = stoi(partTemp);
      destTemp = line.substr(4,4);
      destino = stoi(destTemp);
      //leerArchivo >> partida >> destino;
      //cout << partida << ",";
      List(partida, destino);
    }
    leerArchivo.close();
  }else{
    cout << "No se pudo abrir el archivo" << endl;
  }
}
void Graph::loadGraphMat(string file, int vert, int arc){
  string archivo = file;
  int partida, destino;
  nodes = vert;
  string line, partTemp, destTemp;
 
  
  ifstream leerArchivo (archivo);
  if (leerArchivo.is_open()){
    while (getline(leerArchivo, line) ){
      partTemp = line.substr(1,1);
      partida = stoi(partTemp);
      destTemp = line.substr(4,4);
      destino = stoi(destTemp);
      //leerArchivo >> partida >> destino;
      //cout << partida << ",";
      Matrix(partida, destino);
    }
    leerArchivo.close();
  }else{
    cout << "No se pudo abrir el archivo" << endl;
  }
}

void Graph::List(int part, int dest){
  adjList[part].push_back(dest);
  adjList[dest].push_back(part);
}
void Graph::Matrix(int part, int dest){
  adjMat[part * nodes + dest] = 1;
  adjMat[dest * nodes + part] = 1;
}
void Graph::nprintAdjList(){
  sortAdjList();
  for (int i = 0; i < nodes; i++){
    cout << "vertex " << i <<" : ";
    for (int j = 0; j < adjList[i].size(); j++){
      cout << adjList[i][j] << " ";
    }
  }
}
void Graph::nprintAdjMat(){
  for (int i = 0; i < nodes; i++){
    for (int j = 0; j < nodes; j++){
      cout <<adjMat[i * nodes + j]<< " ";
    }
  }
}

void Graph::sortAdjList(){
  for (int i = 0; i < nodes; i++){
    sort(adjList[i].begin(), adjList[i].end());
  }
}

std::string Graph::printAdjList(){
  sortAdjList();
  std::stringstream aux;
  for (int i = 0; i < nodes; i++){
    aux << "vertex " << i <<" : ";
    for (int j = 0; j < adjList[i].size(); j++){
      aux << adjList[i][j] << " ";
    }
    
  }
  return aux.str();
}
std::string Graph::printAdjMat(){
  std::stringstream aux;
  for (int i = 0; i < nodes; i++){
    for (int j = 0; j < nodes; j++){
      aux <<adjMat[i * nodes + j]<< " ";
    }
  }
  return aux.str();
}

/*
void Graph::depthSearchFirst(int start, int goal){
  stack <int> st;
  list <int> visited;
  vector <vector<int>> paths(nodes, vector<int>(1, -1));
  st.push(start);
  depth(start, goal, st, visited, paths);
  printPath(paths, start, goal);

}



void Graph::depth(int curr, int goal, stack<int> &st, list<int> &visited, vector<vector<int>> &paths){
  if (curr == goal){
    printVisited(visited);
  }else {
    curr = st.top();
    st.pop();
    visited.push_back(curr);
    for (int i = 0; i < adjList[curr].size(); i++){
      if (!contains(visited, adjList[curr][i])){
        st.push(adjList[curr][i]);
        paths[adjList[curr][i]][0] = curr;
      }
    }
    depth(curr, goal, st, visited, paths); 
  }
}

bool Graph::contains(list<int> ls, int node){
  list<int>::iterator it;
  it = find(ls.begin(), ls.end(), node);
  if(it != ls.end()){
    return true;
  }else{
    return false;
  }
} */
string Graph::DFS(int start, int goal){
  //sortAdjList();
  stringstream aux;
  stack<int> st;
  bool visited[nodes];
  vector<int> visitedOrder;
  int path[nodes];
  for (int i = 0; i < nodes; i++){
    visited[i] = false;
    path[i] = -1;
  }
  st.push(start);
  DFSHelper (start, goal, st, visited, path, visitedOrder);
  aux << printVisited(visitedOrder) << printPath(path, start, goal);
  return aux.str();
}

void Graph::DFSHelper(int current, int goal, stack<int> &st, bool visited[], int paths[], vector<int> &visitedOrder){
  if (current == goal){
    return;
  }else if (st.empty()){
    cout << "no encontrado";
  }else{
    current = st.top();
    st.pop();
    visited[current] = true;
    visitedOrder.push_back(current);
    for (int i = 0; i < adjList[current].size(); i++){
      if(visited[adjList[current][i]] == false){
        st.push(adjList[current][i]);
        paths[adjList[current][i]] = current;
      }
    }
    DFSHelper(current, goal, st, visited, paths, visitedOrder);
  }
}

string Graph::printVisited(vector<int> &visitedOrder){
  stringstream aux;
  aux << "visited:";
  for (int i = 0; i < visitedOrder.size(); i++){
    aux << " " << visitedOrder[i];
  }
  return aux.str();
}

string Graph::printPath(int path[], int start, int goal){
  stringstream aux;
  stack<int> reverse;
  int node = goal;
  while (node != start){
    reverse.push(node);
    node = path[node];
  }
  reverse.push(start);
  aux << " path:";
  while (!reverse.empty()){
    aux << " "<< reverse.top();
    reverse.pop();
  }
  return aux.str();
}

 
#endif

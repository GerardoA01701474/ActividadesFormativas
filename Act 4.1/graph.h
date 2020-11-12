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
  void nprintAdjList();
  void nprintAdjMat();
  void depthSearchFirst(int, int);
  void List(int, int);
  void Matrix(int, int);
  void sortAdjList();
  std::string printAdjList();
  std::string printAdjMat();
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

 
#endif

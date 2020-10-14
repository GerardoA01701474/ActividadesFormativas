#ifndef BST_H_
#define BST_H_


#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class T> class BST;

template <class T> 
class Node{
  private:
  T value;
  Node *left, *right;
  public:
  Node(T);
  Node(T,Node*, Node*);
  void add(T);
  void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
  void postorder(std::stringstream&) const;
  void levelBylevel(std::stringstream&) const;
  int height() const;
  void removeChilds();
  bool ancestors(int, std::stringstream&) const;
  int whatlevelamI(T);
  void printlevel(std::stringstream&, int) const;
  friend class BST<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0){}
template <class T>
Node<T>::Node(T val, Node *le,Node *ri){
  value = val;
  left = le;
  right = ri;
}
template <class T>
void Node<T>::printlevel(std::stringstream &aux, int level) const  {

	if(level == 0){
		if (aux.tellp() != 1) {
				aux << " ";
		}
		aux << value;
	}
	if (left != 0) {
		left->printlevel(aux, level -1);
	}
	if (right != 0) {
		right->printlevel(aux, level -1);
	}

}

template <class T>
void Node<T>::levelBylevel(std::stringstream &aux) const {
	int level = height();
	for(int i = 0; i < level; i++){
		printlevel(aux, i);
	}
}

template <class T>
int Node<T>::whatlevelamI(T val){
  int level = 1;
  if (value == val){
    return level;
  }else if(val < value){
    if (left != 0){
      return left->whatlevelamI(val) + 1;
    } 
  }else{
    if (right != 0){
      return right->whatlevelamI(val) + 1;
    }
  }
}

template <class T>
void Node<T>::add(T val){
  if (val < value){
    if (left != 0){
      left->add(val);
    }else{
      left = new Node<T>(val);
    }
  }else{
    if (right != 0){
      right->add(val);
    }else{
      right = new Node<T>(val);
    }
  }
}

template <class T>
void Node<T>::inorder(std::stringstream &aux)const{ //en donde se está imprimiendo el valor???
  if (left != 0){
    left->inorder(aux);
  }
  if (aux.tellp() != 1){
    aux << " ";
  }
  aux << value;
  if (right != 0){
    right->inorder(aux);
  }
}

template <class T>
void Node<T>::preorder(std::stringstream &aux)const{
  aux << value;
  if (left != 0){
    aux << " ";
    left->preorder(aux);
  }
  if (right != 0){
    aux << " ";
    right->preorder(aux);
  }
}

template <class T>
void Node<T>::postorder(std::stringstream &aux)const{
  if (left != 0){
    left->postorder(aux);
  }
  
  if (right != 0){
    right->postorder(aux);
  }
  if (aux.tellp() != 1){
    aux << " ";
  }
  aux << value;
}



template <class T>
int Node<T>::height() const{
  int cleft = 0;
  int cright = 0;

  if (left != 0){
    cleft = left->height() + 1;
  }
  if (right != 0){
    cright = right->height() + 1;
  }
  if (cright == 0 && cleft == 0){
    return 1;
  } 
  if (cleft > cright){
    return cleft;
  }
  return cright;  //por qué no se puede usar un else??
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

template<class T>
bool Node<T>::ancestors(int val, std::stringstream& aux) const{
	if (val == value) {
	  return true;
	} else if (val < value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (left != 0 && left->ancestors(val,aux));
	} else if (val > value) {
		if (aux.tellp() != 1) {
			aux << " ";
		}
		aux << value;
		return (right != 0 && right->ancestors(val,aux));
	}
}

template<class T>
class BST{
  private:
  Node<T> *root;
  public: 
  BST();
  ~BST();
  void add(T);
  string inorder() const;
	string preorder() const;
  string postorder() const;
  string levelBylevel() const;
  int height();
  void clear();
  string visit() const;
  string ancestors(T) const;
  int whatlevelamI(T); 
};
template<class T>
BST<T>::BST(){
  root = 0;
}

template<class T>
BST<T>::~BST(){
  clear();
}

template <class T>
void BST<T>::clear() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}



template <class T>
void BST<T>::add(T val){
  if (root != 0){
    root->add(val);
  }else {
    root = new Node<T>(val);
  }
}

template<class T>
string BST<T>::visit() const{
  std::stringstream aux;
  if (root != 0){
    aux << preorder() << '\n';
    aux << inorder() << '\n';
    aux << postorder() << '\n';
    aux << levelBylevel();
  }
  return aux.str();
}

template <class T>
string BST<T>::inorder() const{
  std::stringstream aux;
  aux << "[";
  if (root != 0){
    root->inorder(aux);
  }
  aux << "]";
  return aux.str();

}
template <class T>
string BST<T>::preorder() const{
  std::stringstream aux;
  aux << "[";
  if (root != 0){
    root->preorder(aux);
  }
  aux << "]";
  return aux.str();
}
template <class T>
string BST<T>::postorder() const{
  std::stringstream aux;
  aux << "[";
  if (root != 0){
    root->postorder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T>
string BST<T>::levelBylevel() const{
  std::stringstream aux;
  aux << "[";
  if (root != 0){
    root->levelBylevel(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T>
string BST<T>::ancestors(T val) const {
	std::stringstream aux;
	aux << "[";
	if (root != 0) {
		if(!root->ancestors(val, aux))
			return "[]";
	}
	aux << "]";
	return aux.str();
}

template <class T>
int BST<T>::whatlevelamI(T val){
  if (root != 0){
    root->whatlevelamI(val);
  }
}
template <class T>
int BST<T>::height(){
  if (root != 0){
    root->height();
  }
}

#endif

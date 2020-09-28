#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);
	T	    value;
	Link<T> *next;
	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template <class T>
class List {
public:
	List();
	List(const List<T>&) throw (OutOfMemory);
	~List();
	void add(T) throw (OutOfMemory);
	int find(T) const;
	std::string toString() const;
	void update(int, T) throw (IndexOutOfBounds);
	T    remove(int) throw (IndexOutOfBounds);
  void clear();
  void addFirst(T) throw (OutOfMemory);

private:
	Link<T> *head;
	int 	size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
  clear();
}

template <class T>
void List<T>::add(T val) throw (OutOfMemory) {
  Link<T> *p, *newLink;
  newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}
  if (head == 0){
    addFirst(val);
    return;
  }
  p = head;
  while (p->next != 0){
    p = p->next;
  } 
  newLink->next = 0;
  p->next = newLink;
  size ++;
}


template <class T>
int List<T>::find(T val) const{
  Link<T> *p;
  p = head;
  int pos = 0;
  while (p->next != 0){
    p = p->next;
    pos++;
    if (p->value == val){
      return pos; 
    }
  }
  return -1;
}


template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
List<T>::List(const List<T> &source) throw (OutOfMemory) {
  head = source.head;
  size = source.size;
}

template <class T>
void List<T>::update(int index, T val) throw (IndexOutOfBounds) {
  int pos = 0;
  Link<T> *p;
  p = head;
  while (pos != index){
    p = p->next;
    pos++;
  }
  p->value = val;
}

template <class T>
T List<T>::remove(int index) throw (IndexOutOfBounds) {
  int pos = 0;
  Link<T> *p;
  Link<T> *borrar;
  borrar = 
  p = 0;
  borrar = head;
  int val;
  if (index == 0){
    p = head;
    head = p->next;
    val = p->value;
    delete p;
    size--;
    return val;
  }
  while (pos != index){
    p = borrar;
    borrar = borrar->next;
    pos ++;
  }
  val = borrar->value; 
  p->next = borrar->next;
  delete borrar;
  size --;
	return val;
}
template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}
template <class T>
void List<T>::addFirst(T val) throw (OutOfMemory) {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}
	newLink->next = head;
	head = newLink;
	size++;
}


#endif  /* LINKEDLIST_H_ */

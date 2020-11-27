#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class DList;


template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
	
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value),
previous(source.previous), next(source.next) {}

template <class T>
class DList {
public:
	DList();
	DList(const DList<T>&) throw (OutOfMemory);
	~DList();

	void addFirst(T) throw (OutOfMemory);
	void add(T) throw (OutOfMemory);
	void removeFirst() throw (NoSuchElement);
	void removeLast() const throw (NoSuchElement);
	int  length() const;
	int find(T) const;
	bool empty() const;
	void clear();
  std::string toStringBackward() const;
  std::string toStringForward() const;
	std::string toString() const;
	void operator= (const DList&) throw (OutOfMemory);



	void update(int, T) throw (IndexOutOfBounds);
	int  indexOf(T) const;
	int  lastIndexOf(T) const;
	void    remove(int) throw (IndexOutOfBounds);
	bool removeFirstOcurrence(T);
	bool removeLastOcurrence(T);

private:
	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;

	
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
bool DList<T>::empty() const {
  if (size == 0){
    return true;
  }
	return 0;
}

template <class T>
int DList<T>::length() const {
	return size;
}

template <class T>
int DList<T>::find(T val) const {
  int pos = 0;
	DLink<T> *p;
	p = head;
	while (p != 0) {
		if (p->value == val) {
			return pos;
		}
    pos ++;
		p = p->next;
	}
	return -1;
}


template <class T>
void DList<T>::addFirst(T val) throw (OutOfMemory) {
  DLink<T> *p;
  p = new DLink<T>(val);
  if (empty()){
    head = p;
    tail = p;
  }else{
    p->next = head;
    head->previous = p;
    head = p; 
  }
  size++;
}

template <class T>
void DList<T>::add(T val) throw (OutOfMemory) {
  if (size == 0){
    addFirst(val);
  }else{
    DLink<T> *p;
    p = new DLink<T>(val);
    p->previous = tail;
    tail->next = p;
    tail = p;
  }
 size ++;
}

template <class T>
void DList<T>::removeFirst() throw (NoSuchElement) {
  	T val;
	DLink<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;
	val = p->value;

	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;
}


template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}

template <class T>
DList<T>::DList(const DList<T> &source) throw (OutOfMemory) {
	DLink<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
		tail = 0;
	} else {
		p = source.head;
		head = new DLink<T>(p->value);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new DLink<T>(p->value, q, 0);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}


template <class T>
void DList<T>::update(int index, T val) throw (IndexOutOfBounds) {
	int pos;
	DLink<T> *p;



	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	p->value = val;
}

template <class T>
int DList<T>::indexOf(T val) const {
	int index;
	DLink<T> *p;

	index = 0;
	p = head;
	while (p != 0) {
		if (p->value == val) {
			return index;
		}
		index++;
		p = p->next;
	}
	return -1;
}

template <class T>
int DList<T>::lastIndexOf(T val) const {
}

template <class T>
void DList<T>::remove(int index) throw (IndexOutOfBounds) {
  int pos;
	T val;
	DLink<T> *p;
  std::cout << "hola: " << size;
	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		return removeFirst();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	val = p->value;
	p->previous->next = p->next;
	if (p->next != 0) {
		p->next->previous = p->previous;
	}
	size--;

	delete p;
  
  /*
  DLink<T> *p;
  DLink<T> *borrar;
  p = 0;
  borrar = head;
  int pos = 0;

  if (index == 0){
    p = head;
    head = head->next;
    head->previous = 0;
    delete p;
    size --;
  }
  while (pos != index){
    p = borrar;
    borrar = borrar->next;
    pos ++;
  }
  p->next = borrar->next;
  borrar->next->previous= borrar->previous;
  delete borrar;
  size --;*/
} 

template <class T>
bool DList<T>::removeFirstOcurrence(T val) {
	return false;
}

template <class T>
bool DList<T>::removeLastOcurrence(T val) {
	return false;
}
template <class T>
	std::string DList<T>::toStringForward() const {
		std::stringstream aux;
		DLink<T> *p;
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
	std::string DList<T>::toStringBackward() const {
		std::stringstream aux;
		DLink<T> *p;
		p = tail;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->previous != 0) {
				aux << ", ";
			}
			p = p->previous;
		}
		aux << "]";
		return aux.str();
	}
///////////////////////////////////////////////////////////


#endif /* DLIST_H_ */

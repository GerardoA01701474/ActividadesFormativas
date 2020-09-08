#ifndef SORTS_H_
#define SORTS_H_
#include <iostream>
#include <vector>
#include <list>

template <class T>
class Sorts {
private:
	void swap(std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
  void copyarray(std::vector<T>&, std::vector<T>&, int, int);
public:
	void ordenaBurbuja(std::vector<T>&);
	void ordenaSeleccion(std::vector<T>&);
	void ordenaMerge(std::vector<T>&);
  int busqSecuencial(const std::vector<T>&, int num);
  int busqBinaria(const std::vector<T>&, int num);
};

template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) {
	T aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

template <class T> 
void Sorts<T>::ordenaSeleccion(std::vector<T> &vector) {
	//std::vector<T> v(source);
  for (int i = 0; i <= vector.size() - 1; i++){
    int pos = i;
    for (int j = i; j <= vector.size() - 1; j++){
      if (vector[pos] > vector[j]){
        pos = j;
      }
    }
    if (pos != i){
      swap (vector, pos, i);
    }
  }
	return;
}

template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T>&vector){
  for (int i = vector.size()-1; i > 0; i--){
    for (int j = 0; j < i; j++){
      if (vector[j] > vector[j + 1]){
        swap(vector, j, j + 1);
      }
    }
  }
  return;
}
template<class T>
void Sorts<T>::copyarray(std::vector<T>&A, std::vector<T>&B, int low, int high){
  for (int i = low; i <= high; i++){
    A[i] = B[i];
  }
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T>&A, std::vector<T>&B, int low, int mid, int high){
  int i = low;
  int j = mid + 1;
  int k = low;

  while (i <= mid && j <= high){  //checa que sigamos dentro de ambos arreglos
    if (A[i] < A[j]){  //compara el low con el mid
      B[k] = A[i];
      i++;
    }else{
      B[k] = A[j];  // guarda el más pequeño en el la posición low (k)
      j++;
    }
    k++;   // avanza porque esa posición ya está ordenada
  }
  if (i > mid){
    for (;j <= high; j++){
      B[k++] = A[j];
    }
  }else{
    for (;i <= mid; i++){
      B[k++] = A[i];
    }
  }
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T>&A, std::vector<T>&B, int low, int high){
  int mid;
  if ((high - low) < 1){ // por qué este es el caso base?, si necesitamos que al final quede cada valor solito
    return;
  }else {
    mid = (low + high) / 2;
    mergeSplit(A,B,low, mid);
    mergeSplit(A,B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyarray(A,B, low, high);
  }

}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T>&vector){
  std::vector<T> temp(vector.size());
  int low = 0;
  int high = vector.size() - 1;
  mergeSplit(vector, temp, low, high);
}

template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T>&vector, int num){
  for (int i = 0; i <= vector.size() - 1; i++){
    if (vector[i] == num){
      return i;
    }
  }
  return -1;
}
template <class T>
int Sorts<T>::busqBinaria(const std::vector<T>&vector, int num){
  int mid;
  int high = vector.size() - 1;
  int low = 0;

  while (low < high){
    mid = (high + low) / 2;
    if (num == vector[mid]){
      return mid;
    }else if (num < vector[mid]){
      high = mid - 1;
    }else if (num > vector[mid]){
      low = mid + 1; 
    }
  }
  return low; 
}


#endif

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//#include "exception.h"
#include <iostream>

class Funciones{
  public: 

  int sumaIterativa(int n) {   
	int acum = 0;
	for (int i = 0; i <= n; i++) {
		acum += i;
	}
	return acum;
}
int sumaRecursiva(int n) {
   if (n == 0) {    
		return 0;
	} else {
		return n + sumaRecursiva(n - 1);
	}
}
int sumaDirecta(int n) {
  int suma;
  suma = n*(n+1)/2;
  return suma;
}

};
#endif

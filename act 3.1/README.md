# Visit():
todas la funciones dentro de Visit() son de complejidad lineal porque requieren recorrer todos los nodos para imprimirlos, en caso de levelbylevel podría ser O(2N)
# la función add() :
el caso promedio es O(log(n)) gracias a que los numeros más pequeños siempre están a la izquierda y los grandes a la derecha, lo que facilita encontrar dónde se debe agregar un nuevo nodo. En el peor de los casos tendrías un arbol degenerado lo que haría que sea de complejidad O(n)
# height():
compara todos los nodos para poder saber cual es el nodo más profundo, por esto es de complejidad O(n)
# ancestors():
es de complejidad O(log(n)) en el caso promedio, al saber que a la derecha siempre habrá valores mayores y a la izquierda menores
se puede descartar la mitad de nodos en cada paso. Pero en el peor de los casos tienes un árbol degenerado por lo que sería de complejidad O(n)
# whatlevelamI:
es de complejidad O(log(n)) en el caso promedio, al saber que a la derecha siempre habrá valores mayores y a la izquierda menores
se puede descartar la mitad de nodos en cada paso. Pero en el peor de los casos tienes un árbol degenerado por lo que sería de complejidad O(n)

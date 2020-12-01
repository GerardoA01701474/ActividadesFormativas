# loadAdjMat:
recorre cada linea del archivo de texto y luego con ayuda de una función auxiliar (Matrix) incluye cada numero en la matriz de adyacencia, esto lo hace de complejidad O(n)
# loadAdjList:
recorre cada linea del archivo de texto y luego con ayuda de una función auxiliar (List) incluye cada numero en la matriz de adyacencia, esto lo hace de complejidad O(n)
# PrintMatriz:
recorre la matriz con dos for loops, esto lo convierte en O(n^2), comparando cada nodo con cada uno de los otros nodos con los que este está conectado
# PrintList:
recorre la lista con dos for loops, esto lo convierte en O(n^2), comparando cada nodo con cada uno de los otros nodos con los que este está conectado
# Recorridos DFS y BFS
Es de complejidad: O(Vertice * Arco) debido a que recibe un nodo de partida y un nodo de llegada, por lo que se recorren todos los nodos de manera que se seguira una línea hasta no poder avanzar mas esto se ira haciendo de manera recursiva al no encontrar otro camino se regresará al anterior y se exploraran las ramas que queden por visitar, 
Considerando el peor de los casos en el que el nodo de partida es el primero y el nodo meta es el último, su complejidad se toma como la multiplicacion de nodos por arcos

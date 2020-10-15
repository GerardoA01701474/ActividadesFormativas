# Visit():
todas la funciones dentro de Visit() son de complejidad 
# la función add() es O(log(n)):
gracias a que los numeros más pequeños siempre están a la izquierda y los grandes a la derecha, lo que facilita encontrar dónde se debe agregar un nuevo nodo
# height():
necesita recorrer todos los nodos para poder saber cual es el nodo más profundo, por esto es de complejidad O(n)
# ancestors():
gracias a que el arbol está ordenado siempre. Al saber que a la derecha siempre habrá valores mayores y a la izquierda menores
se puede descartar la mitad de nodos en cada paso.
# whatlevelamI:
es de complejidad O(log(n)) gracias a que el arbol está ordenado siempre. Al saber que a la derecha siempre habrá valores mayores y a la izquierda menores
se puede descartar la mitad de nodos en cada paso.

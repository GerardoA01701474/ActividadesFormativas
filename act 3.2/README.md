# push:
es de complejidad logaritmica O(log(n)) porque en el peor de los casos (cuando el numero a ingresar es el más pequeño) solo recorre una rama para acomodar el nuevo numero
# pop:
es de complejidad O(log(n)) porque desoués de sacar el más prioritario y reemplazarlo por el último hijo,  recorre una sola rama del arbol haciendo la función heapify para regresar el último hijo hasta abajo
# top:
es complejidad constante O(1) porque solo devuelve el primer valor del arreglo, es decir data[0]
# empty:
regresa un booleano, si el contador es 0 devuelve true, si no es False. solo es un paso, entonces es constante O(1)
# size:
es complejidad constante O(1), lo que hace esta función es devolver la variable de instancia "lenght", solo necesita un paso

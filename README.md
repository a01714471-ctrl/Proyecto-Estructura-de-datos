# Sistema de consulta y organización de estadísticas de jugadores de la NBA

## Descripción del avance

En este avance desarrollamos un programa para consultar y organizar información de jugadores de la NBA. El programa utiliza una clase Jugador para almacenar diferentes atributos de cada jugador, como:

* Nombre
* Equipo
* Posición
* Edad
* Altura
* Puntos
* Rebotes
* Asistencias

La información de los jugadores se almacena en un vector<Jugador>. El programa permite mostrar los datos y ordenarlos utilizando diferentes atributos.

Para realizar el ordenamiento se implementó el algoritmo **Merge Sort**, utilizando programación genérica mediante una clase `Sorts<T>`. El algoritmo puede ordenar los jugadores por cualquiera de los ocho atributos disponibles.

El programa está dividido en archivos para mantener una estructura modular:

* main.cpp: contiene el menú principal, los datos de los jugadores y la interacción con el usuario.
* jugador.h: contiene la clase Jugador, sus atributos, constructores, getters y el método toString().
* sorts.h: contiene la implementación del algoritmo Merge Sort y la lógica para ordenar los jugadores de acuerdo con el criterio seleccionado.


## ¿Cómo usar el programa?

Al ejecutar el programa se muestra el menú principal:

ESTADISTICAS DE JUGADORES NBA
1. Mostrar jugadores
2. Ordenar jugadores
3. Salir

### 1. Mostrar jugadores

Al seleccionar la opción 1, el programa muestra todos los jugadores junto con sus estadísticas.

### 2. Ordenar jugadores

Al seleccionar la opción 2, aparece un segundo menú con los criterios disponibles:

Ordenar jugadores por:
1. Nombre
2. Equipo
3. Posicion
4. Edad
5. Altura
6. Puntos
7. Rebotes
8. Asistencias

Se debe seleccionar un número del 1 al 8. El programa utiliza Merge Sort para ordenar los jugadores según el atributo seleccionado y posteriormente muestra los datos ya ordenados.

Por ejemplo, si se selecciona la opción 6, los jugadores se ordenan de acuerdo con sus puntos.

### 3. Salir

Al seleccionar la opción 3, el programa termina su ejecución.

Si se introduce una opción que no corresponde con el menú, el programa muestra el mensaje:

Opcion no valida.

## Cumplimiento de las sub-competencias

### SICT0301: Evalúa los componentes

Para este avance se realizó el análisis de complejidad del algoritmo de ordenamiento utilizado.

El programa utiliza **Merge Sort**, cuya complejidad temporal es:

| Caso          | Complejidad |
| ------------- | ----------- |
| Mejor caso    | O(n log n)  |
| Caso promedio | O(n log n)  |
| Peor caso     | O(n log n)  |

La función mergeSort primero realiza una copia de los datos y posteriormente llama a mergeSplit.

mergeSplit divide recursivamente el arreglo en dos partes hasta llegar a elementos individuales. Después utiliza mergeArray para combinar las partes nuevamente en orden.

La división genera dos llamadas recursivas sobre mitades del arreglo y la combinación requiere recorrer los elementos de las partes que se están uniendo. Por esto, el comportamiento de Merge Sort se expresa como:

**O(n log n)**

La función mergeArray tiene una complejidad de **O(n)** porque recorre los elementos de las dos partes para colocarlos en el arreglo temporal y posteriormente utiliza copyArray, que también recorre los elementos una vez.

La función copyArray tiene una complejidad de **O(n)** debido al ciclo for que copia los elementos desde el arreglo temporal.

Por lo tanto, considerando las funciones que participan en el ordenamiento, la complejidad total del algoritmo utilizado es:

**Mejor caso: O(n log n)**
**Caso promedio: O(n log n)**
**Peor caso: O(n log n)**

El análisis de complejidad también está indicado directamente en sorts.h mediante comentarios en las funciones y en las instrucciones principales de los ciclos, condiciones y llamadas recursivas.

### SICT0302: Toma decisiones

Para este proyecto se decidió utilizar **Merge Sort** como algoritmo de ordenamiento, considerando las características del problema y la complejidad temporal de las diferentes alternativas.

El programa debe permitir organizar los datos de los jugadores utilizando diferentes atributos, como nombre, equipo, posición, edad, altura, puntos, rebotes y asistencias. Aunque actualmente el programa trabaja con una cantidad pequeña de jugadores, el problema está diseñado para poder trabajar con una cantidad mayor de datos. Por esta razón, se consideró importante seleccionar un algoritmo cuyo rendimiento se mantenga eficiente conforme aumente el número de elementos.

Se analizaron principalmente **Bubble Sort, Selection Sort, Insertion Sort y Merge Sort**:

| Algoritmo | Mejor caso | Caso promedio | Peor caso |
|---|---:|---:|---:|
| Bubble Sort | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| **Merge Sort** | **O(n log n)** | **O(n log n)** | **O(n log n)** |

Bubble Sort, Selection Sort e Insertion Sort pueden presentar una complejidad de O(n²) en su caso promedio. Esto significa que, conforme aumenta la cantidad de jugadores, el número de operaciones necesarias puede crecer de manera cuadrática.

Por otro lado, Merge Sort mantiene una complejidad de O(n log n) en el mejor, promedio y peor caso. Esta característica es importante para el proyecto porque el algoritmo mantiene un comportamiento predecible incluso cuando los datos no se encuentran previamente ordenados.

La diferencia puede observarse al comparar el crecimiento de ambas complejidades. Para una cantidad n de datos, un algoritmo O(n²) realiza un crecimiento cuadrático, mientras que un algoritmo O(n log n) tiene un crecimiento menor. Por ejemplo, si la cantidad de datos aumenta considerablemente, la diferencia entre ambas complejidades también aumenta. Por ello, aunque con pocos jugadores la diferencia de tiempo pueda ser pequeña, Merge Sort resulta más adecuado para un programa que puede manejar conjuntos de datos más grandes.

Además, Merge Sort se adapta a la estructura del programa porque divide el arreglo en partes más pequeñas, ordena cada una de ellas y posteriormente las combina. En este proyecto, la función mergeSplit realiza la división recursiva y mergeArray combina las partes utilizando el atributo seleccionado por el usuario.

Otra razón para utilizar este algoritmo es que no es necesario implementar un algoritmo diferente para cada atributo. El mismo Merge Sort puede ordenar por nombre, equipo, posición, edad, altura, puntos, rebotes o asistencias. El parámetro criterio determina qué atributo se utiliza durante las comparaciones, mientras que la estructura general del algoritmo permanece igual.

Por lo tanto, la decisión de utilizar Merge Sort se fundamenta principalmente en su complejidad temporal O(n log n) en los tres casos y en su capacidad para reutilizar la misma lógica de ordenamiento con diferentes atributos. Esto permite que el programa cumpla con la necesidad de organizar los datos y, al mismo tiempo, tenga un algoritmo que pueda mantener un buen comportamiento al aumentar la cantidad de información.

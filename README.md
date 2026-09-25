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

```text
===== ESTADISTICAS DE JUGADORES NBA =====
1. Mostrar jugadores
2. Ordenar jugadores
3. Salir
```

### 1. Mostrar jugadores

Al seleccionar la opción 1, el programa muestra todos los jugadores junto con sus estadísticas.

### 2. Ordenar jugadores

Al seleccionar la opción 2, aparece un segundo menú con los criterios disponibles:

```text
Ordenar jugadores por:
1. Nombre
2. Equipo
3. Posicion
4. Edad
5. Altura
6. Puntos
7. Rebotes
8. Asistencias
```

Se debe seleccionar un número del 1 al 8. El programa utiliza Merge Sort para ordenar los jugadores según el atributo seleccionado y posteriormente muestra los datos ya ordenados.

Por ejemplo, si se selecciona la opción 6, los jugadores se ordenan de acuerdo con sus puntos.

### 3. Salir

Al seleccionar la opción 3, el programa termina su ejecución.

Si se introduce una opción que no corresponde con el menú, el programa muestra el mensaje:

```text
Opcion no valida.
```

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

Para organizar las estadísticas de los jugadores se seleccionó **Merge Sort** como algoritmo de ordenamiento.

La selección se debe a que el programa necesita ordenar los mismos datos utilizando diferentes atributos, como nombre, equipo, posición, edad, altura, puntos, rebotes y asistencias.

Merge Sort permite realizar este proceso mediante la función mergeArray, donde se determina el atributo que se utilizará para comparar los jugadores. El parámetro criterio permite seleccionar el atributo correspondiente:

* `1`: Nombre
* `2`: Equipo
* `3`: Posición
* `4`: Edad
* `5`: Altura
* `6`: Puntos
* `7`: Rebotes
* `8`: Asistencias

De esta manera, un mismo algoritmo puede utilizarse para organizar los datos de diferentes formas sin tener que crear un algoritmo de ordenamiento diferente para cada atributo.

Además, Merge Sort se utiliza correctamente mediante el proceso de dividir el arreglo, ordenar las partes y finalmente combinarlas en orden. En este avance se utiliza únicamente este algoritmo de ordenamiento.

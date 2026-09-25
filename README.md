# Proyecto-Estructura-de-datos
# Sistema de consulta y organización de jugadores de la NBA

## Descripción del proyecto

Este proyecto consiste en un programa para consultar y organizar información de jugadores de la NBA.

El programa contiene información como:

- Nombre
- Equipo
- Posición
- Edad
- Altura
- Puntos por partido
- Rebotes por partido
- Asistencias por partido

El usuario puede mostrar la información de los jugadores, ordenar los datos utilizando diferentes atributos y buscar un jugador por su nombre.

## ¿Cómo usar el programa?

Al iniciar el programa se muestra un menú con las siguientes opciones:

1. **Mostrar jugadores:** muestra la información de todos los jugadores.
2. **Ordenar jugadores:** permite seleccionar el atributo por el cual se quieren ordenar los jugadores.
3. **Buscar jugador:** permite buscar un jugador por su nombre utilizando búsqueda binaria.
4. **Salir:** termina la ejecución del programa.

Para ordenar los jugadores, el usuario puede seleccionar diferentes atributos, como:

- Nombre
- Equipo
- Posición
- Edad
- Altura
- Puntos
- Rebotes
- Asistencias

El programa utiliza **Merge Sort** para realizar los ordenamientos. Para realizar una búsqueda por nombre, primero se ordenan los jugadores por nombre y después se utiliza **Binary Search**.

## Cumplimiento de sub-competencias

### SICT0301: Evalúa los componentes

Se realizó un análisis de complejidad del algoritmo de ordenamiento utilizado.

El programa utiliza **Merge Sort**, cuya complejidad es:

| Caso | Complejidad |
|---|---|
| Mejor caso | O(n log n) |
| Caso promedio | O(n log n) |
| Peor caso | O(n log n) |

La complejidad de Merge Sort se obtiene porque el arreglo se divide en dos partes de manera recursiva y después se combinan las partes ordenadas.

La función `mergeSplit` realiza dos llamadas recursivas con la mitad del arreglo y `mergeArray` realiza la combinación de los elementos en tiempo lineal.

También se utiliza **Binary Search** para buscar jugadores por nombre. Su complejidad es:

| Caso | Complejidad |
|---|---|
| Mejor caso | O(1) |
| Caso promedio | O(log n) |
| Peor caso | O(log n) |

### SICT0302: Toma decisiones

Para este problema se seleccionó **Merge Sort** como algoritmo de ordenamiento, ya que permite organizar los jugadores de manera eficiente y tiene una complejidad de `O(n log n)` en sus diferentes casos.

Además, se utiliza **Binary Search** para realizar búsquedas por nombre. Debido a que este algoritmo necesita que los datos estén ordenados, primero se utiliza Merge Sort para ordenar los jugadores por nombre.

La implementación permite utilizar el mismo algoritmo de Merge Sort para ordenar los jugadores utilizando diferentes atributos, por lo que se adapta a las necesidades del programa.

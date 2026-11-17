
# NBA Player Stats

## Descripción del proyecto

NBA Player Stats es un programa desarrollado en C++ que permite administrar información estadística de jugadores de la NBA. El sistema permite consultar, ordenar, agregar y eliminar jugadores, además de guardar los cambios en archivos de texto para conservar la información entre ejecuciones.

El proyecto utiliza un `vector` como estructura principal para almacenar los registros, ocho árboles AVL como índices para realizar búsquedas por diferentes atributos y el algoritmo Merge Sort para ordenar los jugadores.

## Funcionalidades

El programa cuenta con las siguientes opciones:

1. **Mostrar jugadores:** presenta todos los registros en una tabla organizada.
2. **Ordenar jugadores:** permite ordenar los registros de manera ascendente utilizando cualquiera de los ocho atributos.
3. **Buscar jugadores:** permite consultar jugadores mediante un criterio específico y muestra todos los registros que coinciden con el valor ingresado.
4. **Agregar jugador:** permite registrar un nuevo jugador y actualizar los ocho índices AVL.
5. **Eliminar jugador:** permite buscar jugadores por nombre y seleccionar cuál eliminar cuando existen varios registros con el mismo nombre.
6. **Guardar jugadores:** almacena los registros actuales en el archivo principal.
7. **Salir:** guarda los cambios y termina la ejecución.

## Atributos de los jugadores

Cada jugador se representa mediante la clase `Jugador`, que contiene los siguientes atributos:

| Atributo | Tipo de dato |
|---|---|
| Nombre | `string` |
| Equipo | `string` |
| Posición | `string` |
| Edad | `int` |
| Altura | `int` |
| Puntos | `double` |
| Rebotes | `double` |
| Asistencias | `double` |

La clase cuenta con un constructor, métodos para consultar cada atributo y una función `toString()` para representar la información del jugador.

## Estructura del proyecto

| Archivo | Descripción |
|---|---|
| `main.cpp` | Contiene el menú principal, las funciones auxiliares y la lógica para administrar los jugadores. |
| `jugador.h` | Define la clase `Jugador` y sus atributos. |
| `AVL.h` | Implementa los árboles AVL utilizados como índices de búsqueda. |
| `sorts.h` | Implementa el algoritmo Merge Sort. |
| `jugadores.txt` | Contiene los registros originales y almacena los cambios realizados. |
| `jugadores_ordenados.txt` | Almacena el resultado de ordenar los jugadores. |

## Estructuras de datos utilizadas

### 1. Vector

Se utiliza un `vector<Jugador>` como estructura principal para almacenar todos los jugadores.

**Justificación:**

- Permite acceder directamente a cualquier registro mediante su índice.
- Facilita mostrar todos los jugadores.
- Permite agregar registros dinámicamente.
- Facilita trabajar con Merge Sort, ya que el algoritmo utiliza vectores.
- Permite guardar y recuperar fácilmente los registros mediante archivos.

**Complejidades:**

| Operación | Complejidad |
|---|---|
| Acceso por índice | O(1) |
| Recorrido completo | O(n) |
| Agregar al final | O(1) amortizado |
| Buscar un registro | O(n) |
| Eliminar un registro | O(n) |

La eliminación tiene complejidad O(n) porque primero se localiza el registro y posteriormente se utiliza `erase`, que puede desplazar los elementos restantes.

### 2. Árboles AVL

Se implementaron ocho árboles AVL independientes mediante la clase `AVL<Jugador>`. Cada árbol organiza los jugadores utilizando un atributo diferente:

| Árbol AVL | Criterio |
|---|---|
| `nombre` | Nombre |
| `equipo` | Equipo |
| `posicion` | Posición |
| `edad` | Edad |
| `altura` | Altura |
| `puntos` | Puntos |
| `rebotes` | Rebotes |
| `asistencias` | Asistencias |

La clase `Indices` administra los ocho árboles. Cuando se agrega un jugador, este se inserta en todos los índices; cuando se elimina, se retira de cada uno.

**Manejo de valores repetidos:**

Cada nodo contiene un vector llamado `repetidos`, que almacena los jugadores que comparten el mismo valor para el criterio correspondiente.

Por ejemplo, si varios jugadores pertenecen al mismo equipo, todos se almacenan en el mismo nodo del árbol que organiza por equipo.

**Justificación:**

- Mantiene los datos organizados mediante un árbol balanceado.
- Permite realizar búsquedas por cualquiera de los ocho atributos.
- Evita recorrer todo el vector principal para localizar una clave.
- Permite manejar diferentes jugadores que comparten un mismo valor.

**Complejidades:**

| Operación | Mejor caso | Caso promedio | Peor caso |
|---|---|---|---|
| Inserción | O(1) | O(log n) | O(log n) |
| Búsqueda de clave (`find`) | O(1) | O(log n) | O(log n) |
| Búsqueda de jugadores (`search`) | O(1) | O(log n + r) | O(log n + r) |
| Eliminación (`remove`) | O(1) | O(log n + d) | O(log n + d) |
| Recorrido inorder | O(n) | O(n) | O(n) |
| Recorrido preorder | O(n) | O(n) | O(n) |
| Eliminar todos los nodos | O(1) | O(n) | O(n) |

Donde:

- `n` representa la cantidad de jugadores almacenados en el árbol.
- `r` representa la cantidad de jugadores que coinciden con la clave buscada.
- `d` representa la cantidad de registros repetidos que pueden revisarse dentro del nodo durante una eliminación.

En una búsqueda, localizar la clave requiere O(log n), mientras que recuperar todos los jugadores que comparten esa clave requiere O(r).

En una eliminación, localizar el nodo requiere O(log n). Si el jugador se encuentra dentro del vector de repetidos, puede ser necesario recorrer hasta O(d) elementos.

Las rotaciones simples y dobles utilizadas para mantener el balance del árbol tienen complejidad O(1).

### 3. Clase Indices

La clase `Indices` administra los ocho árboles AVL y permite realizar operaciones sobre ellos de manera conjunta.

| Operación | Complejidad |
|---|---|
| Agregar un jugador a los ocho índices | O(log n) |
| Buscar jugadores por un criterio | O(log n + r) |
| Eliminar un jugador de los ocho índices | O(log n + d) |

Estas complejidades consideran que se realizan ocho operaciones AVL, una por cada atributo. Como la cantidad de árboles es constante, no modifica el orden asintótico.

## Algoritmo de ordenamiento

### Merge Sort

Se implementó Merge Sort en el archivo `sorts.h` para ordenar los jugadores de acuerdo con cualquiera de sus ocho atributos.

El algoritmo utiliza el enfoque de divide y vencerás:

1. Divide recursivamente el vector en dos mitades.
2. Ordena cada mitad de manera independiente.
3. Combina las dos mitades en un solo segmento ordenado.
4. Repite el proceso hasta obtener el vector completamente ordenado.

La implementación cuenta con los siguientes métodos auxiliares:

- `comparar()`: compara dos jugadores de acuerdo con el criterio seleccionado.
- `copyArray()`: copia los elementos de un segmento del vector auxiliar.
- `mergeArray()`: combina dos mitades previamente ordenadas.
- `mergeSplit()`: divide recursivamente el vector y coordina las combinaciones.
- `mergeSort()`: prepara los vectores y ejecuta el algoritmo.

**Complejidad de Merge Sort:**

| Caso | Complejidad |
|---|---|
| Mejor caso | O(n log n) |
| Caso promedio | O(n log n) |
| Peor caso | O(n log n) |
| Espacio auxiliar | O(n) |

El algoritmo mantiene la misma complejidad temporal en todos los casos porque siempre divide el vector en mitades y realiza las combinaciones correspondientes.

**Justificación de la elección:**

Se seleccionó Merge Sort porque ofrece una complejidad temporal O(n log n) incluso en el peor caso. Además, permite ordenar los registros sin modificar directamente el vector original, ya que trabaja con una copia y devuelve un nuevo vector ordenado.

El ordenamiento se realiza de manera ascendente y puede utilizar cualquiera de los ocho atributos de los jugadores.

## Consultas implementadas

El sistema permite realizar búsquedas mediante los siguientes criterios:

1. Nombre.
2. Equipo.
3. Posición.
4. Edad.
5. Altura.
6. Puntos.
7. Rebotes.
8. Asistencias.

El usuario selecciona el criterio y proporciona el valor que desea consultar.

La búsqueda se realiza utilizando el árbol AVL correspondiente. Si existen varios jugadores con el mismo valor, el programa recupera todos los registros coincidentes y los presenta en una tabla.

La complejidad de la consulta es:

**O(log n + r)**

Donde `n` representa la cantidad de jugadores y `r` la cantidad de registros que coinciden con el valor buscado.

## Análisis de complejidad de los demás componentes

Además de las estructuras de datos y el algoritmo de ordenamiento, el programa contiene funciones auxiliares para mostrar, convertir, cargar, guardar y administrar los registros.

| Función o componente | Complejidad | Descripción |
|---|---|---|
| `mostrarJugadores()` | O(n) | Recorre el vector y muestra todos los registros. |
| `convertirEntero()` | O(L) | Convierte una cadena a entero y valida su contenido. |
| `convertirDouble()` | O(L) | Convierte una cadena a double y valida su contenido. |
| `convertirJugador()` | O(L) | Separa y convierte los ocho campos de una línea del archivo. |
| `cargarJugadores()` | O(n log n) | Lee los registros y los inserta en el vector y en los ocho árboles AVL. |
| `guardarJugadores()` | O(n) | Recorre el vector y escribe los registros en un archivo. |
| `crearClave()` | O(L) | Construye un objeto temporal para realizar una búsqueda. |
| `capturarJugador()` | O(1) | Captura los atributos de un nuevo jugador, considerando una cantidad fija de campos. |
| `mismoJugador()` | O(1) | Compara los ocho atributos de dos jugadores, bajo el modelo de costo utilizado. |

Donde `L` representa la longitud de la cadena procesada.

### Complejidad de las operaciones principales

| Operación del menú | Complejidad |
|---|---|
| Mostrar jugadores | O(n) |
| Ordenar jugadores | O(n log n) |
| Buscar jugadores | O(log n + r) |
| Agregar jugador | O(log n) |
| Eliminar jugador | O(n + log n + d) |
| Guardar jugadores | O(n) |

**Consideraciones:**

- La operación de ordenar incluye Merge Sort y la presentación de los resultados. Su complejidad dominante es O(n log n).
- La búsqueda utiliza el índice AVL correspondiente y recupera todos los registros coincidentes.
- Agregar un jugador actualiza el vector y los ocho árboles AVL.
- Eliminar un jugador incluye la búsqueda por nombre, su eliminación de los ocho árboles y la búsqueda y eliminación del registro en el vector. El recorrido del vector hace que la complejidad total sea O(n) en el peor caso.
- Guardar jugadores recorre todos los registros y los escribe en el archivo correspondiente.

## Análisis de complejidad general del programa

Considerando las operaciones principales, el programa presenta las siguientes complejidades:

| Operación | Complejidad temporal |
|---|---|
| Mostrar todos los jugadores | O(n) |
| Ordenar todos los jugadores | O(n log n) |
| Buscar por atributo | O(log n + r) |
| Agregar un jugador | O(log n) |
| Eliminar un jugador | O(n) |
| Cargar los registros iniciales | O(n log n) |
| Guardar los registros | O(n) |

La operación de mayor complejidad temporal entre las operaciones principales es el ordenamiento mediante Merge Sort, con O(n log n).

La carga inicial también presenta O(n log n), debido a que cada jugador se inserta en los ocho índices AVL.

Por lo tanto, considerando estas operaciones, la complejidad temporal dominante del programa es:

**O(n log n)**

En cuanto al espacio, el programa mantiene:

- Un vector principal con los `n` jugadores.
- Ocho árboles AVL que almacenan una referencia lógica de cada jugador mediante sus propios registros.
- Vectores de repetidos dentro de los nodos.
- Un vector auxiliar para los resultados de las búsquedas.
- Un vector temporal utilizado por Merge Sort.

El almacenamiento de los ocho índices representa O(8n), que asintóticamente equivale a O(n), aunque utiliza un factor constante adicional de memoria.

Merge Sort requiere O(n) de espacio auxiliar, además del espacio O(log n) utilizado por las llamadas recursivas.

Por lo tanto, el espacio total asintótico del programa es:

**O(n)**

## Manejo de archivos

El programa utiliza archivos de texto para cargar y conservar la información de los jugadores.

### jugadores.txt

Es el archivo principal del sistema.

- Se lee automáticamente al iniciar el programa.
- Cada línea representa un jugador.
- Los campos están separados por punto y coma (`;`).
- Los registros válidos se almacenan en el vector y se insertan en los ocho índices AVL.
- Se actualiza cuando el usuario selecciona la opción de guardar o cuando sale del programa.

El formato de cada registro es:

```text
Nombre;Equipo;Posicion;Edad;Altura;Puntos;Rebotes;Asistencias
```

### jugadores_ordenados.txt

Es el archivo generado cuando el usuario ejecuta la opción de ordenar.

- Contiene los jugadores ordenados de acuerdo con el criterio seleccionado.
- Se genera a partir del vector devuelto por Merge Sort.
- No reemplaza el archivo principal `jugadores.txt`.

### Lectura y escritura

La lectura se realiza mediante `ifstream` y la escritura mediante `ofstream`.

La función `convertirJugador()` verifica que cada línea contenga exactamente ocho campos y que los valores numéricos puedan convertirse correctamente antes de incorporar el registro al sistema.

La función `guardarJugadores()` recorre el vector y escribe los atributos de cada jugador separados por punto y coma.

## Instrucciones de ejecución

1. Colocar los archivos `main.cpp`, `jugador.h`, `AVL.h`, `sorts.h` y `jugadores.txt` dentro del mismo directorio.
2. Compilar el programa utilizando un compilador compatible con C++.

Ejemplo utilizando g++:

```bash
g++ main.cpp -o nba_stats
```

3. Ejecutar el programa:

```bash
./nba_stats
```

En Windows, se puede ejecutar con:

```bash
nba_stats.exe
```

Es importante mantener `jugadores.txt` en el mismo directorio desde el que se ejecuta el programa para que pueda cargar los registros iniciales.

## Competencias desarrolladas

### SICT0301 - Evalúa los componentes que integran una solución tecnológica y procesos relacionados considerando criterios de calidad y eficiencia.

Se analizaron las complejidades temporales y espaciales de los algoritmos, las estructuras de datos y las funciones auxiliares del programa.

Se documentaron las operaciones de inserción, búsqueda, eliminación y recorrido de los árboles AVL, así como las operaciones del vector y el algoritmo Merge Sort.

También se identificó la complejidad general de las operaciones principales del sistema.

### SICT0302 - Toma decisiones de diseño de software considerando las estructuras de datos y algoritmos más adecuados para resolver un problema.

Se seleccionó un vector como estructura principal para almacenar los jugadores debido a su facilidad de acceso y administración.

Se implementaron ocho árboles AVL para organizar los registros por diferentes atributos y permitir búsquedas eficientes.

Finalmente, se seleccionó Merge Sort como algoritmo de ordenamiento por su complejidad O(n log n) en el mejor, promedio y peor caso.

### Otras funcionalidades desarrolladas

- Consultas de jugadores mediante ocho criterios diferentes.
- Manejo de registros que comparten valores en los atributos.
- Lectura de archivos para recuperar la información al iniciar el programa.
- Escritura de archivos para conservar los cambios realizados.
- Validación de entradas numéricas.
- Presentación organizada de los registros mediante tablas.

## Conclusión

El proyecto integra diferentes estructuras de datos y algoritmos para desarrollar un sistema de administración de estadísticas de jugadores de la NBA.

El uso de un vector permite administrar los registros principales, mientras que los ocho árboles AVL facilitan las consultas por diferentes atributos. Merge Sort permite ordenar la información de manera eficiente y los archivos de texto hacen posible conservar los datos entre ejecuciones.

La combinación de estos componentes permite realizar las operaciones principales del sistema considerando su eficiencia temporal y espacial.

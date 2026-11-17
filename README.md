# Sistema de consulta y administración de estadísticas de jugadores de la NBA

Este proyecto consiste en un programa desarrollado en C++ que permite administrar y consultar información de jugadores de la NBA. Para ello, se utiliza un archivo de texto que contiene los registros de los jugadores y diferentes estructuras de datos y algoritmos para organizar y consultar la información de manera eficiente.

Cada jugador cuenta con los siguientes atributos: nombre, equipo, posición, edad, altura, puntos, rebotes y asistencias.

El programa permite realizar las siguientes operaciones:

- Mostrar los jugadores registrados.
- Ordenar a los jugadores por nombre, equipo, posición, edad, altura, puntos, rebotes o asistencias.
- Consultar jugadores mediante búsquedas.
- Organizar y consultar jugadores utilizando un árbol AVL.
- Agregar y eliminar jugadores de las estructuras correspondientes.
- Guardar y cargar la información mediante archivos de texto.

## SICT0302B: Toma decisiones

### Selecciona y usa una estructura de datos adecuada al problema

Para almacenar y administrar los jugadores utilicé una cola implementada mediante una lista (`QueueList<Jugador>`). Elegí esta estructura porque permite agregar jugadores al final y retirar elementos del inicio de manera eficiente. Además, permite conservar los registros y recorrerlos cuando se necesita mostrar o procesar la información.

Las operaciones principales de la cola son:

- `enqueue`: agrega un jugador al final de la cola.
- `dequeue`: elimina el jugador que se encuentra al inicio.
- `front`: permite consultar el primer jugador.
- `empty`: verifica si la cola está vacía.
- `clear`: elimina todos los elementos.

Estas operaciones se encuentran implementadas en el archivo `queue.h`.

Adicionalmente, utilicé un árbol AVL para organizar a los jugadores de acuerdo con un criterio seleccionado. Elegí esta estructura porque mantiene el árbol balanceado mediante rotaciones, evitando que las operaciones de búsqueda, inserción y eliminación se degraden cuando los datos se encuentran desordenados.

El árbol permite manejar jugadores con valores repetidos mediante un vector dentro de cada nodo, por lo que varios jugadores pueden compartir el mismo valor del criterio seleccionado.

Esta implementación se encuentra en el archivo `AVL.h`.

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente

Para ordenar a los jugadores utilicé el algoritmo Merge Sort. Elegí este algoritmo porque mantiene una complejidad de O(n log n) en el mejor, promedio y peor caso, lo que permite ordenar eficientemente los registros incluso cuando los datos inicialmente se encuentran desordenados.

El algoritmo permite ordenar los jugadores de manera ascendente o descendente utilizando cualquiera de los ocho atributos disponibles:

- Nombre.
- Equipo.
- Posición.
- Edad.
- Altura.
- Puntos.
- Rebotes.
- Asistencias.

La implementación se encuentra en el archivo `sorts.h`, específicamente en las funciones `mergeSort`, `mergeSplit` y `mergeArray`.

## SICT0301B: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa
Los análisis de complejidad se encuentran como comentarios en los códigos.

#### Merge Sort

El programa utiliza Merge Sort para ordenar los jugadores según el criterio seleccionado.

- **Mejor caso:** O(n log n).
- **Caso promedio:** O(n log n).
- **Peor caso:** O(n log n).

La función divide recursivamente el conjunto de jugadores en dos mitades, hasta llegar a elementos individuales. Posteriormente, combina las mitades en orden, comparando los valores de los jugadores.

La división genera O(log n) niveles y en cada nivel se procesan O(n) elementos, por lo que la complejidad total es O(n log n).

La función `mergeArray` tiene una complejidad de O(n), debido a que recorre y combina los elementos de las dos mitades.

### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa

#### Cola de jugadores (QueueList)

La cola se utiliza para almacenar los jugadores que se cargan desde el archivo y permitir su administración dentro del programa.

- **Inserción (`enqueue`): O(1).** Se agrega un elemento al final de la lista.
- **Eliminación (`dequeue`): O(1).** Se elimina el primer elemento.
- **Acceso al primer elemento (`front`): O(1).** Se obtiene directamente el elemento del inicio.
- **Verificar si está vacía (`empty`): O(1).** Se consulta la cantidad de elementos.
- **Vaciar la cola (`clear`): O(n).** Se eliminan todos los elementos.
- **Recorrer la cola: O(n).** Es necesario visitar cada jugador.
- **Convertir la cola a un vector: O(n).** Se recorren los elementos y se copian al vector.

#### Árbol AVL

El árbol AVL se utiliza para organizar a los jugadores según el criterio seleccionado y realizar consultas por sus valores.

- **Inserción (`add`): O(log n).** Se recorre el árbol para encontrar la posición correspondiente y se actualiza el balance mediante rotaciones.
- **Búsqueda (`find`): O(log n).** Se recorren los niveles del árbol hasta encontrar el valor solicitado.
- **Consulta de jugadores (`search`): O(log n + n).** Se busca el nodo correspondiente y posteriormente se recorren los jugadores repetidos almacenados en su vector.
- **Eliminación (`remove`): O(log n + n).** Se localiza el nodo y, cuando existen valores repetidos, se revisan para encontrar el jugador que se desea eliminar.
- **Eliminar todos los nodos (`removeAll`): O(n).** Se recorren y eliminan todos los nodos del árbol.
- **Recorrido inorden (`inorder`): O(n).** Se visitan todos los nodos y sus jugadores repetidos.
- **Recorrido preorden (`preorder`): O(n).** Se visitan todos los nodos y sus jugadores repetidos.
- **Rotaciones: O(1).** Cada rotación realiza una cantidad constante de cambios en los enlaces de los nodos.
- **Actualizar altura y balance: O(1).** Se utilizan los valores almacenados en cada nodo para actualizar su información.

La búsqueda, inserción y eliminación tienen una complejidad de O(log n) para recorrer el árbol, debido a que se mantiene balanceado. Cuando también es necesario recorrer jugadores repetidos, el costo adicional puede ser O(n).

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa

#### Búsqueda binaria

El programa utiliza búsqueda binaria para localizar jugadores dentro de un vector previamente ordenado.

- **Mejor caso:** O(1), cuando el elemento buscado se encuentra en la primera comparación.
- **Caso promedio:** O(log n).
- **Peor caso:** O(log n).

En cada iteración se descarta la mitad de los elementos que todavía pueden contener el valor buscado.

Sin embargo, para realizar esta búsqueda primero se necesita ordenar los jugadores y convertir la cola en un vector. Por lo tanto, considerando todo el proceso:

- Ordenamiento: O(n log n).
- Conversión de cola a vector: O(n).
- Búsqueda binaria: O(log n).

La complejidad total de una consulta que requiere ordenar antes de buscar es O(n log n).

#### Lectura de archivos

La función encargada de cargar los jugadores utiliza `ifstream` para leer el archivo `jugadores.txt`.

- **Lectura del archivo:** O(n), porque se procesa cada registro.
- **Conversión de los datos:** O(1) por jugador, considerando que cada registro contiene una cantidad fija de atributos.
- **Inserción de cada jugador en la cola:** O(1).

Por lo tanto, cargar todos los jugadores tiene una complejidad de O(n).

#### Escritura de archivos

Cuando se guardan los registros de los jugadores en un archivo, es necesario recorrer los elementos que se desean almacenar.

- **Escritura de todos los jugadores:** O(n).

#### Complejidad final del programa

Considerando las operaciones principales del programa:

- Cargar los jugadores: O(n).
- Mostrar todos los jugadores: O(n).
- Ordenar los jugadores: O(n log n).
- Buscar un jugador mediante búsqueda binaria, incluyendo el ordenamiento previo: O(n log n).
- Buscar un valor en el árbol AVL: O(log n), sin considerar los elementos repetidos que deban mostrarse.
- Recorrer todos los jugadores del árbol: O(n).

Por lo tanto, la complejidad temporal de las operaciones principales que requieren ordenar los registros es O(n log n). Las operaciones que solamente recorren o muestran todos los jugadores tienen una complejidad de O(n).

### Presenta casos de prueba correctos y completos para todas las funciones y procedimientos del programa

Los casos de prueba deben comprobar el funcionamiento de las estructuras de datos, los algoritmos y las operaciones principales del programa.

Entre las pruebas se consideran:

**Cola de jugadores**

- Insertar varios jugadores.
- Consultar el primer jugador.
- Eliminar jugadores.
- Comprobar el comportamiento de una cola vacía.
- Vaciar la cola.

**Merge Sort**

- Ordenar jugadores por nombre.
- Ordenar jugadores por equipo.
- Ordenar jugadores por posición.
- Ordenar jugadores por atributos numéricos.
- Comprobar el orden ascendente y descendente.
- Ordenar una colección vacía, con un elemento y con varios elementos.

**Búsqueda binaria**

- Buscar un jugador existente.
- Buscar un jugador inexistente.
- Buscar el primer y último elemento.
- Buscar un elemento cuando solamente existe un registro.

**Árbol AVL**

- Insertar diferentes jugadores.
- Insertar jugadores con valores repetidos.
- Buscar valores existentes e inexistentes.
- Eliminar jugadores.
- Comprobar las eliminaciones cuando existen valores repetidos.
- Comprobar los recorridos inorden y preorden.
- Verificar que el árbol se mantenga balanceado después de inserciones y eliminaciones.

**Archivos**

- Cargar correctamente los registros de `jugadores.txt`.
- Comprobar el comportamiento cuando el archivo no existe.
- Comprobar registros incompletos o con datos inválidos.
- Verificar que los registros se guarden correctamente cuando se modifica la información.

## SICT0303B: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa

El programa cuenta con diferentes mecanismos para consultar la información almacenada.

Se pueden mostrar todos los jugadores registrados y ordenar la información por cualquiera de sus ocho atributos utilizando Merge Sort.

También se puede buscar un jugador mediante búsqueda binaria, después de ordenar los registros según el criterio seleccionado.

Adicionalmente, el árbol AVL permite consultar jugadores por el valor de un atributo, encontrar registros con valores repetidos y mostrar la información mediante recorridos inorden y preorden.

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta

Los jugadores se encuentran registrados en el archivo `jugadores.txt`, desde donde se leen al iniciar el programa.

La función `cargarJugadores` utiliza `ifstream`, `getline` y `stringstream` para separar los datos de cada registro. Posteriormente, convierte los atributos numéricos y crea los objetos `Jugador`, que se insertan en la cola.

También se realizan validaciones para evitar cargar registros incompletos o con datos inválidos.

### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta

El programa utiliza archivos de texto para conservar la información de los jugadores.

El archivo `jugadores.txt` contiene los datos originales que se cargan al iniciar el programa. Por otra parte, `ordenados.txt` se utiliza para almacenar los resultados generados al ordenar los jugadores.

De esta manera, se mantiene separado el conjunto de datos original de los resultados del ordenamiento, evitando modificar los registros originales cada vez que se genera un reporte.

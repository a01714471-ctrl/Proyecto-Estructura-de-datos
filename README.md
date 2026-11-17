# NBA Player Stats

## Descripción

NBA Player Stats es un programa desarrollado en C++ que permite administrar y consultar estadísticas de jugadores de la NBA. El sistema permite visualizar, ordenar, buscar, agregar y eliminar jugadores, manteniendo la información almacenada en archivos de texto.

En este proyecto utilizo diferentes estructuras de datos y algoritmos para organizar la información y facilitar las consultas según los distintos atributos de cada jugador.

## Funcionalidades

El programa cuenta con las siguientes funcionalidades:

- **Mostrar jugadores:** visualiza la información de todos los jugadores registrados.
- **Ordenar jugadores:** permite ordenar los jugadores de acuerdo con cualquiera de sus atributos.
- **Buscar jugadores:** permite consultar jugadores utilizando diferentes criterios de búsqueda.
- **Agregar jugadores:** permite registrar nuevos jugadores y actualizar los índices de búsqueda.
- **Eliminar jugadores:** permite eliminar jugadores registrados a partir de su nombre.
- **Guardar información:** almacena los cambios realizados en el archivo principal.
- **Cargar información:** recupera los jugadores almacenados al iniciar el programa.

## Atributos de los jugadores

Cada jugador contiene los siguientes atributos:

- Nombre.
- Equipo.
- Posición.
- Edad.
- Altura.
- Puntos.
- Rebotes.
- Asistencias.

El programa permite utilizar cualquiera de estos ocho atributos como criterio para ordenar o buscar jugadores.

## Estructura del proyecto

El proyecto está organizado en los siguientes archivos:

- **`main.cpp`:** contiene el menú principal, las operaciones del programa, la administración de los jugadores y la interacción con los archivos.
- **`jugador.h`:** define la clase `Jugador`, sus atributos, constructores, métodos de acceso y representación de la información.
- **`AVL.h`:** implementa los árboles AVL utilizados para organizar y consultar los jugadores.
- **`sorts.h`:** implementa el algoritmo Merge Sort para ordenar los jugadores.
- **`jugadores.txt`:** almacena la información principal de los jugadores.
- **`jugadores_ordenados.txt`:** almacena los resultados de los ordenamientos realizados.

## Estructuras de datos utilizadas

### Vector

Utilizo un `vector<Jugador>` como estructura principal para almacenar todos los jugadores.

Elegí esta estructura porque necesito recorrer constantemente los registros para mostrarlos, utilizarlos como entrada para el algoritmo de ordenamiento y administrar los jugadores. Además, permite acceder directamente a cualquier jugador mediante su índice.

También facilita la visualización de los jugadores y la administración de los registros cuando agrego o elimino elementos.

### Árboles AVL

Utilizo ocho árboles AVL para organizar la información de los jugadores, uno por cada atributo:

1. Nombre.
2. Equipo.
3. Posición.
4. Edad.
5. Altura.
6. Puntos.
7. Rebotes.
8. Asistencias.

Cada árbol permite realizar búsquedas utilizando un atributo específico. De esta manera, puedo consultar la información sin tener que recorrer todos los jugadores de manera secuencial.

Los árboles AVL mantienen su equilibrio mediante rotaciones, lo que permite conservar una altura proporcional al logaritmo del número de elementos.

Cuando existen jugadores con el mismo valor en un atributo, los almaceno en un vector de repetidos dentro del nodo correspondiente. Así, varios jugadores pueden compartir un mismo nodo sin necesidad de crear nodos independientes para cada coincidencia.

### Clase Indices

Utilizo la clase `Indices` para administrar los ocho árboles AVL.

Sus principales operaciones son:

- **add:** inserta un jugador en los ocho índices.
- **remove:** elimina un jugador de los índices correspondientes.
- **search:** realiza una búsqueda en el árbol asociado al criterio seleccionado.

Esto me permite mantener actualizados todos los índices cuando agrego o elimino jugadores y facilita las consultas mediante cualquiera de los ocho atributos.

## Algoritmo de ordenamiento

### Merge Sort

Utilizo Merge Sort para ordenar los jugadores de acuerdo con cualquiera de sus ocho atributos.

El algoritmo divide el vector en partes más pequeñas, ordena cada una de ellas de manera recursiva y posteriormente combina las partes para obtener el resultado ordenado.

Elegí este algoritmo porque ofrece un rendimiento consistente, incluso cuando aumenta la cantidad de jugadores.

Además, puedo ordenar los registros sin modificar el vector original, ya que el resultado se almacena en un nuevo vector y posteriormente se guarda en `jugadores_ordenados.txt`.

## Análisis de complejidad

El análisis de complejidad de los algoritmos de ordenamiento, las estructuras de datos y los demás componentes del programa se encuentra documentado a manera de comentarios dentro de los archivos de código correspondientes.

## Funcionamiento del programa

Al iniciar, el programa carga la información almacenada en `jugadores.txt` y construye los ocho índices AVL para permitir las consultas.

Posteriormente, muestra un menú con las siguientes opciones:

1. Mostrar jugadores.
2. Ordenar jugadores.
3. Buscar jugadores.
4. Agregar jugador.
5. Eliminar jugador.
6. Guardar información.
7. Salir.

Cuando agrego o elimino jugadores, actualizo tanto el vector principal como los ocho árboles AVL, manteniendo la información consistente.

Al seleccionar la opción de ordenar, el programa solicita el atributo que se utilizará como criterio y ejecuta Merge Sort. El resultado se guarda en un archivo independiente, sin modificar el orden de los registros originales.

## Administración de archivos

Utilizo dos archivos de texto para administrar la información.

### jugadores.txt

Es el archivo principal del proyecto. Contiene los registros de todos los jugadores y lo utilizo para cargar la información al iniciar el programa.

Cada registro almacena los ocho atributos separados por punto y coma.

Los cambios que realizo mediante las operaciones de agregar y eliminar se guardan en este archivo al seleccionar la opción correspondiente o al salir del programa.

### jugadores_ordenados.txt

Almacena los resultados de los ordenamientos que realizo.

Este archivo se genera o actualiza cuando utilizo la funcionalidad de ordenamiento. Su contenido no modifica el archivo principal `jugadores.txt`.

## Instrucciones de ejecución

1. Descargar o clonar el repositorio.
2. Abrir el proyecto en un entorno de desarrollo compatible con C++.
3. Verificar que los archivos `.h`, `main.cpp` y `jugadores.txt` se encuentren en la ubicación correspondiente.
4. Compilar el archivo `main.cpp`.
5. Ejecutar el programa.
6. Utilizar el menú para acceder a las diferentes funcionalidades.

## Competencias

### SICT0301: Evalúa los componentes

El análisis de complejidad de los algoritmos de ordenamiento, las estructuras de datos y los demás componentes del programa se encuentra documentado a manera de comentarios dentro de los archivos de código correspondientes.

### SICT0302: Toma decisiones

#### Selecciona y usa una estructura de datos adecuada al problema

Utilizo un vector (`vector<Jugador>`) como estructura principal para almacenar los registros de los jugadores de la NBA. Elegí esta estructura porque necesito recorrer constantemente todos los jugadores para mostrarlos, utilizarlos como entrada para el algoritmo de ordenamiento y administrar los registros. Además, permite acceder directamente a cualquier jugador mediante su índice en O(1). Aunque una lista enlazada permite insertar y eliminar elementos en O(1) cuando se conoce el nodo, el acceso a sus elementos requiere O(n), por lo que resulta menos conveniente para las operaciones principales del proyecto. Implemento el vector en `main.cpp` para almacenar, recorrer, agregar y eliminar jugadores.

También utilizo ocho árboles AVL para organizar y consultar a los jugadores de acuerdo con sus atributos: nombre, equipo, posición, edad, altura, puntos, rebotes y asistencias. Decidí utilizar un árbol independiente para cada atributo porque necesito realizar búsquedas mediante cualquiera de estos criterios. De esta manera, cada consulta se dirige directamente al índice correspondiente, evitando recorrer secuencialmente todos los jugadores.

Elegí árboles AVL en lugar de árboles binarios de búsqueda convencionales porque mantienen automáticamente su equilibrio mediante rotaciones simples y dobles después de las inserciones y eliminaciones. Esto evita que los árboles se degeneren y alcancen una complejidad O(n) en el peor caso, como puede suceder con un BST. En cambio, los AVL garantizan una complejidad O(log n) para localizar los nodos durante las operaciones de búsqueda, inserción y eliminación.

Además, como varios jugadores pueden compartir un mismo valor en atributos como equipo, posición o edad, implementé un vector de repetidos dentro de cada nodo. Así, almaceno juntos a los jugadores que comparten un atributo, evitando crear nodos independientes para cada coincidencia. Esto me permite recuperar todos los jugadores asociados con un mismo valor.

Administro los ocho árboles mediante la clase `Indices`, que se encarga de insertar y eliminar los jugadores en todos los índices y realizar búsquedas en el árbol correspondiente al criterio seleccionado. De esta manera, mantengo sincronizados los índices con el vector principal cuando agrego o elimino jugadores.

La implementación de los árboles se encuentra en `AVL.h`, mientras que su administración se realiza mediante la clase `Indices` en `main.cpp`.

#### Selecciona un algoritmo de ordenamiento adecuado al problema

Utilizo Merge Sort para ordenar los jugadores de acuerdo con cualquiera de sus ocho atributos. Elegí este algoritmo porque necesito ordenar los registros de manera eficiente, incluso cuando aumenta la cantidad de jugadores. Merge Sort tiene una complejidad O(n log n) en el mejor, promedio y peor caso, mientras que algoritmos como Bubble Sort y Selection Sort presentan una complejidad O(n²) en promedio y en el peor caso.

Aunque Merge Sort requiere memoria auxiliar O(n), considero que este costo es aceptable debido a su rendimiento consistente. Además, su implementación me permite ordenar los jugadores sin modificar el vector original, ya que genera un nuevo vector con los resultados. Esto es importante para mi proyecto porque quiero conservar el orden original de los registros y guardar los resultados del ordenamiento en un archivo independiente.

Implementé el algoritmo en `sorts.h`, mediante las funciones `mergeSort`, `mergeSplit` y `mergeArray`. Desde `main.cpp`, puedo seleccionar cualquiera de los ocho atributos como criterio de ordenamiento. El resultado se muestra y se guarda en `jugadores_ordenados.txt`.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa

Implementé mecanismos de consulta que me permiten acceder a la información de los jugadores mediante los ocho árboles AVL. Selecciono el atributo y el valor que deseo buscar, y el programa consulta el índice correspondiente para recuperar los jugadores que coinciden con ese criterio. Esto evita realizar una búsqueda secuencial en el vector principal para cada consulta.

Además, puedo visualizar todos los jugadores registrados y ordenar su información mediante Merge Sort. Estas funcionalidades se encuentran disponibles en las opciones de mostrar, ordenar y buscar del menú principal de `main.cpp`.

#### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa

Los jugadores se encuentran registrados en el archivo `jugadores.txt`, del cual obtengo la información al iniciar el programa. Cada registro contiene los ocho atributos de un jugador separados por punto y coma.

Implementé funciones para leer cada línea, separar sus atributos y convertirlos a los tipos de datos correspondientes para construir objetos `Jugador`. Posteriormente, agrego cada registro al vector principal y lo inserto en los ocho árboles AVL mediante la clase `Indices`. Esto me permite reconstruir las estructuras de datos automáticamente cada vez que ejecuto el programa.

Este mecanismo se implementa mediante las funciones `cargarJugadores` y `convertirJugador` en `main.cpp`.

#### Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa

Implementé mecanismos para conservar los cambios que realizo durante la ejecución del programa. Cuando agrego o elimino jugadores, las modificaciones se reflejan en el vector principal y en los ocho árboles AVL. Al seleccionar la opción de guardar o salir del programa, la información actualizada se escribe en `jugadores.txt`, evitando que los cambios se pierdan al finalizar la ejecución.

También implementé la escritura de los resultados de ordenamiento en `jugadores_ordenados.txt`. Esto me permite conservar los resultados sin modificar el archivo principal ni alterar el orden original de los jugadores.

Estos mecanismos se implementan mediante la función `guardarJugadores` y las funciones encargadas de guardar los resultados ordenados en `main.cpp`.

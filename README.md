# Sistema de consulta y organización de estadísticas de jugadores de la NBA

## Descripción del avance 1

En el primer avance se desarrolló un programa para consultar y organizar información de jugadores de la NBA. Se creó la clase `Jugador` para almacenar diferentes atributos de cada jugador, como:

- Nombre
- Equipo
- Posición
- Edad
- Altura
- Puntos
- Rebotes
- Asistencias

La información se almacenaba en un `vector<Jugador>`. El programa permitía mostrar los datos y ordenarlos utilizando diferentes atributos.

Para realizar el ordenamiento se implementó el algoritmo **Merge Sort**, mediante una clase `Sorts<T>`. El algoritmo permite ordenar a los jugadores por cualquiera de los ocho atributos disponibles.

El programa se dividió en archivos para mantener una estructura modular:

- `main.cpp`: contiene el menú principal, los datos de los jugadores y la interacción con el usuario.
- `jugador.h`: contiene la clase `Jugador`, sus atributos, constructores, getters y el método `toString()`.
- `sorts.h`: contiene la implementación de Merge Sort y la lógica para ordenar a los jugadores según el criterio seleccionado.

## Descripción del avance 2

En el segundo avance se agregaron nuevas funcionalidades para mejorar la organización y consulta de la información.

Se implementaron las estructuras de datos `QueueList` y `QueueVector`, así como los algoritmos de búsqueda binaria iterativa y recursiva. También se integró un menú que permite mostrar, ordenar y buscar jugadores según sus diferentes atributos.

Los datos de los jugadores se encuentran definidos directamente en `main.cpp`. El programa utiliza principalmente `QueueList` para administrar los registros y convierte los datos a un vector cuando necesita realizar operaciones de ordenamiento o búsqueda.

### Cambios sobre el primer avance

- Se agregaron las estructuras de datos `QueueList` y `QueueVector`.
- Se implementaron la búsqueda binaria iterativa y la recursiva.
- Se agregó una opción para buscar jugadores por sus atributos.
- Se integraron las funcionalidades de ordenamiento y búsqueda en el menú principal.
- Se documentó el análisis de complejidad directamente en el código.

## Estructura de archivos

- `main.cpp`: contiene el menú principal, los datos de los jugadores y la interacción con el usuario.
- `jugador.h`: contiene la clase `Jugador` y los métodos para consultar y mostrar sus atributos.
- `sorts.h`: contiene la implementación de Merge Sort.
- `queue.h`: contiene las clases `Queue`, `QueueList` y `QueueVector`.
- `busquedas.h`: contiene los algoritmos de búsqueda binaria iterativa y recursiva.

## Instrucciones para compilar el avance de proyecto

Se necesita un compilador de C++ compatible con C++11.

Desde la terminal, dentro de la carpeta del proyecto, ejecutar:

    g++ main.cpp -std=c++11 -o segundo_avance

## Instrucciones para ejecutar el avance de proyecto

Después de compilar, ejecutar el programa con el siguiente comando.

**Linux o macOS:**

    ./segundo_avance

**Windows:**

    segundo_avance.exe

## ¿Cómo usar el programa?

Al ejecutar el programa se muestra el menú principal:

    ESTADISTICAS DE JUGADORES NBA
    1. Mostrar jugadores
    2. Ordenar jugadores
    3. Buscar jugador
    4. Salir

### 1. Mostrar jugadores

Muestra los jugadores registrados junto con sus estadísticas.

### 2. Ordenar jugadores

Permite ordenar a los jugadores utilizando uno de los siguientes criterios:

    Ordenar jugadores por:
    1. Nombre
    2. Equipo
    3. Posicion
    4. Edad
    5. Altura
    6. Puntos
    7. Rebotes
    8. Asistencias

Se debe seleccionar un número del 1 al 8. El programa utiliza Merge Sort para ordenar a los jugadores según el atributo seleccionado y posteriormente muestra los datos ordenados.

### 3. Buscar jugador

Permite buscar un jugador utilizando uno de los atributos disponibles. Para realizar la búsqueda se utilizan los algoritmos de búsqueda binaria iterativa y recursiva, después de ordenar los datos según el criterio seleccionado.

### 4. Salir

Termina la ejecución del programa.

Si se introduce una opción que no corresponde con el menú, el programa muestra un mensaje indicando que la opción no es válida.

## Descripción de las entradas del avance de proyecto

El programa utiliza diez registros de jugadores de la NBA definidos directamente en `main.cpp`.

Las entradas del usuario corresponden a las opciones del menú, el criterio de ordenamiento o búsqueda y el valor que desea buscar.

## Descripción de las salidas del avance de proyecto

El programa muestra la información de los jugadores registrados, permite visualizar los datos ordenados según el criterio seleccionado y muestra los resultados de las búsquedas realizadas.

También presenta mensajes para orientar al usuario durante la ejecución y permite salir desde el menú principal.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes

#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

El análisis de complejidad de los algoritmos de ordenamiento se encuentra documentado directamente en el código.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

El análisis de complejidad de las estructuras de datos y sus operaciones se encuentra documentado directamente en el código.

### SICT0302: Toma decisiones

#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

Se seleccionó **Merge Sort** porque permite ordenar a los jugadores según diferentes atributos y mantiene una complejidad temporal de `O(n log n)` en el mejor caso, el caso promedio y el peor caso.

También se consideraron algoritmos como Bubble Sort, Selection Sort e Insertion Sort. Merge Sort se eligió por su eficiencia cuando aumenta la cantidad de datos y porque permite reutilizar la misma lógica para ordenar los ocho atributos de los jugadores.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

Para este proyecto se implementaron las estructuras de datos `QueueList` y `QueueVector`, considerando la necesidad de almacenar y organizar la información de los jugadores de la NBA.

`QueueList` utiliza una lista enlazada para almacenar los registros, mientras que `QueueVector` utiliza un vector. Ambas estructuras permiten administrar los datos de los jugadores, aunque presentan diferencias en la forma de acceder a sus elementos y en el costo de sus operaciones.

Se eligieron estas estructuras para trabajar con los registros y facilitar la integración de los algoritmos de ordenamiento y búsqueda. En el programa principal se utiliza principalmente `QueueList`, cuyos elementos se convierten a un vector cuando es necesario realizar estas operaciones.

Desde el punto de vista de la complejidad, el acceso a un elemento por posición en un vector es O(1), mientras que recorrer una lista enlazada hasta una posición determinada puede requerir O(n). Por otro lado, insertar o eliminar elementos al inicio de una lista enlazada puede realizarse en O(1), mientras que estas operaciones en un vector pueden requerir desplazar elementos.

Además, Merge Sort tiene una complejidad temporal de O(n log n), independientemente del orden inicial de los datos. La búsqueda binaria también tiene una complejidad de O(log n), siempre que los datos estén ordenados y se pueda acceder eficientemente a los elementos por posición. Por esta razón, el programa utiliza un vector para realizar las operaciones de ordenamiento y búsqueda.

La elección de estas estructuras permite organizar los registros y utilizar los algoritmos implementados de acuerdo con las necesidades del programa. El análisis de complejidad de las estructuras y sus operaciones se encuentra documentado directamente en el código.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctos.

Se implementaron mecanismos para consultar y organizar la información de los jugadores de la NBA mediante las estructuras de datos `QueueList` y `QueueVector`.

El programa permite mostrar todos los jugadores registrados y sus estadísticas, así como ordenar la información utilizando Merge Sort según cualquiera de los ocho atributos disponibles: nombre, equipo, posición, edad, altura, puntos, rebotes y asistencias.

También se implementaron dos métodos de búsqueda binaria: uno iterativo (`bs_seq`) y otro recursivo (`bs_rec`). Estos permiten localizar jugadores a partir del atributo seleccionado por el usuario. Antes de realizar la búsqueda, los datos se ordenan de acuerdo con el criterio correspondiente, ya que la búsqueda binaria requiere que los elementos estén ordenados.

Con estas funcionalidades, el usuario puede consultar la información de manera organizada y encontrar jugadores sin tener que revisar manualmente todos los registros.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

Actualmente, los datos de los jugadores se encuentran definidos directamente en `main.cpp` y se cargan al iniciar el programa. Posteriormente, se almacenan en la estructura de datos utilizada para administrar la información.

Aunque todavía no se implementa la lectura de archivos externos, el programa cuenta con una estructura modular que permitiría agregar esta funcionalidad en futuras versiones. Por ejemplo, se podría utilizar un archivo CSV para registrar los datos de los jugadores y leerlos mediante `ifstream`, facilitando la incorporación de nuevos registros sin modificar directamente el código fuente.

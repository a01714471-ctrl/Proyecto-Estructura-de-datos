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

Para realizar el ordenamiento se implementó el algoritmo **Merge Sort**, mediante una clase `Sorts<T>`. Este algoritmo permite ordenar a los jugadores por cualquiera de los ocho atributos disponibles.

El programa se dividió en archivos para mantener una estructura modular:

- `main.cpp`: contiene el menú principal y la interacción con el usuario.
- `jugador.h`: contiene la clase `Jugador`, sus atributos, constructores, getters y el método `toString()`.
- `sorts.h`: contiene la implementación de Merge Sort y la lógica para ordenar a los jugadores según el criterio seleccionado.

## Descripción del avance 2

En el segundo avance se agregaron nuevas funcionalidades para mejorar la organización y consulta de la información.

Se implementaron las estructuras de datos `QueueList` y `QueueVector`, así como los algoritmos de búsqueda binaria iterativa y recursiva. También se integró un menú que permite mostrar, ordenar y buscar jugadores según sus diferentes atributos.

El programa utiliza principalmente `QueueList` para administrar los registros y convierte los datos a un vector cuando necesita realizar operaciones de ordenamiento o búsqueda.

Además, se incorporó la lectura de datos desde un archivo de texto externo, lo que permite separar la información de los jugadores del código fuente y facilita la actualización de los registros.

### Cambios sobre el primer avance

- Se agregaron las estructuras de datos `QueueList` y `QueueVector`.
- Se implementaron los algoritmos de búsqueda binaria iterativa y recursiva.
- Se agregó una opción para buscar jugadores por sus atributos.
- Se integraron las funcionalidades de ordenamiento y búsqueda en el menú principal.
- Se documentó el análisis de complejidad directamente en el código.
- Se implementó la lectura de jugadores desde el archivo `jugadores.txt`.
- Se agregó la validación de los registros leídos para identificar problemas de formato.
- Se eliminó la necesidad de registrar manualmente cada jugador dentro de `main.cpp`.
  
Descripción de los archivos:

- `main.cpp`: contiene el menú principal, las funciones para mostrar los jugadores y la interacción con el usuario. También inicia la carga de los datos desde el archivo de texto.
- `jugador.h`: contiene la clase `Jugador` y los métodos para consultar y mostrar sus atributos.
- `sorts.h`: contiene la implementación de Merge Sort.
- `queue.h`: contiene las clases `Queue`, `QueueList` y `QueueVector`.
- `busquedas.h`: contiene los algoritmos de búsqueda binaria iterativa y recursiva.
- `jugadores.txt`: contiene los registros de los jugadores y sus estadísticas.

## Lectura de datos desde un archivo de texto

Para facilitar la administración de la información, se implementó la función `cargarJugadores()`, que obtiene los datos de los jugadores desde `jugadores.txt`.

Esta función utiliza las herramientas de manejo de archivos de C++, abre el archivo, lee cada línea y separa sus campos. Posteriormente, convierte los valores numéricos a sus tipos correspondientes, crea los objetos `Jugador` y los agrega a la cola mediante `enqueue()`.

De esta manera, los datos se cargan automáticamente al iniciar el programa, sin necesidad de escribir cada registro directamente en `main.cpp`.

### Formato de los registros

El archivo debe contener un jugador por línea. Los campos se separan mediante punto y coma (`;`) y deben aparecer en el siguiente orden:

`Nombre;Equipo;Posición;Edad;Altura;Puntos;Rebotes;Asistencias`

Los registros deben contener los ocho campos requeridos y respetar el orden establecido. La función de carga verifica el formato y utiliza los valores leídos para construir cada objeto.

Si el archivo no se puede abrir o se encuentra un registro con un formato inválido, el programa informa del problema y no continúa con la ejecución normal.

Una ventaja de esta implementación es que se pueden agregar, eliminar o modificar jugadores directamente en `jugadores.txt`, sin tener que modificar el código de `main.cpp`.

## Instrucciones para compilar el proyecto

Se necesita un compilador de C++ compatible con C++11.

Desde una terminal, dentro de la carpeta del proyecto, ejecutar:

    g++ main.cpp -std=c++11 -o segundo_avance

## Instrucciones para ejecutar el proyecto

Después de compilar, ejecutar el programa con el siguiente comando.

**Linux o macOS:**

    ./segundo_avance

**Windows:**

    segundo_avance.exe

Es importante que `jugadores.txt` se encuentre en el directorio de trabajo desde el cual se ejecuta el programa, ya que se utiliza ese nombre para abrir el archivo.

## ¿Cómo usar el programa?

Al ejecutar el programa se muestra el menú principal:

    ===== ESTADISTICAS DE JUGADORES DE LA NBA =====
    1. Mostrar jugadores
    2. Ordenar jugadores
    3. Buscar jugador
    4. Salir

### 1. Mostrar jugadores

Muestra los jugadores cargados desde `jugadores.txt`, junto con sus estadísticas.

### 2. Ordenar jugadores

Permite ordenar a los jugadores utilizando uno de los siguientes criterios:

    Ordenar por:
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

Permite buscar un jugador utilizando uno de los ocho atributos disponibles.

El usuario selecciona el criterio e introduce el valor que desea buscar. Antes de realizar la búsqueda, el programa ordena los datos según el criterio seleccionado y los convierte a un vector.

La búsqueda binaria recursiva, implementada mediante `bs_rec()`, permite localizar el registro correspondiente. Si se encuentra una coincidencia, se muestran los datos del jugador; de lo contrario, se informa que no se encontró un registro con ese valor.

### 4. Salir

Termina la ejecución del programa.

Si se introduce una opción que no corresponde con el menú, el programa muestra un mensaje indicando que la opción no es válida.

## Descripción de las entradas del proyecto

El programa utiliza las siguientes entradas:

- **Archivo `jugadores.txt`:** contiene los registros de los jugadores, separados por punto y coma.
- **Opción del menú:** permite seleccionar la operación que se desea realizar.
- **Criterio de ordenamiento:** determina el atributo por el cual se ordenan los jugadores.
- **Criterio y valor de búsqueda:** permiten especificar el atributo y el dato que se desea localizar.

La cantidad de jugadores no está limitada a los diez registros del ejemplo; es posible agregar más líneas al archivo, siempre que respeten el formato establecido.

## Descripción de las salidas del proyecto

El programa puede producir las siguientes salidas:

- Una tabla con los jugadores y sus estadísticas.
- Una tabla con los jugadores ordenados según el criterio seleccionado.
- Los datos del jugador encontrado durante una búsqueda.
- Mensajes que indican cuando no se encuentra un jugador.
- Mensajes de validación para opciones incorrectas o problemas al cargar el archivo.
- Un mensaje de salida al terminar la ejecución.

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

Se implementaron las estructuras `QueueList` y `QueueVector` para almacenar y administrar la información de los jugadores de la NBA.

El programa utiliza principalmente `QueueList` y convierte sus datos a un vector para realizar las operaciones de ordenamiento y búsqueda.

Se consideraron las diferencias de complejidad entre ambas estructuras: el acceso por posición en un vector es `O(1)`, mientras que localizar un elemento por posición en una lista enlazada requiere, en general, `O(n)`. Por ello, se utiliza un vector para facilitar el acceso a los elementos durante las operaciones de ordenamiento y búsqueda binaria.

El análisis de complejidad de las estructuras de datos y sus operaciones se encuentra documentado directamente en el código.

### SICT0303: Implementa acciones científicas

#### Implementa mecanismos para consultar información de las estructuras correctamente.

Se implementaron mecanismos para consultar y organizar la información de los jugadores de la NBA mediante las estructuras de datos `QueueList` y `QueueVector`.

El programa permite mostrar todos los jugadores registrados y sus estadísticas, así como ordenar la información utilizando Merge Sort según cualquiera de los ocho atributos disponibles: nombre, equipo, posición, edad, altura, puntos, rebotes y asistencias.

También se implementaron los algoritmos de búsqueda binaria iterativa y recursiva. En el menú actual se utiliza la búsqueda binaria recursiva mediante `bs_rec()`. Antes de realizar la búsqueda, los datos se ordenan de acuerdo con el criterio correspondiente, ya que la búsqueda binaria requiere que los elementos estén ordenados.

Con estas funcionalidades, el usuario puede consultar la información de manera organizada y encontrar jugadores sin tener que revisar manualmente todos los registros.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

Se implementó la función `cargarJugadores()` para leer los datos de los jugadores desde un archivo externo llamado `jugadores.txt`.

La función utiliza el manejo de archivos de C++ para abrir el archivo, leer cada registro, separar los campos mediante punto y coma y convertir los valores numéricos a sus tipos correspondientes. Después, crea los objetos `Jugador` y los almacena en `QueueList`.

También se contempla la validación del formato de los registros y la detección de errores durante la apertura del archivo.

Esta implementación permite administrar los datos de forma independiente al código fuente, facilita la actualización de los registros y evita modificar `main.cpp` cada vez que se desea agregar o cambiar un jugador.

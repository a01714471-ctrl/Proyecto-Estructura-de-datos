# Sistema de consulta y organización de estadísticas de jugadores de la NBA

## Descripción del avance

Este proyecto consiste en un programa para consultar y organizar información de jugadores de la NBA.

El programa almacena información de diferentes jugadores, incluyendo:

- Nombre
- Equipo
- Posición
- Edad
- Altura
- Puntos por partido
- Rebotes por partido
- Asistencias por partido

En este avance, el programa permite mostrar la información de los jugadores y organizarla utilizando diferentes atributos. Para realizar los ordenamientos se implementó el algoritmo **Merge Sort**, utilizando la misma lógica para ordenar los datos de acuerdo con el criterio seleccionado por el usuario.

Los criterios disponibles para ordenar son:

1. Nombre
2. Equipo
3. Posición
4. Edad
5. Altura
6. Puntos
7. Rebotes
8. Asistencias

El programa está dividido en diferentes archivos para mantener la modularidad. La clase `Jugador` se encuentra en `jugador.h`, mientras que la implementación de **Merge Sort** se encuentra en `sorts.h`.

---

## ¿Cómo usar el programa?

Al iniciar el programa se muestra un menú con las siguientes opciones:

```text
===== ESTADISTICAS DE JUGADORES NBA =====
1. Mostrar jugadores
2. Ordenar jugadores
3. Salir




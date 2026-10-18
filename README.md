# Práctica 1: Playlist de música

Programación Orientada a Objetos · Ingeniería Mecatrónica · Tercer semestre

Llena cada espacio conforme avances en las fases de [PRACTICA.md](PRACTICA.md).

## Fase 1. Entender el problema

**1.1 El problema con mis propias palabras**
El sistema consiste en una aplicación para administrar una biblioteca de audio que organiza pistas (divididas en canciones y podcasts) dentro de listas de reproducción o playlists. Cada pista cuenta con un título y una duración. Las canciones incluyen información de artista y género, mientras que los podcasts incluyen anfitrión y número de episodio. Las playlists agrupan pistas existentes mediante referencias (sin adueñarse de ellas) y permiten calcular la duración total acumulada y mostrar su contenido de forma estructurada.

**1.2 Sustantivos (posibles clases) y verbos (posibles métodos)**

Sustantivos: Playlist, Pista, Cancion, Podcast, Duracion, Artista, Genero, Anfitrion

Verbos: agregarCancion, agregarPodcast, cantidadPistas, duracionTotal, mostrar, mostrarInfo, totalSegundos, imprimir, setTitulo.

**1.3 Relaciones** (completa con "es un", "tiene un" o "usa un")

*   Una canción es un pista.
*   Un podcast es un pista.
*   Una pista tiene un duración.
*   Una playlist usa un canción.

## Fase 2. Diseñar la solución

**2.1 Diagrama de clases**

![Diagrama de clases](diseno_solucion.png)

**2.2 Justificación de cada relación**

| Relación | Tipo | ¿Por qué? |
| --- | --- | --- |
| Cancion - Pista | _____ | _____ |
| Podcast - Pista | _____ | _____ |
| Pista - Duracion | _____ | _____ |
| Playlist - Cancion | _____ | _____ |
| Playlist - Podcast | _____ | _____ |

## Fase 3. Implementar

**3.1 Bitácora de dudas**

| # | Duda | Cómo la resolví | Fuente |
| --- | --- | --- | --- |
| 1 | _____ | _____ | _____ |
| 2 | _____ | _____ | _____ |
| 3 | _____ | _____ | _____ |

**3.2 Experimentos guiados**

Experimento 1, orden de construcción y destrucción: Los constructores se ejecutan de la base a la derivada (Duracion -> Pista -> Cancion), y los destructores se ejecutan en orden inverso (de la derivada a la base).

Experimento 2, ¿quién es dueño de quién?: Al destruir la playlist al salir de su ámbito de bloque, la canción creada en main sigue existiendo intacta porque la playlist solo guarda punteros y no libera memoria de objetos externos (agregación).

Experimento 3, un objeto en dos playlists: Al modificar el título de una canción original mediante setTitulo(), el cambio se refleja de inmediato al mostrar ambas playlists, comprobando que almacenan referencias al mismo objeto en memoria y no copias independientes.

## Fase 4. Probar y mejorar

**4.1 Tabla de pruebas**

| # | Caso | Resultado esperado | Resultado obtenido | ¿Pasa? |
| --- | --- | --- | --- | --- |
| 1 | Duración normal `Duracion(3, 45)` | 3:45 | _____ | _____ |
| 2 | Segundos mayores a 59 `Duracion(0, 75)` | 1:15 | _____ | _____ |
| 3 | Valores negativos `Duracion(-2, 10)` | 0:00 | _____ | _____ |
| 4 | Título vacío | "Sin título" | _____ | _____ |
| 5 | Playlist vacía | 0:00 y 0 pistas | _____ | _____ |
| 6 | Canción duplicada | La segunda vez devuelve `false` | _____ | _____ |
| 7 | Puntero nulo | Devuelve `false` | _____ | _____ |
| 8 | Total con 2 canciones y 1 podcast | Suma correcta en m:ss | _____ | _____ |

**4.2 Bitácora de mejoras**

| # | Falla o mejora detectada | Qué cambié | Por qué |
| --- | --- | --- | --- |
| 1 | _____ | _____ | _____ |
| 2 | _____ | _____ | _____ |

Retos opcionales que intenté: _____

## Fase 5. Publicar en GitHub

**5.1 Enlace a mi fork**

[Inserta aquí el enlace a tu fork]

## Cierre y reflexión

**6.1 ¿Qué aprendiste en esta práctica?**

Aprendí a aplicar y distinguir de forma práctica los tres pilares de relación entre clases en C++ (herencia, composición y agregación). También comprendí la importancia de utilizar listas de inicialización en constructores de clases derivadas, así como el manejo seguro de vectores con punteros para evitar duplicados y gestionar referencias compartidas.

**6.2 ¿Qué cambiarías de tu proceso la próxima vez?**

Definir con mayor anticipación las validaciones de datos limítrofes (como valores negativos o punteros nulos) antes de escribir la lógica principal, lo que facilitaría una depuración más rápida desde las primeras pruebas unitarias en el archivo main.cpp.
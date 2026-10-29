# Shadow Escape

Juego de aventura textual en C: un espía debe recorrer una casa y sus alrededores,
conseguir un sobre con información y escapar antes de que se agote el tiempo. El
jugador explora espacios conectados, recoge y utiliza objetos, administra su salud y
se enfrenta a un enemigo.

El proyecto fue desarrollado como práctica de programación en C. La interfaz se
representa en la terminal mediante mapas ASCII.

## Requisitos

- GCC o un compilador compatible con las opciones de C del proyecto.
- GNU Make.
- La biblioteca estática `lib/libscreen.a`, incluida en el repositorio y enlazada
  por el Makefile.
- Valgrind, solo para ejecutar las pruebas con comprobación de memoria.
- Doxygen, solo para regenerar la documentación técnica.

La biblioteca `libscreen.a` es un archivo precompilado; la compilación presupone
un entorno compatible con el formato y la arquitectura de esa biblioteca.

## Compilar y jugar

Desde la raíz del proyecto:

```sh
make
```

Esto compila el juego y los ejecutables de prueba. Para iniciar una partida con el
mapa incluido:

```sh
./bin/game data/nuevo.dat
```

También se puede usar el objetivo `make run`. Para guardar en un archivo el
resultado de los comandos de la partida:

```sh
./bin/game data/nuevo.dat -l partida.log
```

El programa espera un archivo de datos como primer argumento. La opción `-l`
debe ir seguida del nombre del archivo de registro.

## Comandos

Los comandos no distinguen entre mayúsculas y minúsculas. Se pueden usar sus
formas largas o las abreviaturas indicadas:

| Acción | Comando |
|---|---|
| Salir | `exit` (`e`) |
| Recoger / dejar un objeto | `take <objeto>` (`t`) / `drop <objeto>` (`d`) |
| Atacar / disparar / apuñalar | `attack` (`a`) / `shoot` (`sh`) / `stab` (`st`) |
| Desplazarse | `move <dirección>` (`m`); direcciones: `north`, `south`, `east`, `west`, `up`, `down` o `n`, `s`, `e`, `w`, `u`, `d` |
| Inspeccionar | `inspect <objeto|space>` (`i`) |
| Encender / apagar | `turnon <objeto>` (`ton`) / `turnoff <objeto>` (`toff`) |
| Abrir un enlace con un objeto | `open <enlace> with <objeto>` (`o`) |
| Guardar / cargar | `save <archivo>` (`s`) / `load <archivo>` (`ld`) |

Ejemplos:

```text
inspect s
take backpack
move north
open door with house_keys
```

La guía de usuario original está en [`docs/guia-usuario.pdf`](docs/guia-usuario.pdf).
El archivo [`docs/recorrido-final.txt`](docs/recorrido-final.txt) contiene una
secuencia de comandos de ejemplo; puede revelar partes del recorrido.

## Pruebas

`make test` compila los ejecutables de prueba. Para ejecutarlos todos:

```sh
./scripts/run_tests.sh 0
```

Para ejecutar un módulo concreto, por ejemplo:

```sh
./scripts/run_tests.sh 0 command_test
```

El primer argumento `1` ejecuta las pruebas con Valgrind, que debe estar
instalado:

```sh
./scripts/run_tests.sh 1
```

Los ejecutables muestran el porcentaje y el resultado de cada prueba. Las
pruebas están organizadas por módulos del juego (espacios, enlaces, objetos,
inventario, jugador, comandos y gestión de partida, entre otros).

El script devuelve un código distinto de cero si falla alguna prueba o si no se
pudo compilar un ejecutable.

## Estructura

```text
.
├── data/       # Mapa y datos de partida de ejemplo
├── bin/        # Ejecutables generados por Make
├── docs/       # Guía de usuario y recorrido de ejemplo
├── include/    # Interfaces y tipos compartidos
├── lib/        # Biblioteca estática libscreen
├── obj/        # Archivos objeto generados al compilar
├── scripts/    # Ayudas para ejecutar pruebas
├── src/        # Implementación y pruebas en C
├── doc/        # Salida generada por Doxygen (HTML y LaTeX)
├── Makefile
└── Doxyfile
```

El código está dividido en módulos para el estado y las reglas del juego, el
jugador, los espacios y enlaces, los objetos y el inventario, los comandos, la
gestión de datos y la representación gráfica en terminal.

El mapa de ejemplo es un archivo de texto delimitado por registros etiquetados:
`#p:` (jugador), `#e:` (enemigo), `#s:` (espacios), `#o:` (objetos), `#l:`
(enlaces) y `#d:` (diálogos). Se puede proporcionar otro archivo con el mismo
formato al iniciar el juego.

## Documentación técnica

Con Doxygen instalado, genera la documentación técnica con:

```sh
make Doxygen
```

La salida HTML queda en `doc/html/`. Estos archivos generados se ignoran en Git;
se pueden regenerar a partir de `Doxyfile`, `src/` e `include/`.

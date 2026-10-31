*Este proyecto ha sido creado como parte del currículo de 42 por pabbenit, dbustama.*

# Push_swap

## Descripción

**Push_swap** es un proyecto de la Escuela 42 cuyo objetivo es ordenar una secuencia de enteros en orden ascendente utilizando exclusivamente dos pilas (`a` y `b`) y un conjunto limitado de operaciones. Al comenzar, `a` contiene los números en el orden recibido por argumentos y `b` está vacía. El primer número representa la cima de `a`.

El programa **`push_swap`** analiza la entrada, selecciona una estrategia de ordenación y escribe en la salida estándar (`stdout`) las instrucciones necesarias para ordenar `a`. El objetivo no consiste únicamente en obtener un orden correcto: también se busca reducir el número de instrucciones emitidas.

Se han integrado cuatro modos seleccionables: **simple**, **intermedio**, **complejo** y **adaptativo** (por defecto). El proyecto incluye un modo de estadísticas `--bench` y un programa adicional **`checker`** como parte bonus.

## Instrucciones

### Compilación

Desde la raíz del repositorio:

```bash
make            # Compila push_swap y la Libft necesaria
make bonus      # Compila checker
make clean      # Elimina los archivos objeto
make fclean     # Elimina objetos, ejecutables y la biblioteca compilada
make re         # Reconstruye push_swap desde cero
```

Se utiliza `cc` con `-Wall -Wextra -Werror`. El Makefile enlaza con la biblioteca propia situada en `libft/`.

### Ejecución de push_swap

```bash
./push_swap 3 2 1
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1
./push_swap "3 -2 10 5"
```

| Opción | Comportamiento |
| --- | --- |
| Sin selector | Utiliza el modo adaptativo. |
| `--simple` | Fuerza la extracción sucesiva del mínimo. |
| `--medium` | Fuerza el algoritmo basado en bloques o *chunks*. |
| `--complex` | Fuerza el algoritmo radix binario LSD (Leas Significant Digit). |
| `--adaptive` | Selecciona una de las estrategias según el desorden inicial. |
| `--bench` | Añade estadísticas por `stderr` sin sustituir las instrucciones de `stdout`. |

Las instrucciones se imprimen una por línea. Una entrada que ya esté ordenada no necesita operaciones. Sin argumentos, el programa debe terminar sin mostrar nada; ante una entrada no válida, escribe `Error\n` por `stderr`.

### Modo benchmark

```bash
./push_swap --bench 3 2 1

# Guardar las estadísticas y enviar las operaciones al checker:
ARG="3 2 1"
./push_swap --bench $ARG 2> bench.txt | ./checker $ARG

# Contar exclusivamente las instrucciones:
./push_swap --complex $ARG | wc -l
```

El benchmark informa del índice de desorden, la estrategia ejecutada, la complejidad que identifica el programa, el total de instrucciones y el desglose por las 11 operaciones. Las estadísticas se envían a **`stderr`** y las operaciones a **`stdout`**; esta separación permite usar tuberías sin mezclar ambos contenidos.

### Bonus: checker

Compilar primero con `make bonus`. El checker recibe los mismos números iniciales que Push_swap y lee las instrucciones por la entrada estándar (`stdin`):

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG

printf 'sa\nrra\n' | ./checker 3 2 1
printf 'pb\n' | ./checker 1 2 3
printf 'instruccion_invalida\n' | ./checker 3 2 1
```

El checker usa `get_next_line()` para leer instrucciones completas y las aplica sobre sus dos pilas. Tras llegar al final de la entrada, escribe `OK\n` si **`a` está ordenada y `b` vacía**, o `KO\n` en caso contrario. Si una instrucción o un argumento es inválido, escribe `Error\n` en `stderr`. Sin argumentos, finaliza silenciosamente.

## Operaciones permitidas

| Operación | Significado |
| --- | --- |
| `sa`, `sb` | Intercambian los dos primeros elementos de `a` o `b`. |
| `ss` | Aplica los intercambios de ambas pilas. |
| `pa` | Envía el primer elemento de `b` a la cima de `a`. |
| `pb` | Envía el primer elemento de `a` a la cima de `b`. |
| `ra`, `rb` | Rotan la pila hacia arriba: el primer elemento pasa al final. |
| `rr` | Aplica ambas rotaciones hacia arriba. |
| `rra`, `rrb` | Rotan la pila hacia abajo: el último elemento pasa al principio. |
| `rrr` | Aplica ambas rotaciones hacia abajo. |

Las instrucciones combinadas (`ss`, `rr`, `rrr`) cuentan como **una** instrucción emitida, aunque afecten a las dos pilas.

## Diseño y decisiones técnicas

### Representación de las pilas

Se utilizan listas doblemente enlazadas (`t_node`), con punteros al primer y último nodo (`head`, `tail`) y un contador `size` en cada `t_stack`. Una estructura `t_data` centraliza las dos pilas, el selector de algoritmo, los indicadores de benchmark/checker, el índice de desorden y los contadores de operaciones.

Los números se validan antes de crear los nodos. La liberación de los nodos y de las estructuras se centraliza mediante funciones de limpieza, mientras que el procesamiento de argumentos administra sus reservas temporales.

### Indexación de valores

Antes de ordenar, se asigna a cada nodo un índice `n_index`, correspondiente a la posición que ocupa su valor en la secuencia ordenada: índices de `0` a `n - 1`.

Esta normalización permite trabajar con números negativos o grandes sin cambiar la lógica del radix binario. Por ejemplo, los valores `[-10, 50, 3]` se corresponden con los índices `[0, 2, 1]`.

### Índice de desorden

El desorden se mide **antes de efectuar movimientos** mediante la proporción de pares invertidos:

$$
D = \frac{I}{\frac{n(n-1)}{2}}
$$

Donde `I` es el número de pares de posiciones `(i, j)` tales que `i < j` y `a[i] > a[j]`, y `n` es el número de elementos. Para `n < 2` se toma `D = 0`.

- `D = 0`: entrada ordenada.
- `D = 1`: entrada en orden estrictamente descendente.
- `0 < D < 1`: desorden parcial.

El cálculo de pares invertidos requiere **O(n²) comparaciones en C** y **O(1) memoria auxiliar**, sin contar el array temporal utilizado por el programa para representar los valores.

## Algoritmos seleccionados y justificación

**Importante:** en este proyecto distinguimos entre el número de **instrucciones de Push_swap emitidas** y el tiempo interno de ejecución en C. Las cotas de operaciones que exige el enunciado se refieren a las instrucciones generadas. El cálculo inicial del desorden y la preparación de índices tienen costes propios, aunque no impriman movimientos.

### 1. Simple: extracción sucesiva del mínimo (`--simple`)

1. Busca el valor mínimo presente en `a`.
2. Lo acerca a la cima mediante `ra` o `rra`, eligiendo el sentido que requiere menos rotaciones.
3. Lo traslada a `b` mediante `pb`.
4. Repite hasta vaciar `a` y devuelve todos los elementos con `pa`.

**Justificación:** es una estrategia de selección sencilla de implementar, razonar y utilizar como referencia frente a métodos más eficientes.

**Cota superior de instrucciones:** **O(n²)** en el peor caso: se pueden realizar hasta O(n) rotaciones por cada uno de los O(n) elementos. **Espacio auxiliar del algoritmo:** O(1), una vez creadas las pilas.

### 2. Intermedio: bloques de índices o *chunks* (`--medium`)

1. Calcula un tamaño de bloque próximo a `√n`.
2. Recorre `a` y envía a `b` mediante `pb` los elementos cuyo índice pertenece al rango de trabajo; utiliza `ra` para continuar buscando.
3. Amplía progresivamente el rango hasta transferir todos los elementos.
4. Reconstruye `a` localizando sucesivamente el máximo de `b`, acercándolo a su cima con `rb` o `rrb` y utilizando `pa`.

**Justificación:** agrupar índices reduce las búsquedas indiscriminadas y busca mejorar el número práctico de movimientos frente a la extracción simple.

**Análisis de operaciones:** la fase de distribución en aproximadamente `√n` bloques tiene como referencia **O(n√n)** rotaciones y envíos. No obstante, en la versión actual, la reconstrucción de `b` extrae máximos uno a uno y puede necesitar hasta **O(n²)** rotaciones como cota superior conservadora. Por ello, **la implementación completa todavía no tiene demostrada la cota O(n√n) exigida para la estrategia intermedia**. **Espacio auxiliar del algoritmo:** O(1), sin contar las estructuras generales de las pilas.

### 3. Complejo: radix binario LSD (`--complex`)

1. Trabaja sobre los índices normalizados de `0` a `n - 1`.
2. Recorre sus bits del menos significativo al más significativo.
3. Para cada bit, envía a `b` los índices cuyo bit es `0` (`pb`) y rota en `a` los de bit `1` (`ra`).
4. Devuelve a `a` los valores almacenados en `b` (`pa`) antes de procesar el bit siguiente.

**Justificación:** al distribuir establemente los elementos según cada bit se obtiene una ordenación que no depende de las magnitudes ni del signo de los enteros originales.

**Cota superior de instrucciones:** **O(n log n)**, porque se procesan O(log n) posiciones binarias y en cada una se realizan O(n) movimientos. **Espacio auxiliar del algoritmo:** O(1) adicional, usando las pilas ya existentes; la preparación inicial de índices utiliza O(n) espacio temporal.

### 4. Adaptativo: selección por desorden (`--adaptive`, predeterminado)

La implementación actual decide qué algoritmo ejecutar según el índice `D`:

| Nivel de desorden | Umbral | Algoritmo ejecutado actualmente | Objetivo del subject |
| --- | --- | --- | --- |
| Bajo | `D < 0.2` | Simple, extracción del mínimo | O(n) |
| Medio | `0.2 ≤ D < 0.5` | Intermedio, chunks | O(n√n) |
| Alto | `D ≥ 0.5` | Complejo, radix binario | O(n log n) |

**Justificación de los umbrales:** `0.2` y `0.5` son los límites establecidos expresamente en el enunciado para distinguir entradas con poco, medio y mucho desorden. No son valores obtenidos de una búsqueda experimental de umbrales óptimos. El objetivo del selector es emplear un método de menor coste para entradas casi ordenadas y otros métodos progresivamente más escalables conforme aumenta el desorden.

**Cotas reales de la versión documentada:** la rama baja usa el algoritmo simple, cuya cota es O(n²), y **no satisface todavía el objetivo O(n)**. La rama media utiliza el algoritmo por chunks, cuya fase de extracción máxima tampoco garantiza todavía O(n√n) como cota completa. La rama alta sí selecciona radix, con O(n log n) instrucciones. Los cambios necesarios para cumplir los objetivos de las dos primeras ramas quedan pendientes; no se presentan esas cotas como alcanzadas.

**Espacio auxiliar:** O(1) adicional en la selección y ejecución de los algoritmos, excluyendo las pilas y la preparación de índices. El programa en su conjunto usa O(n) espacio dinámico en función del número de elementos, además del almacenamiento de los argumentos.

## Rendimiento y comprobación

El enunciado establece los siguientes umbrales para entradas aleatorias:

| Tamaño | Mínimo exigido | Buen rendimiento | Excelente |
| --- | ---: | ---: | ---: |
| 100 números | Menos de 2.000 operaciones | Menos de 1.500 | Menos de 700 |
| 500 números | Menos de 12.000 operaciones | Menos de 8.000 | Menos de 5.500 |

Estas cifras son **criterios del enunciado**, no resultados garantizados para cualquier ejecución de esta implementación.

Algunas pruebas reproducibles:

```bash
# Verificar una secuencia completa:
ARG="3 2 1"
./push_swap --complex $ARG | ./checker $ARG

# Examinar la salida y el número de líneas:
./push_swap --simple $ARG
./push_swap --complex $ARG | wc -l

# Comprobar manejo de errores:
./push_swap 1 2 1
./push_swap 2147483648
./push_swap ""
```

Para inspeccionar la memoria dinámica en un entorno con Valgrind puede usarse, por ejemplo:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
```

## Organización del repositorio

```text
.
├── Makefile
├── README.md
├── push_swap.c                 # Punto de entrada principal
├── push_swap.h                 # Estructuras y prototipos
├── algorithms/                 # Estrategias y cálculo de desorden
├── bench/                      # Estadísticas de operaciones
├── bonus/checker.c             # Verificador de instrucciones
├── parse/                      # Argumentos, números e indexación
├── lst_utils/                  # Utilidades de listas y memoria
├── push_swap_ops/              # Operaciones permitidas
└── libft/                      # Libft, printf y get_next_line
```

## Recursos

### Documentación y referencias

- **Enunciado oficial de Push_swap (Escuela 42):** especificación de las operaciones, estrategias, índice de desorden, benchmark, evaluación y bonus.
- **La Norma de 42:** reglas de estilo, estructura y organización de código C utilizadas durante el proyecto.
- **Linux man-pages — `read(2)`:** [man7.org/linux/man-pages/man2/read.2.html](https://man7.org/linux/man-pages/man2/read.2.html). Lectura de bytes desde `stdin`, EOF y errores.
- **Linux man-pages — `malloc(3)` y `free(3)`:** [man7.org/linux/man-pages/man3/malloc.3.html](https://man7.org/linux/man-pages/man3/malloc.3.html). Reserva y liberación de memoria dinámica.
- **cppreference — C:** [en.cppreference.com/w/c](https://en.cppreference.com/w/c). Tipos, expresiones, operadores y comportamiento de C.
- **Radix sort:** [en.wikipedia.org/wiki/Radix_sort](https://en.wikipedia.org/wiki/Radix_sort). Distribución por dígitos y enfoque LSD.
- **Selection sort:** [en.wikipedia.org/wiki/Selection_sort](https://en.wikipedia.org/wiki/Selection_sort). Ordenación por selección como referencia del algoritmo simple.
- **Big-O notation:** [en.wikipedia.org/wiki/Big_O_notation](https://en.wikipedia.org/wiki/Big_O_notation). Notación asintótica y comparación de cotas.

### Uso de inteligencia artificial

Se ha utilizado **ChatGPT** como herramienta de apoyo para el aprendizaje y la revisión del proyecto, especialmente en:

- Explicaciones de conceptos de C necesarios para el desarrollo del proyecto.
- Discusión y contraste del diseño de las estrategias simple, por chunks, radix y adaptativa.
- Propuesta y análisis de pruebas de compilación, validación y rendimiento.
- Apoyo en la preparación de documentación y del presente README.

Las respuestas de IA se han utilizado como apoyo y se han contrastado con el enunciado, el código y las pruebas realizadas por el equipo. La responsabilidad del funcionamiento, la comprensión y la entrega corresponde a los dos estudiantes.

*This project was created as part of the 42 curriculum by pabbenit and dbustama.*

# Push_swap

## Description

**Push_swap** is a 42 School project whose goal is to sort a sequence of integers in ascending order using only two stacks (`a` and `b`) and a limited set of operations. Initially, `a` contains the numbers in the order provided as command-line arguments, and `b` is empty. The first number represents the top of `a`.

The **`push_swap`** program parses the input, selects a sorting strategy, and writes the instructions needed to sort `a` to standard output (`stdout`). The goal is not merely to obtain the correct order: it is also to minimize the number of instructions emitted.

Four selectable modes are implemented: **simple**, **medium**, **complex**, and **adaptive** (the default). The project also includes a `--bench` statistics mode and an additional **`checker`** program as a bonus.

## Instructions

### Compilation

From the repository root:

```bash
make            # Build push_swap and the required Libft library
make bonus      # Build checker
make clean      # Remove object files
make fclean     # Remove objects, executables, and the compiled library
make re         # Rebuild push_swap from scratch
```

The project uses `cc` with `-Wall -Wextra -Werror`. The Makefile links against the project's own library in `libft/`.

### Running push_swap

```bash
./push_swap 3 2 1
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1
./push_swap "3 -2 10 5"
```

| Option | Behavior |
| --- | --- |
| No selector | Uses adaptive mode. |
| `--simple` | Forces repeated minimum extraction. |
| `--medium` | Forces the block-based, or *chunk*, algorithm. |
| `--complex` | Forces binary LSD (Least Significant Digit) radix sort. |
| `--adaptive` | Selects a strategy based on the initial disorder level. |
| `--bench` | Adds statistics to `stderr` while keeping the instructions on `stdout`. |

Instructions are printed one per line. An input that is already sorted requires no operations. With no arguments, the program must exit without displaying anything; for invalid input, it writes `Error\n` to `stderr`.

### Benchmark mode

```bash
./push_swap --bench 3 2 1

# Save statistics and pipe the operations to checker:
ARG="3 2 1"
./push_swap --bench $ARG 2> bench.txt | ./checker $ARG

# Count only the instructions:
./push_swap --complex $ARG | wc -l
```

The benchmark reports the disorder index, the executed strategy, the complexity reported by the program, the total number of instructions, and a breakdown of the 11 operations. Statistics are sent to **`stderr`** and operations to **`stdout`**; keeping them separate allows pipes to be used without mixing their contents.

### Bonus: checker

First, build the bonus with `make bonus`. The checker receives the same initial numbers as Push_swap and reads instructions from standard input (`stdin`):

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG

printf 'sa\nrra\n' | ./checker 3 2 1
printf 'pb\n' | ./checker 1 2 3
printf 'invalid_instruction\n' | ./checker 3 2 1
```

The checker uses `get_next_line()` to read complete instructions and applies them to its two stacks. Upon reaching the end of input, it writes `OK\n` if **`a` is sorted and `b` is empty**, or `KO\n` otherwise. If an instruction or argument is invalid, it writes `Error\n` to `stderr`. With no arguments, it exits silently.

## Allowed operations

| Operation | Meaning |
| --- | --- |
| `sa`, `sb` | Swap the first two elements of `a` or `b`. |
| `ss` | Apply the swap operations to both stacks. |
| `pa` | Push the top element of `b` onto `a`. |
| `pb` | Push the top element of `a` onto `b`. |
| `ra`, `rb` | Rotate a stack upwards: the first element moves to the end. |
| `rr` | Apply upward rotation to both stacks. |
| `rra`, `rrb` | Reverse-rotate a stack: the last element moves to the front. |
| `rrr` | Apply reverse rotation to both stacks. |

Combined instructions (`ss`, `rr`, `rrr`) count as **one** emitted instruction, even though they affect both stacks.

## Design and technical decisions

### Stack representation

The project uses doubly linked lists (`t_node`), with pointers to the first and last nodes (`head`, `tail`) and a `size` counter in each `t_stack`. A central `t_data` structure stores both stacks, the algorithm selector, benchmark/checker flags, the disorder index, and operation counters.

Numbers are validated before nodes are created. Node and structure deallocation is centralized in cleanup functions, while argument processing manages its own temporary allocations.

### Value indexing

Before sorting, each node is assigned an `n_index` corresponding to the position of its value in the sorted sequence, using indices from `0` to `n - 1`.

This normalization allows the binary radix algorithm to handle negative or large numbers without changing its logic. For example, the values `[-10, 50, 3]` correspond to the indices `[0, 2, 1]`.

### Disorder index

Disorder is measured **before performing any movements** using the proportion of inverted pairs:

$$
D = \frac{I}{\frac{n(n-1)}{2}}
$$

Here, `I` is the number of pairs of positions `(i, j)` such that `i < j` and `a[i] > a[j]`, and `n` is the number of elements. For `n < 2`, we define `D = 0`.

- `D = 0`: sorted input.
- `D = 1`: strictly descending input.
- `0 < D < 1`: partially disordered input.

Counting inverted pairs requires **O(n²) comparisons in C** and **O(1) auxiliary memory**, excluding the temporary array the program uses to represent the values.

## Selected algorithms and rationale

**Important:** this project distinguishes between the number of **Push_swap instructions emitted** and the internal execution time in C. The operation bounds required by the subject refer to the generated instructions. Initial disorder calculation and index preparation have their own costs, even though they do not print movements.

### 1. Simple: Selection Sort adaptation (`--simple`)

1. Find the minimum value currently in `a`.
2. Bring it to the top using `ra` or `rra`, choosing the direction requiring fewer rotations.
3. Transfer it to `b` using `pb`.
4. Repeat until `a` is empty, then return all elements using `pa`.

**Rationale:** this is a selection-based strategy that is straightforward to implement, reason about, and use as a baseline against more efficient methods.

**Upper bound on instructions:** **O(n²)** in the worst case: up to O(n) rotations may be needed for each of O(n) elements. **Algorithm's auxiliary space:** O(1), once the stacks have been created.

### 2. Medium: Chunk-based sorting *chunks* (`--medium`)

1. Compute a chunk size close to `√n`.
2. Traverse `a` and push elements whose indices fall within the current range to `b` using `pb`; use `ra` to continue searching.
3. Gradually expand the range until all elements have been transferred.
4. Rebuild `a` by repeatedly finding the maximum in `b`, bringing it to the top with `rb` or `rrb`, and using `pa`.

**Rationale:** grouping indices reduces unrestricted searches and aims to lower the practical number of moves compared with simple extraction.

**Operation analysis:** distributing elements across approximately `√n` chunks has a reference bound of **O(n√n)** rotations and pushes. However, in the current version, rebuilding from `b` extracts maximum values one by one and may require up to **O(n²)** rotations as a conservative upper bound. Therefore, **the complete implementation has not yet demonstrated the O(n√n) bound required for the medium strategy**. **Algorithm's auxiliary space:** O(1), excluding the general stack structures.

### 3. Complex: binary LSD radix sort (`--complex`)

1. Work with normalized indices from `0` to `n - 1`.
2. Process their bits from least significant to most significant.
3. For each bit, push indices whose bit is `0` to `b` (`pb`) and rotate indices whose bit is `1` within `a` (`ra`).
4. Return the values stored in `b` to `a` (`pa`) before processing the next bit.

**Rationale:** stable distribution by each bit produces an ordering that does not depend on the magnitudes or signs of the original integers.

**Upper bound on instructions:** **O(n log n)**, since O(log n) bit positions are processed and each requires O(n) movements. **Algorithm's auxiliary space:** an additional O(1), using the existing stacks; initial index preparation uses O(n) temporary space.

### 4. Adaptive: disorder-based selection (`--adaptive`, default)

The current implementation chooses which algorithm to run based on the index `D`:

| Disorder level | Threshold | Algorithm currently executed | Subject requirement |
| --- | --- | --- | --- |
| Low | `D < 0.2` | Simple, minimum extraction | O(n) |
| Medium | `0.2 ≤ D < 0.5` | Medium, chunks | O(n√n) |
| High | `D ≥ 0.5` | Complex, binary radix | O(n log n) |

**Rationale for the thresholds:** `0.2` and `0.5` are the limits explicitly established by the subject to distinguish low, medium, and high disorder. They were not obtained through an experimental search for optimal thresholds. The selector aims to use a lower-cost method for nearly sorted inputs and progressively more scalable methods as disorder increases.

**Actual bounds of the documented version:** the low-disorder branch uses the simple algorithm, whose bound is O(n²), and **does not yet meet the O(n) requirement**. The medium branch uses the chunk-based algorithm, whose maximum-extraction phase also does not yet guarantee O(n√n) as an overall bound. The high-disorder branch does select radix, with O(n log n) instructions. Changes needed to meet the goals of the first two branches remain pending; those bounds are not presented as achieved.

**Auxiliary space:** an additional O(1) for strategy selection and algorithm execution, excluding the stacks and index preparation. The program as a whole uses O(n) dynamic space as a function of the number of elements, in addition to argument storage.

## Performance and verification

The subject establishes the following thresholds for random inputs:

| Input size | Minimum requirement | Good performance | Excellent |
| --- | ---: | ---: | ---: |
| 100 numbers | Fewer than 2,000 operations | Fewer than 1,500 | Fewer than 700 |
| 500 numbers | Fewer than 12,000 operations | Fewer than 8,000 | Fewer than 5,500 |

These figures are **the subject's evaluation criteria**, not results guaranteed for every run of this implementation.

Some reproducible tests:

```bash
# Verify a complete instruction sequence:
ARG="3 2 1"
./push_swap --complex $ARG | ./checker $ARG

# Inspect the output and number of lines:
./push_swap --simple $ARG
./push_swap --complex $ARG | wc -l

# Check error handling:
./push_swap 1 2 1
./push_swap 2147483648
./push_swap ""
```

To inspect dynamic memory in an environment with Valgrind, you can use, for example:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
```

## Repository structure

```text
.
├── Makefile
├── README.md
├── push_swap.c                 # Main entry point
├── push_swap.h                 # Structures and function prototypes
├── algorithms/                 # Strategies and disorder calculation
├── bench/                      # Operation statistics
├── bonus/checker.c             # Instruction checker
├── parse/                      # Arguments, numbers, and indexing
├── lst_utils/                  # Linked-list and memory utilities
├── push_swap_ops/              # Allowed operations
└── libft/                      # Libft, printf, and get_next_line
```

## Resources

### Documentation and references

- **Official Push_swap subject (42 School):** specifications for operations, strategies, disorder index, benchmark, evaluation, and bonus.
- **42 Norm:** C style, structure, and code organization rules followed throughout the project.
- **Linux man-pages — `read(2)`:** [man7.org/linux/man-pages/man2/read.2.html](https://man7.org/linux/man-pages/man2/read.2.html). Reading bytes from `stdin`, EOF, and errors.
- **Linux man-pages — `malloc(3)` and `free(3)`:** [man7.org/linux/man-pages/man3/malloc.3.html](https://man7.org/linux/man-pages/man3/malloc.3.html). Dynamic memory allocation and deallocation.
- **cppreference — C:** [en.cppreference.com/w/c](https://en.cppreference.com/w/c). C types, expressions, operators, and behavior.
- **Radix sort:** [en.wikipedia.org/wiki/Radix_sort](https://en.wikipedia.org/wiki/Radix_sort). Digit-by-digit distribution and the LSD approach.
- **Selection sort:** [en.wikipedia.org/wiki/Selection_sort](https://en.wikipedia.org/wiki/Selection_sort). Selection sorting as a reference for the simple algorithm.
- **Big-O notation:** [en.wikipedia.org/wiki/Big_O_notation](https://en.wikipedia.org/wiki/Big_O_notation). Asymptotic notation and comparison of bounds.

### Use of artificial intelligence

**IA** was used as a supporting tool for learning and reviewing the project, particularly for:

- Explanations of C concepts needed for project development.
- Discussing and comparing the design of the simple, chunk-based, radix, and adaptive strategies.
- Proposing and analyzing compilation, input-validation, and performance tests.
- Assisting with documentation and preparation of this README.

AI-generated responses were used as supporting material and checked against the subject, the code, and tests performed by the team. Responsibility for the project's coding, functionality, understanding, and submission remains with both students.

## Members Contributions

- Every member of this group has contributed to the conceptual design of each part of the project and has a thorough understanding of all the concepts required to develop it.
- Each member has contributed to develop, test and debug the code implementations of ths project.                                                 

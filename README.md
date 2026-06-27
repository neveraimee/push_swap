*This project has been created as part of the 42 curriculum by aimdoyle, asousa-p.*

## Description

Push_swap is a sorting algorithm project that sorts a stack of integers using
two stacks (stack a and stack b) and a set of operations. The goal is to sort
stack a in ascending order.

Our project explores algorithm complexity by implementing four distinct strategies of different complexity, and an
adaptive algorithm that selects the best strategy to implement based on how unsorted
the input is.

## Instructions

### Compilation
```bash
make
```

### Usage
```bash
./push_swap [numbers]
```

### Strategy Flags
```bash
./push_swap --simple  [numbers]    # O(n²) bubble sort
./push_swap --medium  [numbers]    # O(n√n) chunk sort
./push_swap --complex [numbers]    # O(n log n) radix sort
./push_swap --adaptive [numbers]   # adaptive chooses one of the above based on the disorder level
```

### Benchmark Mode
```bash
./push_swap --bench [numbers]
```

### Error Cases
```bash
./push_swap 1 one 2      # non-integer → Error
./push_swap 1 1 2        # duplicate   → Error
./push_swap 99999999999  # out of range → Error
```

### Verify With Checker
```bash
ARG="5 3 1 4 2"
./push_swap $ARG | ./checker $ARG
```

## Algorithms

### Disorder Metric
Before sorting, the program computes a disorder value between 0 and 1
representing how unsorted the input is.

### Simple — O(n²) — Bubble Sort
A bubble sort adaptation that repeatedly compares adjacent elements,
swapping them if out of order and using stack b as temporary storage.
Best for nearly sorted inputs with a low disorder level.

### Medium — O(n√n) — Chunk Sort
Divides the index range into chunks of size √n. Elements belonging to
each chunk are pushed to stack b in order, then pulled back to stack a
by always retrieving the largest remaining index using shortest-path
rotation (either rb or rrb depending on which direction reaches the
target faster).

### Complex — O(n log n) — Radix Sort
A bitwise radix sort that sorts by binary representation of each
number's index. For each bit position, numbers with a 0 bit are pushed
to stack b, numbers with a 1 bit are rotated in stack a, then
everything is pulled back.

### Adaptive — Default Strategy
Measures the disorder, then selects the most appropriate algorithm:

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 0.2    | Bubble sort | O(n²) |
| 0.2–0.5  | Chunk sort  | O(n√n) |
| ≥ 0.5    | Radix sort  | O(n log n) |

## Resources

### References
- [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Sorting Algorithim Video](https://www.youtube.com/watch?v=h1Bi0granxM)

### AI Usage
Claude AI was used throughout this project to:
- Understand algorithmic complexity (Big O notation, O(n²), O(n√n), O(n log n))

- Learn how radix sort works with binary bit manipulation

- Debug infinite loops and edge cases in chunk sort



## Contributions

| Login | Contributions |
|-------|--------------|
| aimdoyle | Stack data structure, all 11 operations, chunk sort, adaptive sort, bench output |
| asousa-p | Parsing and validation, radix sort, bubble sort, index nodes, main |
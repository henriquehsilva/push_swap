The very first line must be italicized and read: This project has been created as part
of the 42 curriculum by marbelas and hhnorio

## DESCRIPTON
push_swap is a C program designed to sort integers. Starting with a set of integers in stack `a`, the program sorts them in ascending order using two stacks (`a` and `b`) and a limited set of instructions (moves). It calculates and prints the shortest possible sequence of operations to the standard output.

## permitted operations

| Operation | Description |
|----------|-----------|
| `sa` | Swap the two top elements of stack `a` |
| `sb` | Swap the two top elements of stack `b` |
| `ss` | Execute `sa` and `sb` at the same time |
| `pa` | Move the top elements of `b` to the top of `a` |
| `pb` | Move the top elements of `a` to the top pf `b` |
| `ra` | Rotate stack `a` upward (first element becomes the last) |
| `rb` | Rotate stack `b` upward |
| `rr` | Execute `ra` and `rb` at the same time |
| `rra` | Rotate stack `a`  downward (last elements becomes the first) |
| `rrb` | Rotate stack `b` downward |
| `rrr` | Execute `rra` and `rrb` at the same time |

## flags

| Flag | Effect |
|------|--------|
| `--simple` | Forces the O(n²) selection-sort strategy |
| `--medium` | Forces the O(n√n) chunk/bucket strategy |
| `--complex` | Forces the O(n log n) recursive quicksort-style strategy |
| `--adaptive` | Picks a strategy automatically based on how "disordered" the input is (this is the **default** when no flag is given) |


## INSTRUCTIONS

## compilation commands

to comile
```
make 

```
to clean
```
make clean
make fclean
make re
```

## simple tests
```
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```
## checker_linux

```
for strat in --simple --medium --complex --adaptive ""; do
  ARG="5 4 3 2 1"
  OUT=$(./push_swap $strat ${=ARG})
  RESULT=$(echo "$OUT" | ./checker_linux ${=ARG})
  echo "Strategy '${strat:-default}': $RESULT"
```

## small inputs

Use the provided `checker_linux` binary to confirm correctness and get a feel for instruction count:

```
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_linux $ARG
```

Reasonable targets:

| Size | Acceptable | Good |
|------|------------|------|
| 3 numbers | ≤ 5 ops | ≤ 3 ops |
| 5 numbers | ≤ 15 ops | ≤ 12 ops |

## large inputs

```
# 100 numbers
for i in 1 2 3; do
  ARG=($(shuf -i 1-500 -n 100))
  OPS=$(./push_swap $ARG | wc -l)
  RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
  echo "Run $i: $RESULT | Ops: $OPS"
done

# 500 numbers
ARG=($(shuf -i 1-1000 -n 500))
./push_swap $ARG | ./checker_linux $ARG
```

Efficiency targets required by 42:

| Number of elements | Acceptable | Good | Excellent |
|---------------------|-----------|------|-----------|
| 100 | < 2000 ops | < 1500 ops | < 700 ops |
| 500 | < 12000 ops | < 8000 ops | < 5500 ops |

## checking memory leaks

```
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 2 1 3 6 5 8 6 12 9 4
```


## RECOURCES

## contributions

hhnorio: project structuring, parsing, and simple, complex, and adaptive algorithms.

marbelas: compute disorder, simple, medium, and adaptive algorithms.

## refs

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
https://www.youtube.com/watch?v=Y95a-8oNqps&t=189s
https://www.geeksforgeeks.org/dsa/quick-sort-algorithm
https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2
https://www.geeksforgeeks.org/dsa/doubly-linked-list
https://www.geeksforgeeks.org/c/atol-atoll-and-atof-functions-in-c-c


AI was utilized for conceptual understanding, test execution, and assisting in the creation of this README.

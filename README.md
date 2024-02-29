# Push Swap

This project implements a sorting algorithm to efficiently sort numbers in a stack, with limited and minimal operations.

It takes a list of integers as input and sorts them in ascending order using two stacks, named A and B. The goal is to perform a series of operations on the stacks to achieve the desired sorting.

## Algorithm

The algorithm i used is a combination of sorting techniques, including Radix sort, to efficiently sort the list of integers.

## Rules

- There must be 2 stacks named A and B.
- To start with:
    - A contains a random number of either positive or negative numbers without any duplicates.
    - B is empty;
- The goal is to sort in ascending order numbers into stack A.

### Moves allowed to be performed on the stack
- **`sa`** - swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **`sb`** - swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **`ss`** - sa and sb at the same time.
- **`pa`** - push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **`pb`** - push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **`ra`** - rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- **`rb`** - rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- **`rr`** - ra and rb at the same time.
- **`rra`** - reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- **`rrb`** - reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- **`rrr`** - rra and rrb at the same time.


## Installation

To compile the Push Swap program, run this command:

```
git clone https://github.com/joaodibba/42_push_swap.git; cd 42_push_swap; make
```

## Usage

To use the Push Swap program, follow these steps:

1. Run the program with a list of integers as arguments: `./push_swap 5 2 8 1 4`
2. The program will output a series of operations to perform on the stacks to achieve the desired sorting.

## Visualizer

To visualize the sorting process, use this [visualizer](https://github.com/o-reo/push_swap_visualizer.git) program.

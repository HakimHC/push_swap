# Push_swap Project

## Project Description

The Push_swap project aims to create a program that sorts a stack of integers using the minimum possible number of operations. The program makes use of two stacks, `a` and `b`, and a set of predefined operations to manipulate these stacks.

## Features

The following operations can be used to manipulate the stacks:

1. **sa (swap a)**: Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
2. **sb (swap b)**: Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
3. **ss**: sa and sb at the same time.
4. **pa (push a)**: Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
5. **pb (push b)**: Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
6. **ra (rotate a)**: Shift up all elements of stack a by 1. The first element becomes the last one.
7. **rb (rotate b)**: Shift up all elements of stack b by 1. The first element becomes the last one.
8. **rr**: ra and rb at the same time.
9. **rra (reverse rotate a)**: Shift down all elements of stack a by 1. The last element becomes the first one.
10. **rrb (reverse rotate b)**: Shift down all elements of stack b by 1. The last element becomes the first one.
11. **rrr**: rra and rrb at the same time.

## Compilation

A Makefile is provided to compile the source files. 

## Limitations

* The program must not use global variables.

## Usage

```bash
./push_swap 4 67 3 87 23
```

The program will output the instructions to sort the input integers.

## Error Handling

The program should handle errors gracefully. For instance, if some arguments aren't integers, are bigger than an integer, or there are duplicates, the program must display "Error" followed by a '\n' on the standard error.

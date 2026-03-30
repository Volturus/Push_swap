*This project has been created as part of the 42 curriculum by vmourey.*

# PUSH SWAP

## DESCRIPTION :
This project has for goal to determine the shortest sequence of instructions to sort a given list of numbers, or at least getting close enough.

Said instructions are as follows :
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

To do so, we use a quicksort, a sorting algorithm that chooses the median number of the array and then repositions the elements so that everything smaller is found before the median, while everything bigger is found after. Once it's done, repeat the operation on the two new lists created around the pivot, etc..., until you get the former pivots in order. 
While doing so, every operation is associated with an ft_printf function writing the corresponding instruction.

## INSTRUCTIONS :
To make use of the program, it is enough to execute the “make all” or “make push_swap” command in the terminal in the folder containing the makefile. Once the executable is obtained, you can use it alongside lists of numbers, no matter whether they are written like this : "1 2 3" or like this : 1 2 3 (or even a combination of both).
The executable thus created can be removed using the “make fclean” command.
Finally, the “make re” command can be used to remove the executable and then recreate it.

The following command, as an example, can be used to generate a random array of variable size (here 10) to be processed by push_swap.
- ARG=$(shuf -i 1-1000 -n 10 | tr '\n' ' '); ./push_swap $ARG
It's also possible to add "| ./checker_x $ARG" in order to verify the instructions given or even "|wc -l" to count their number.

## RESSOURCES:
At the start of the project, I consulted the following references to decide on the sorting algorithm to use.
- https://lamfo-unb.github.io/2019/04/21/Sorting-algorithms/
- https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/


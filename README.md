# Push_swap
Push_swap is a project developed by 42 school\
The goal is to sort two stacks of number with and only with a given set of instructions.\
The project consists of three programs, checker, push_swap and the visualizer.\
Push_swap must display the smallest list of instructions possible to sort the stack.\
Checker will then wait and read instructions on the standard input, Once all the instructions have been read, checker will
execute them on the stack received as an argument.\
If after executing those instructions, stack a is actually sorted and b is empty, it displays **OK** else it displays **KO**

## Usage
Use make command to compile.\
Both programs take a list of integers in this format ./program 1 2 3 4.\
**Push_swap** :\
./push_swap 1 2 3 4\
flag -v before list of integers to use visualizer\
**Checker** :\
./checker 1 2 3 4

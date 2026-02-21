### push_swap

This project has been created as part of the 42 curriculum by <janrodri>

## Description

The **push_swap** project consist in passing an arbitrary sequence of numbers to the program and returning the executed movements required to sort the numbers passed as anrguments. In this you have two stacks: **stack_a** and **stack_b**, placing the passed arguments initially in **stack_a**.

In the program the entry can not contain characters that are not digits or single symbols: + / - , the numbers can't be duplicated or exceed the range limits of int.

The movements allowed are: swap (exchange the first with the second element) [sa, sb], rotate (put the first element as last in the stack) [ra, rb], push (transfer the first element to the other stack) [pa, pb], reverse-rotate (put the last node as first in the stack) [rra, rrb]. 

The goal is to adjust the numbers and move them through the stack strategically so at the end the **stack_a** ends up being completely ordered, using the least amount of instructions as possible. Additionally, to finish the sorting it is required that the movements used follow certain restrictions:

• For maximum project validation (100%) and eligibility for bonuses, you must:
	◦ Sort 100 random numbers in fewer than 700 operations.
	◦ Sort 500 random numbers in no more than 5500 operations.
• For minimal project validation (which implies a minimum grade of 80%), you can succeed with different averages:
	◦ 100 numbers in under 1100 operations and 500 numbers in under 8500 operations
	◦ 100 numbers in under 700 operations and 500 numbers in under 11500 operations
	◦ 100 numbers in under 1300 operations and 500 numbers in under 5500 operations


## Instructions

To execute the program, you must run the MAKEFILE with the command 'make'/'make all' to compile all the required files and generate the executable file. In addition, you can clean only the object files created (clean) or all the object files plus the executable file (fclean) with the commands 'make clean'/'make fclean'. Also, you can recompile all the files with 'make re'. After having the files compiled, you can use the following commands to test the push_swap:

- To generate an aleatory sequence of numbers that don't repeat themselves and retain it in a variable (ARG):

	ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(LIMIT_INF,LIMIT_MAX), AMOUNT_NUMBERS))))")


- To put this string of random numbers as the argument to the program, and watch the movements executed to sort the program:

	./push_swap $ARG

- To execute the program with the ARG variable that contains the sequence of random numbers and watch the number of operations that were needed. And also, watch the checker_linux reply to the passed arguments, we can use the following instruction:

	echo "Ops: $(./push_swap $ARG | wc -l | tr -d ' ') | $(./push_swap $ARG | ./checker_linux $ARG)"

		**This command returns the wc(word count) by -l (lines) [number of lines printed] and uses the tr (transliterate) -d (delete) [char] to clean all the empty spaces that could be found in the retrieved data.

- To check the abscense of leaks in the code use:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap



## Resources

The sources used to developed this project have been the following sites:

https://github.com/AzerSD/ksort-push_swap - A reference project that used the K-Sort algorithm used in my implementation.

https://elhacker.info/manuales/Lenguajes%20de%20Programacion/C/Administraci%C3%B3n%20de%20la%20memoria%20en%20C.pdf - A reference in the usage of memory allocations and the consequences when it creates leaks.

https://github.com/mcombeau/push_swap - A project used as reference in the organization and parsing of my implementation.

AI- Copilot / Claude / Chatgpt - As references in concrete subjects of parts of the reuired theory and to have a deeper knowledge of the processes required for the final algorithm. Used to generate tests and corroborate the acquired knowledge. 

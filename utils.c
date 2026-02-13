/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:40:30 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/13 19:27:18 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* clean_error

Description: Function that cleans the stack lists created in the program,
writes in terminal an error message anc closes all the standard streams opened.
Cleans the double pointer(*args), the strings inside the array of 
strings(*args[i]) and the pointer to the array of strings(args) 
[which is char ***args]. The function clear_stack takes care of erasing
the nodes inside each stack item until the last one. Erasing a single stack
deletes the variables inside of it but not the variable of the node that
the address of 'next' is pointing to.

Arguments: The stacks that the program manipulates, stack_a and stack_b. 

Returns: Nothing, just executes the cleaning, informs of the status
and exits the program.

*/

void	clean_error(t_stack **stack_a, t_stack **stack_b, char ***args)
{
	int	i;

	if (stack_a)
		clear_stack(stack_a);
	if (stack_b)
		clear_stack(stack_b);
	i = 0;
	if (args || *args || (*args)[i])
	{
		while ((*args)[i])
			free((*args)[i++]);
		free(*args);
	}
	write(1, "Error\n", 6);
	exit(1);
}

/* ft_atol

Description: Function that converts a numbered expresed in string into
a number with long format.

Arguments: The string to convert.

Returns: The long number that equals the value of the string specified.*/

long int	ft_atol(const char *str)
{
	int			i;
	int			minus;
	long int	result;

	i = 0;
	minus = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (minus)
		result = -result;
	return (result);
}

/* free_string_array

Description: Function to avoid the double ownership of the content that
is refered to by a pointer. An array needs to have control over the memory 
created after a pointer. So if you copy the address of a pointer to a string,
you don't control or own the memory of the original content. Only it's pointer.
To be able to fully free a variable you need to copy the entire content of an 
original reference. And after that, free the references that are no longer
useful. It's better to copy strings not by the address of its pointer but by 
copying the entire string with ft_strdup.

Arguments: A address of an array of strings (the original array 
created with malloc) that needs to be freed. BUT the pointer to this
array is a LOCAL variable--> you didn't create it with malloc --> NOT FREEABLE.
Memory asignated byt the system, not you, which means, you CAN'T FREE IT.

Returns: Nothing, only executes.
*/

void	free_string_array(char ***array)
{
	int	i;

	i = 0;
	if (!array || !(*array) || !(*array)[i])
		return ;
	while ((*array)[i])
		free((*array)[i++]);
	free(*array);
	*array = NULL;
}

/* assign_index

Description: Function that takes the value of a node and compares its number 
to the rest of numbers of the other nodes. Takes the number of elements that 
are less to reflect the final index in the order.

Arguments: The head of the stack, a copy of the original, because we 
only want to read it. And the node of the stack for which we want the index.

Returns: The final index of the node from the stack.
 */

int	assign_index(t_stack *stack_head, t_stack *stack_node)
{
	t_stack	*head;
	int		index;
	int		value;

	index = 0;
	head = stack_head;
	value = stack_node->value;
	while (head)
	{
		if (head->value < value)
			index++;
		head = head->next;
	}
	return (index);
}

/* chunks

Description: Function that determines the amount of chunks that
will be generated.

Arguments: The amount of numbers registrered in the stack

Returns: For numbers shorter than 5, we would use the function of 
'sort_three' and not need the chunks division. For numbers shorter than 
20 we would use chunks of 5 elements. For numbers less than 200 (incluiding 
the reference of 100) we would use divisions by 20 elements. For numbers
bigger than 200, (including the reference of 500) we would use divisions 
by 45 elements. For numbers shorter than 5, we would use the 'sort_three'
function.

*/

int	chunks(int size_stack)
{
	int	chunks;

	chunks = 0;
	if (size_stack >= 5 && size_stack < 20)
		return (5);
	if (size_stack >= 20 && size_stack <= 200)
	{
		chunks = size_stack / 20;
		if (size_stack % 20 != 0)
			chunks++;
	}
	if (size_stack > 200)
	{
		chunks = size_stack / 45;
		if (size_stack % 45 != 0)
			chunks++;
	}
	return (chunks);
}

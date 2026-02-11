/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:20:54 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/11 20:57:56 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* fill_stack
	
Description: Fills an stack with the specified and valid values. Takes the args
list od strings, converts each element into an int and fills the stack list.

Arguments: The list of strigns wiht the cleaned elements.

Returns: The head of the stack list created with all of the elements. If there 
was a value that exceeded the limits of int, it would exit the function and
won't create the stack, leaving it's value to NULL. 

Leaks: stack_new generates a node usign malloc, and reserves the
next node with a stack_new, which requires a malloc too. The caller of 
fill_stack needs to free the nodes and the nodes->next values to free
the mallocs created.

Receives an array of strings pending to be freed after serving
its purpose. It is only read, so this function doesn't have the ownership
to free it, but the caller of fill_stack needs to free normalized after 
filling the stack. It has been dragging the malloc of all of these functions:
new_argv<-ft_split<-ft_strdup<-clear_filling_zeros.

Leaks: This function passes the ownership to the caller, so once you
invoke this function, and after transforming or modifying the stack,
after it serves it's purpose, needs to be freed. The head and the
linked next nodes. 
*/

t_stack	*fill_stack(char **normalized)
{
	int		i;
	t_stack	*stack_head;
	t_stack	*stack_element;
	int		value;

	stack_head = NULL;
	stack_element = NULL;
	i = 0;
	while (normalized[i])
	{
		value = long_to_int_limits(normalized[i]);
		stack_element = stack_new(value);
		stack_add_bottom(&stack_head, stack_element);
		i++;
	}
	return (stack_head);
}
/* long_to_int_limits

Description: Function that before converting the element of the normalized 
array into the value of an stack, checks if it is inside the limits of int,
turning it into long first, to also see that the extremes are valid. 
Then converting into int if they fit the range. If they dont, the program
exits its execution, printing 'Error' and cleaning the stack.

Arguments: A normalized element in a string

Returns: The number int if it's valid. An interruption of the
execution of the program.
*/

int	long_to_int_limits(char *normalized_element)
{
	long	norm_element;
	int		checked;

	norm_element = ft_atol(normalized_element);
	if ((norm_element >= -2147483648) && (norm_element <= 2147483647))
		checked = (int) norm_element;
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (checked);
}

/* clear_stack

Description: To clear all the instances of memory assigned to a node.
That implies cleaning the node, that would erase its internal values.
And also cleaning separately the nodes referenced inside the 
original node. To clear properly, if the stack is cleared, we would
erase all the linked nodes existing. 

Arguments: The head of the stack list. As we want to delete the original,
we will pass the address of the stack list that we want to erase.

Returns:  Nothing, just executes the action
*/

void	clear_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return ;
	while ((*stack)->next != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		(*stack) = temp;
	}
	free(*stack);
}

/* fill_index

Description: Goes through all the elements of the array assigning each
element its index.

Arguments: The original stack

Returns : Nothing, just executes the action or exits if there is no
content in the stack.
*/

void	fill_index(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		temp->index = assign_index(*stack, temp);
		temp = temp->next;
	}
}

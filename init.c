/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:20:54 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/03 18:52:14 by janrodri         ###   ########.fr       */
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
*/

t_stack	*fill_stack(int *array)
{
	int		i;
	t_stack	*stack_head;
	t_stack	*stack_element;

	stack_head = NULL;
	stack_element = NULL;
	i = 0;
	while (array[i])
	{
		stack_element = stack_new(array[i]);
		stack_add_bottom(&stack_head, stack_element);
		if (i == 0)
			stack_head = stack_element;
		i++;
	}
	return (stack_head);
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

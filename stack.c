/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:42:10 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/03 21:18:08 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* stack_new

Description: Function that initializes a new stack,
stablishing the initial values of each attribute of
a node (stack).

Arguments: To create a stack you need at least the
firts value that would keep a node from the stack.

Returns: The first node that would create the stack.
*/

t_stack	*stack_new(long value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}


/* get_stack_bottom 

Description: Function that returns the last stack of 
the list of stacks (nodes in stack), the one that ends in NULL.

Arguments: the head of the stack.

Returns: the node at the bottom of the stack list*/

t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_stack_before_bottom

Description: Function that returns the stack previous to the bottom 
stack. The previous one to the stack that contains NULL in its (next) attribute.

Arguments: the head of the stack.

Returns: the previous node to the bottom of the stack list*/

t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack-> next && (stack->next)->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_stack_size 

Decription: Function that counts the nodes that are contained in 
the list of stack

Arguments: the head of the stack

Returns: the number of nodes inside the list of stack
*/
int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
/* stack_add_bottom

Description: Function that aggregates a new node at 
the stack list at the end of the stack.

Arguments: The original head of the stack list to which we
want to add a node at. To do so, we use the address of the
original to modify this one, not a local copy. Also, the 
new node we want to append to the stack.

Returns: Nothing, it just executes the action.
*/

void	stack_add_bottom(t_stack **stack, t_stack *bottom)
{
	t_stack	*temp;

	if (!bottom)
		return ;
	if (!*stack)
	{
		*stack = bottom;
		(*stack)->next = NULL;
		return ;
	}
	temp = get_stack_bottom(*stack);
	temp->next = bottom;
	bottom->next = NULL;
}


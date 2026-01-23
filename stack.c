/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:42:10 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/23 19:06:28 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* stack_new

Description: Function that initializes a new stack,
stablishing the initial values of each attribute of
a node (stack).

Arguments: To create a stack you need at least the
firts value that would keep a node from the stack.

Returns: The first node that would create the stack.*/
t_stack	*stack_new(int value)
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


/* clear_stack

Description: 

Arguments:

Returns:  */

void	clear_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack->next != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:24:46 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/25 23:23:17 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* position_index

Returns the position of the node with the specified index*/

int	position_index(t_stack *stack, int index)
{
	int		pos;
	t_stack	*temp;

	temp = stack;
	pos = 0;
	while (temp && temp->index != index)
	{
		pos++;
		temp = temp->next;
	}
	return (pos);
}

/* sort_five

Function to optimize the sorting of a stack with five elements.
 */

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		while (position_index(*stack_a, i) != 0)
		{
			if (position_index(*stack_a, i) < 2)
				do_ra(stack_a);
			else
				do_rra(stack_a);
		}
		do_pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	do_pa(stack_b, stack_a);
	do_pa(stack_b, stack_a);
}

/* sort_two

Function to optimize the sorting of a stack with two elements.
 */

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}

/* sort_three

Function to optimize the sorting of a stack with three elements.
 */

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
	if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		do_rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	while (position_index(*stack_a, 0) != 0)
	{
		if (position_index(*stack_a, 0) < 1)
			do_ra(stack_a);
		else
			do_rra(stack_a);
	}
	do_pb(stack_a, stack_b);
	sort_three(stack_a);
	do_pa(stack_b, stack_a);
}

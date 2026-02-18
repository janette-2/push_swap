/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_returns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:41:51 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/17 22:51:30 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting_return

Description: 

Arguments:

Returns:
*/

void	sorting_return(t_stack **stack_b, t_stack **stack_a)
{
	int		size;
	t_stack	*temp;

	temp = *stack_b;
	size = get_stack_size(temp);
	while (*stack_b)
	{
		if (biggest_index(size) == (*stack_b)->index)
		{
			do_pa(stack_b, stack_a);
			size--;
		}
		else
		{
			if (position_biggest(*stack_b, size)
				<= (get_stack_size(*stack_b) / 2))
				do_rb(stack_b);
			else
				do_rrb(stack_b);
		}
	}
}
/* biggest_index
 */

int	biggest_index(int size)
{
	int	biggest;

	biggest = size - 1;
	return (biggest);
}

/* position_biggest
 */

int	position_biggest(t_stack *stack_b, int size)
{
	int		pos;
	t_stack	*temp;

	temp = stack_b;
	pos = 0;
	while (temp && temp->index != biggest_index(size))
	{
		pos++;
		temp = temp->next;
	}
	return (pos);
}

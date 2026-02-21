/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_returns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 17:41:51 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/21 17:13:47 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting_return

Description: Analyses the elements in the stack to search for the highest 
index at the moment. If it is found, and is at the top of B, it is pushed 
back to A and reduces the count of the original size to keep track of the 
elements that are left and search for the respected index. 
If the highest index is not at the top of B, then it analyses in which half 
of the stack is the current highest index. If it is in the higher half, it
rotates to keep moving the element to the top which is nearest. If the highest 
index is at the lower half, does a reverse-rotate action, to keep moving the
element to the bottom of the stack which is the nearest until the reverse-rotate
gets to the target element and places it in the top of the stack. 


Arguments: The stacks

Returns:Nothing, just executes.
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

Description: Calculates the highest index in the stack at the moment.
It gets the original size of the stack as reference, and as this argument
decreases as the elements get pushed back to A, it keeps count of how many
elements are in B, and determines that, because B has empty A after sorting the
chunks, the highest index that is left is the amount that remains - 1 (because
the initial 0) 
*/

int	biggest_index(int size)
{
	int	biggest;

	biggest = size - 1;
	return (biggest);
}

/* position_biggest

Determines, when we are reaching the highest index to push it back to A, 
the position where this target in the stack B. We need to know in which node
it is, to return the position of it and compare with the middle of the current
stack, to see if we move the stack to the top or to the bottom in the next actions.
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

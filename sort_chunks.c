/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:48:01 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/15 01:19:23 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting_chunks

Description: Function that, through the definition of limits
by the chunks, detects any index inside the ranges and pushes 
it to stack B. If it is in the lower half of the range, it also
rotates in B to push these to the bottom.

Arguments: The stack A and stack B as well as the range of the chunks
implemented. It creates chunks so even if they arnot completed, all
the nodes in the stack get grouped, leaving stack A empty at the end.

Returns: Nothing, just executes the action descripted and prints in
terminal the respective movements executed.

n_chunks: Division that secures that, if there is only 1 extra element 
that doesn't fit into an exact division, it adds one more chunk. That works
because the division only keeps the unity of a decimal number, so if there 
is an exact division, it gets the right unit. And if there is an extra division
it also takes it into account and adds it. */

void	sorting_chunks(t_stack **stack_a, t_stack **stack_b, int chunks)
{
	int	low;
	int	i;
	int	high;
	int	n_chunks;
	int	size;

	size = get_stack_size(*stack_a);
	n_chunks = (size + (chunks - 1)) / chunks;
	i = 0;
	while (i < n_chunks)
	{
		low = i * chunks;
		high = high_index(chunks, size, i);
		while (has_index_in_chunk(*stack_a, low, high))
		{
			if ((*stack_a)->index >= low && (*stack_a)->index <= high)
				inside_chunk_range(stack_a, stack_b, low, chunks);
			else
				do_ra(stack_a);
		}
		i++;
	}
}

/* high_index
 */

int	high_index(int chunks, int size, int i)
{
	int	high;

	high = ((i + 1) * chunks) - 1;
	if (high >= size)
		high = size - 1;
	return (high);
}


/* has_index_in_chunk

Description:

Arguments:

Returns: 1 if true, 0 if false 

*/

int	has_index_in_chunk(t_stack *stack_a, int low, int high)
{
	t_stack	*temp;

	temp = stack_a;
	while (temp)
	{
		if (temp->index <= high && temp->index >= low)
			return (1);
		else
			temp = temp->next;
	}
	return (0);
}

/* inside_chunk_range

Description:

Arguments:

Returns:
*/
void	inside_chunk_range(t_stack **stack_a,
		t_stack **stack_b, int low, int chunks)
{
	int	mid;

	mid = low + (chunks / 2);
	if ((*stack_a)->index < mid)
	{
		do_pb(stack_a, stack_b);
		do_rb(stack_b);
	}
	else
		do_pb(stack_a, stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:43:31 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/24 21:56:14 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_ordered 

Function that analyses if the indexes assigned to the stack 
are already sorted. If so, finishes the execution of the program.
Returns 1 if true, 0 if false.
*/

int	is_ordered(t_stack *stack_a)
{
	int	ordered;

	ordered = 0;
	while (stack_a && (stack_a->index == ordered))
	{
		ordered++;
		stack_a = stack_a->next;
	}
	if (!stack_a)
		return (1);
	return (0);
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

/* sort

Function that determines which 'sort' function to use according
to the amount of elements in the stack.
*/

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 5)
	{
		do_pb(stack_a, stack_b);
		do_pb(stack_a, stack_b);
		sort_two(stack_b);
		sort_three(stack_a);
		do_sb(stack_b);
		do_pa(stack_b, stack_a);
		do_pa(stack_b, stack_a);
	}
	else
	{
		sorting_chunks(stack_a, stack_b, chunks(size));
		sorting_return(stack_b, stack_a);
	}
}
/* check_limits

Function that after having the arguments normalized into simple numbers
analyses if the numbers contained are inside of the allowed range of values
of the 'int' data type. First, converts the numbers from string to long and 
after that, it checks if the value is inside the limits.
If any of them are outside the limits returns 0, if all of them are inside the
limits returns 1.

*/

int	check_limits(char **normalized)
{
	long	value;
	int		i;

	i = 0;
	while (normalized[i])
	{
		value = ft_atol(normalized[i]);
		if (value < -2147483648 || value > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

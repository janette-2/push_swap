/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:43:31 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/18 23:54:37 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_ordered */

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


void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}


void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
	if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		do_rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
	{
		sorting_chunks(stack_a, stack_b, chunks(size));
		sorting_return(stack_b, stack_a);
	}
}

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

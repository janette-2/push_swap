/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 20:43:31 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/18 20:49:11 by janrodri         ###   ########.fr       */
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


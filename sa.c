/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:20:04 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/06 22:04:18 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap_a

Decription: Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.

Arguments: The stack a.

Returns: The entire stack with the first two elements interchanged.

Leaks: The caller of this function, after completing its purpose,
needs to manage the free of the allocated memory that carries stack a.
*/

t_stack	*swap_a(t_stack *stack)
{
	int		temp0;
	int		temp1;
	//t_stack	*temp;

	temp0 = stack->value;
	temp1 = (stack->next)->value;
	stack->value = temp1;
	(stack->next)->value = temp0;
	return (stack);
}
/* 
int	main(int argc, char *argv[])
{
	(void) argc;
	t_stack	*swap_a;

	swap_a = fill_stack(argv++);
	while (swap_a->next)
	{
		printf("Value: %d\n", swap_a->value);
		swap_a = swap_a->next;
	}
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:20:04 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/14 22:16:47 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap_a

Decription: Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.

Arguments: The reference to access the original stack. We need to be able to 
modify the actual pointer to the first element and arrange the nodes, we use
doble pointers. Because if not, the change would not be reflected outside
of this function.

Returns: Nothing, just executes the action. Checks if there is no content,
if there is no pointer to the head of the stack or if there is only 1 element,
if so, the program stops its execution. 
*/

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !(*stack) || !(*stack)->next)
		exit(1);
	first = *stack;
	second = (*stack)->next;
	third = ((*stack)->next)->next;
	second->next = first;
	first->next = third;
	*stack = second;
}

void	do_sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}

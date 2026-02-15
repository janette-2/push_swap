/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 22:03:34 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/14 22:16:47 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* reverse_rotate

Description: Moves the last node of the stack to the head. Moving all the
in between node on position under. We use a pointer to the original stack
to modify the content inside but not lose the reference of the head, therefore,
a pointer that is the access to the new order of the nodes.

Arguments: The reference to access the original stack. We need to be able to 
modify the actual pointer to the first element and arrange the nodes, we use
doble pointers. Because if not, the change would not be reflected outside
of this function.

Returns: Nothing, just executes the action. Checks if there is no content,
if there is no pointer to the head of the stack or if there is only 1 element,
if so, the program stops its execution.

*/

void	reverse_rotate(t_stack **stack)
{
	t_stack	*bottom;
	t_stack	*before_bottom;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	bottom = get_stack_bottom(*stack);
	before_bottom = get_stack_before_bottom(*stack);
	bottom->next = *stack;
	before_bottom->next = NULL;
	*stack = bottom;
}

void	do_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

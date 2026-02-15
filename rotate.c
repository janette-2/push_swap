/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 00:09:41 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/14 22:16:47 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate

Description: Moves the first element of the nodes pointed to by the **stack
head reference to the bottom. Moving all of the remaining, a position further.

Arguments: The reference to access the original stack. We need to be able to 
modify the actual pointer to the first element and arrange the nodes, we use
doble pointers. Because if not, the change would not be reflected outside
of this function.

Returns: Nothing, just executes the action. Checks if there is no content,
if there is no pointer to the head of the stack or if there is only 1 element,
if so, the program stops its execution
*/

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*bottom;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	head = *stack;
	second = (*stack)->next;
	bottom = get_stack_bottom(*stack);
	bottom->next = head;
	head->next = NULL;
	*stack = second;
}

void do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
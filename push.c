/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:27:02 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/10 23:15:32 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push

Description: Function that pushes the first argument of the stack a 
to the stack b. By doing so, the orignal nodes get pushed down.
Moving everything a position further in the stack, but maintaining the
original references to their acceses.

Arguments: The original stacks, the one that is origin and the one that is 
the destination. We will call them with **stack. Because the head of the original
stacks needs to be intact, the content of the nodes may anter but the way to 
access the stack will always be through a pointer to the head node, though 
the node may alter. 

Returns: Nothing, just executes the action if the stacks exists.
Exits if the origin stack is NULL.
*/
void	push(t_stack **origin, t_stack **destiny)
{
	t_stack	*origin_copy;
	t_stack	*new_origin;
	t_stack	*destiny_copy;

	if (!origin || !(*origin))
		exit(1);
	origin_copy = *origin;
	destiny_copy = *destiny;
	new_origin = (*origin)->next;
	(*origin)->next = destiny_copy;
	*destiny = origin_copy;
	*origin = new_origin;
}

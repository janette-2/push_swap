/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:27:02 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/07 19:55:55 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push

Description: Function that pushes the first argument of the stack a 
to the stack b. By doing so, the orignal content gets pushed down.
Moving everything a position further in the stack.

Arguments: The original stacks, the one that is origin and the one that is 
the destination.

Returns: Nothing, just executes the action.
*/
void	push(t_stack *origin, t_stack *destiny)
{
	t_stack	*origin_copy;
	t_stack	*destiny_copy;

	origin_copy = origin;
	destiny_copy = stack_new(origin_copy->value);
	destiny_copy = 

}

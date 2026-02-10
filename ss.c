/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:21:36 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/09 23:48:08 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ss

Description: Function that executes a double swap, of two stacks at the 
same time.

Arguments: The two stacks to swap

Returns: Nothing, just executes the action.*/

void	ss(t_stack **stack1, t_stack **stack2)
{
	swap(&stack1);
	swap(&stack2);

}

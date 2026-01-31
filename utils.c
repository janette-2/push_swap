/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:40:30 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/31 19:19:42 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* clean_error

Description: Function that cleans the stack lists created in the program,
writes in terminal an error message anc closes all the standard streams opened.

Arguments: The stacks that the program manipulates, stack_a and stack_b

Returns: Nothing, just executes the cleaning, informs of the status
and exits the program.

*/

void	clean_error(t_stack **stack_a, t_stack **stack_b, char ***args)
{
	if (stack_a || stack_b)
	{
		clear_stack(stack_a);
		clear_stack(stack_b);
	}
	free(*args);
	write(1, "Error\n", 6);
	exit(1);
}


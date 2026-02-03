/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:40:30 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/03 23:19:10 by janrodri         ###   ########.fr       */
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
	if (stack_a)
		clear_stack(stack_a);
	if (stack_b)
		clear_stack(stack_b);
	if (args && *args) //Puede que exista args y que sea NULL. Si haces un free(NULL) -> SEGMENTATION FAULT
		free(*args);
	write(1, "Error\n", 6);
	exit(1);
}

/* ft_atol

Description: Function that converts a numbered expresed in string into
a number with long format.

Arguments: The string to convert.

Returns: The long number that equals the value of the string specified.*/

long int	ft_atol(const char *str)
{
	int			i;
	int			minus;
	long int	result;

	i = 0;
	minus = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus++;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (minus)
		result = -result;
	return (result);
}

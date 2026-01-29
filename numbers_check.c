/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:39:49 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/29 20:13:50 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* numbers_conversion

Description: Function that transforms a number written with filling zeros
or with equivalents of zero into their simplified version.

Arguments: The *argv[] with all the elements already separated and validated.

Returns: A new array of strings with the conversions made
*/

char	**numbers_conversion(char *argv[])
{
	int		i;
	int		k;
	char	**conversion;

	conversion = argv;
	i = 0;
	while (argv[i])
	{
		if (zero_equivalents(argv[i]))
			conversion[i++] = "0";
		else if (filling_zeros(argv[i]))
		{
			k = 0;
			while (argv[i][k])
			{
				if (argv[i][k] == '0')
					k++;
				conversion[i][k] = argv[i][k++];
			}
			i++;
		}
		else
			conversion[i] = argv[i++];
	}
	return (conversion);
}

/* have_duplicates

Description: Compares each element inside the converted array of 
strings to find duplicates.

Arguments: The converted array of strings with valid numbers,
valid signs and without filling zeros

Returns: 1 or 0. Gives you 1 if there are duplicated elements.
Gives 0 if there are none.*/

int	have_duplicates(char *conversion[])
{
	
}

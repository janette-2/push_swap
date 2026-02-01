/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:39:49 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/01 17:24:51 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* limits_check
Description: Function that detects, before converting the
string into an int, that the number is in between the valid
limits. This step is necessary because ft_atoi doesn't checks this.

Arguments: The cleaned string with the normlized numbers.

Returns: 1 or 0. Gives 1 if all of the elements are inside the limits,
gives you 0 if it doesn't.
*/

int	limits_check(char *normalized[])
{
	int	i;

	i = 0;
	while (normalized[i])
	{
		if (ft_strncmp("-2147483648", normalized[i], 11) < 0)
			return (0);
		if (ft_strncmp("2147483647", normalized[i], 11) > 0)
			return (0);
		i++;
	}
	return (1);
}

/* clear_filling_zeros 

Description: Function that returns the string normalized of an
element that is valid but has filling zeros.

Arguments: The original separated element in a string,
each index of the array args.

Returns: The value cleansed. Or NULL if there was an error
when creating the new string due to a limited capacity in the memory. 
*/
char	*clear_filling_zeros(char *args)
{
	char	*cleared;
	int		i;

	i = 0;
	cleared = malloc(ft_strlen(args) + 1);
	if (!cleared)
		return (NULL);
	if (args[i] == '-' || args[i] == '+')
	{
		cleared[i] = args[i];
		i++;
	}
	while (args[i] == '0')
		i++;
	while (args[i])
	{
		cleared[i] = args[i];
		i++;
	}
	cleared[i] = '\0';
	return (cleared);
}

/* numbers_conversion

Description: Function that transforms a number written with filling zeros
or with equivalents of zero into their simplified version.

Arguments: The *argv[] with all the elements already separated and validated.

Returns: A new array of strings with the conversions made.
If something fails returns NULL.
*/

char	**numbers_normalized(char *argv[])
{
	int		i;
	char	**normalized;

	normalized = argv;
	i = 0;
	while (argv[i])
	{
		if (zero_equivalents(argv[i]))
			normalized[i] = "0";
		else if (filling_zeros(argv[i]))
		{
			normalized[i] = clear_filling_zeros(argv[i]);
			if (!normalized[i])
			{
				free(normalized);
				return (NULL);
			}
		}
		else
			normalized[i] = argv[i];
		i++;
	}
	return (normalized);
}

/* have_duplicates

Description: Compares each element inside the converted array of 
strings to find duplicates.

Arguments: The converted array of strings with valid numbers,
valid signs and without filling zeros. Takes as granted that there 
is valid content. 

Returns: 1 or 0. Gives you 1 if there are duplicated elements.
Gives 0 if there are none.
*/

int	have_duplicates(char *normalized[])
{
	int	elements;
	int	i;
	int	j;

	elements = nbr_elements(normalized);
	i = 0;
	while (normalized[i + 1])
	{
		j = i + 1;
		while (j != elements)
		{
			if (ft_strncmp(normalized[i], normalized[j],
					ft_strlen(normalized[i])) != 0)
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

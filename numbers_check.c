/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:39:49 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/03 20:07:05 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* limits_check
Description: Function that detects, before converting the
string into an int, that the number is in between the valid
limits. This step is necessary because ft_atoi doesn't checks this.

Arguments: The cleaned string with the normlized numbers.

Returns: 1 or 0. Gives 1 if any of the elements is inside the limits,
gives you 0 if it doesn't.
*/

int	limits_check(int *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (nbr_cmp(-2147483648, array[i]) < 0)
			return (0);
		if (nbr_cmp(2147483647, array[i]) > 0)
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

int	have_duplicates(int *array)
{
	int	elements;
	int	i;
	int	j;

	elements = nbr_array(array);
	i = 0;
	while (array[i + 1])
	{
		j = i + 1;
		while (j != elements)
		{
			if (nbr_cmp(array[i], array[j]) != 0)
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}


/* nbr_cmp

Description: Function that compares between two number, 
gives a +int if the first one is bigger. An -int if the
first one is minor. Gives 0 if the numbers are equal.

Arguments: The numbers to be compared.

Returns: The difference between the two numbers compared.
*/

int	nbr_cmp(int n1, int n2)
{
	int	result;

	result = n1 - n2;
	return (result);
}

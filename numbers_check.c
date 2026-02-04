/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:39:49 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/04 23:56:29 by janrodri         ###   ########.fr       */
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

int	limits_check(t_stack *stack)
{
	long	value_copy;

	while (stack)
	{
		value_copy = stack->value;
		if ((value_copy >= -2147483648) && (value_copy <= 2147483647))
			stack = stack->next;
		else
			return (0);
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
	int		j;

	i = 0;
	j = 0;
	cleared = malloc(ft_strlen(args) + 1);
	if (!cleared)
		return (NULL);
	if (args[i] == '-' || args[i] == '+')
	{
		cleared[j++] = args[i++];
	}
	while (args[i] == '0')
		i++;
	while (args[i])
	{
		cleared[j++] = args[i++];
	}
	cleared[j] = '\0';
	return (cleared);
}

/* numbers_conversion

Description: Function that transforms a number written with filling zeros
or with equivalents of zero into their simplified version.

Arguments: The *argv[] with all the elements already separated and validated.

Returns: A new array of strings with the conversions made.
If something fails returns NULL. THE ARRAY OF STRINGS NEEDS TO BE FREED IN MAIN()

** the "0" string, specified like that, is a .rodata (read only data)
and that makes it a non-freeable value. So, to make sure you create the 
space in memory assigned to that '0', so YOU CAN FREE IT LATER, just 
assing the string with ft_strdup always.
*/

char	**numbers_normalized(char *argv[])
{
	int		i;
	char	**normalized;

	normalized = (char **) malloc((nbr_elements(argv) + 1) * sizeof(char *));
	i = 0;
	while (argv[i])
	{
		if (zero_equivalents(argv[i]))
			normalized[i] = ft_strdup("0");
		else if (filling_zeros(argv[i]))
		{
			normalized[i] = clear_filling_zeros(argv[i]);
			if (!normalized[i])
			{
				free_string_array(&normalized);
				return (NULL);
			}
		}
		else
			normalized[i] = ft_strdup(argv[i]);
		i++;
	}
	normalized[i] = NULL;
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

ESTO QUE PASE A SER UNA COMPROBACIÓN SACANDO LOS VALORES YA METIDOS EN EL STACK A.
*/

void	have_duplicates(t_stack **stack)
{
	long	i;
	long	j;
	t_stack	*temp;
	t_stack	*next;

	temp = (*stack);
	while (temp)
	{
		i = temp->value;
		next = temp->next;
		while (next)
		{
			j = next->value;
			if (nbr_cmp(i, j) != 0)
				next = next->next;
			else
				clean_error(stack, NULL, NULL);
		}
		temp = temp->next;
	}
}


/* nbr_cmp

Description: Function that compares between two numbers, 
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

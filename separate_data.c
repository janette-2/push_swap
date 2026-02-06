/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:33:12 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/06 22:31:42 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* several_in_string

Description: Function to detect if the values given are isolated numbers in each 
string or it is an string starting with "x y  z" that contains several numbers.
To do so, it checks if there are arguments separatedby spaces in the string. 

Arguments: The function analyses an *argv[x] (pointer) 
extracted from the main().

Returns: 1 or 0. 
If the function returns 1, it means that the data found is a single number.
If it is 0, it means that the value given is a block of numbers in a string.  

*/

int	several_in_string(char *argv)
{
	if (ft_memchr(argv, ' ', ft_strlen(argv)))
		return (1);
	else
		return (0);
}

/* separated_argv

Description: Function that separates the elements grouped
in a string from argv[]. ft_split uses malloc, so content needs 
to be freed.

Arguments: A single element of a string from the list of argv[] given

Returns: The list of elements(strings) inside the original string 

Leaks: This function calls ft_split which is dragging mallocs for 
the array of strings and the strings inside of it. So, after obtaining
the desired info, the final array of strings needs to be freed.
*/

char	**separated_argv(char *argv)
{
	char	**separated_argv;

	separated_argv = ft_split(argv, ' ');
	return (separated_argv);
}


/* checking_entry

Description: Function that detects one by one, if each argument is valid.
If the signs are valid, the range is inside the limits, and there are no 
weird characters, it would be valid.

Arguments: The single elements passed by arguments, already separated.

Returns: 1 or 0. It returns 1 if it is valid.
It returns 0 if the argument is invalid.

Leaks: Warning, in this case, the function receives an array
of strings that drags the final free after completing its purpose.
In this case, this array of strings is not being manipulated, plus,
the purpose of this array is not fulfilled at this point. So, as 
this array only has a function of being read only, and this array will 
continue to be used after check_entry, DON'T FREE THE ARRAY OF STRINGS HERE.*/

int	check_entry(char *args[])
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (not_digits(args[i]) || !valid_sign(args[i]))
			return (0);
		i++;
	}
	return (1);
}


/* nbr_elements

Description: Function that counts the total of elements given in argv,
whether they have been put in strings or on each own. Skips the first element
of argv[0], the title of the executable program.

Arguments: The original list of arguments

Returns: The number of total elements counted
*/


int	nbr_elements(char *argv[])
{
	int		count;
	int		i;
	int		j;
	char	**to_separate;

	count = 0;
	i = 0;
	while (argv[i])
	{
		if (several_in_string(argv[i]))
		{
			to_separate = separated_argv(argv[i]);
			j = 0;
			while (to_separate[j++])
				count++;
			free_string_array(&to_separate);
		}
		else
			count++;
		i++;
	}
	return (count);
}

/* new_argv

Description: Creation of a new list of strings with all the original arguments 
properly separated in single elements. Detects if a separation is needed and 
executes it. If it is not needed, it just copies the original argument.

Arguments: The original argv[]

Returns: A new list with the elements in single indexes.

Leaks: 
The functions that calls new_argv need to manage the mallocs created for this 
new array of strings, as well as the strings inside of it. So, take into
account that new_argv needs to be freed after stopped being used.

This function also calls separated_argv <- ft_split, which is dragging mallocs
for the array of strings and the strings inside of it created with ft_split.
So, after obtaining the desired info, and stopping on dragging the 
transformations of this array of strings, the final array and its content
needs to be freed.

** The new array of strings will copy total - 1 elements from argv,
because argv includes the name of the program. So to calculate the number
of element, we pass the array argv moved by 1 position (argv++) */

char	**new_argv(char *argv[])
{
	char	**new;
	char	**to_separate;
	int		i;
	int		j;
	int		k;

	new = (char **)malloc((nbr_elements(argv++) + 1) * sizeof(char *));
	i = 0;
	k = 0;
	while (argv[i])
	{
		if (several_in_string(argv[i]))
		{
			to_separate = separated_argv(argv[i]);
			j = 0;
			while (to_separate[j])
				new[k++] = ft_strdup(to_separate[j++]);
			free_string_array(&to_separate);
			i++;
		}
		else
			new[k++] = ft_strdup(argv[i++]);
	}
	new[k] = NULL;
	return (new);
}


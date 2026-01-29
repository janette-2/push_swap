/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:33:12 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/29 19:15:35 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

Description:

Arguments:

Returns:
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

Arguments: The single elements passed by arguments, already separated if needed.

Returns: 1 or 0. It returns 1 if it is valid.
It returns 0 if the argument is invalid.*/

int	check_entry(char *argv)
{
	if (not_digits(argv) || !valid_sign(argv))
		return (0);
	return (1);
}


/* nbr_elements

Description:

Arguments:

Returns:*/


int	nbr_elements(char *argv[])
{
	int		count;
	int		i;
	int		j;
	char	**to_separate;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (several_in_string(argv[i]))
		{
			to_separate = separated_argv(argv[i]);
			j = 0;
			while (to_separate[j++])
				count++;
		}
		else
			count++;
		i++;
	}
	return (count);
}

/* new_argv

Description:

Arguments:

Returns:*/

char	**new_argv(char *argv[])
{
	char	**new;
	char	**to_separate;
	int		i;
	int		j;
	int		k;

	new = (char **)malloc((nbr_elements(argv) + 1) * sizeof(char *));
	i = 1;
	k = 0;
	while (argv[i])
	{
		if (several_in_string(argv[i]))
		{
			to_separate = separated_argv(argv[i]);
			j = 0;
			while (to_separate[j])
				new[k++] = to_separate[j++];
			i++;
		}
		else
			new[k++] = argv[i++];
	}
	new[k] = NULL;
	return (new);
}


/* PROCEDIMIENTO PARA DETECTAR DATOS ERRÓNEOS:

En vez de hacer dobles punteros y tenerlo todo en este array de strings para luego meterlo
todo en el stack, vamos a ir directamente metiendo datos en el stack de una,

Para ello, tenemos que idear una función que para cada argumento obtenido nos analice 
primero si es un dato válido. Si lo es, ya lo convertimos a int, a su equivalente si 
es un cero a normalizar, y lo metemos en el stack. 

Si detectamos que no es válido, podemos ya salir de la ejecución.*/


// REVISAR LUEGO EN TODO LA CONDICIÓN DE SI LE METES UN DATO INVÁLIDO

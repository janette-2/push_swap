/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:15:23 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/18 18:47:23 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_single_number

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

/* is_sign

Description: Function that detects if the text found starts with a valid single 
sign. Either '-' or '+'. These can only be found once.

Arguments: Takes an *argv[], one of the strings given by arguments to main().

Returns: 1 or 0.
If the function returns 1, it would mean that it has detected that the elements
starts by a single sign and has a number after it.
It it returns 0, it would mean that we have one of these invalid cases:
+, -, ++1, +-0, ---0a, -15+6 */

int	valid_sign(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i + 1])
	{
		i++;
		while (ft_isdigit(argv[i]))
		{
			i++;
			if (argv[i] == '\0')
				return (1);
		}
	}
	return (0);
}


/* zero_equivalents

Description: Function that detects all the different variations of zero,
which are: 0, -0, +0, 000, -000000, +00000000.

Arguments: */

// LIBFT: Añadir ft_memchr y ft_strlen


// SHROTCUT COMMENTS: Truco para comentar una única linea 
// (o selección de varias): presionar ctrl +k y ctrl + c 
// Para descomentar sería ctrl + k y ctrl + u . 
// Para bloques también puede usar shift + alt + a

// FINAL *ARGV[]: Para identificar el final 
// de los argumentos que ha recopilado main *argv[]
// acaba siempre con NULL.

// BASH QUOTING: Ten en cuenta que cuando se pasa una string por *argv[] cuando
// vayas a leer el primer char de esa string, aunque se identifiquen con "" o ''
// estos se interpretan como caracteres especiales de especificación de formato.
// NO VERÁS COMO char[0] = " PORQUE ES UNA CONVERSIÓN INTRÍNSECA A 
// FORMATOS DE DATOS (ver en Quoting del man bash)
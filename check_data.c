/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:15:23 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/23 20:21:01 by janrodri         ###   ########.fr       */
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

/* valid_sign

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

Arguments: Takes an element from the arguments given by keyboard(*argv[]).
Taken as granted that each element is already separated.

Returns: 1 or 0.
If it returns 1, it means that the element found matches any of 
the variations of zero. If it returns 0, means that the element
found is not a zero.*/

int	zero_equivalents(char *argv)
{
	int	i;

	i = 0;
	if (valid_sign(argv))
		i++;
	while (argv[i] == '0')
		i++;
	if (!argv[i])
		return (1);
	return (0);
}

/* filling_zeros

Description: Function that jumps all the in between zeros that are not
interpreted followed by a valid number.

Arguments: Takes an element from the arguments given by keyboard(*argv[]).
Taken as granted that each element is already separated.

Returns: 1 or 0.
Gives you 1 if there is a valid number after all the preceding zeros found.
Gives you 0 if there is invalid data or an equivalent of zero.*/

int	filling_zeros(char *argv)
{
	int	i;

	i = 0;
	if (valid_sign(argv))
		i++;
	while (argv[i] == '0')
		i++;
	while (ft_isdigit(argv[i]))
		i++;
	if (argv[i] == '\0')
		return (1);
	return (0);
}

/* not_digits

Description: Function that, in the case of not having filling zeros, analyses if
there is a character that is not a number, being an invalid data.

Arguments: Takes an element from the arguments given by keyboard(*argv[]).
Taken as granted that each element is already separated.

Return: 1 or 0.
Gives you 1 if there is a character that is not a digit in the element.
For example: -+af20, 45o4, +55l6, ljlfd. Or if it has filling_zeros.
Gives you 0 if there all the characters are digits. */

int	not_digits(char *argv)
{
	int	i;

	i = 0;
	if (valid_sign(argv))
		i++;
	if (argv[i] != '0')
	{
		while (ft_isdigit(argv[i]))
			i++;
		if (argv[i] == '\0')
			return (0);
	}
	return (1);
}



//ANALIZAR EL CASO EN EL QUE TE PASEN UN ÚNICO NÚMERO. QUÉ DEVUELVE?
//VER SI DEBERIA SER ROBUSTO CON RESPECTO A LOS FILLING_ZEROS ESTE TAMBIÉN



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
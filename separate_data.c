/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:33:12 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/23 19:51:12 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

Arguments: The single elements passed by arguments.

Returns: 1 or 0. It returns 1 if it is valid.
It returns 0 if the argument is invalid.*/

int	check_entry(char *argv)
{
	if (not_digits(argv) || !valid_sign(argv))
		return (0);
	return (1);
}



/* PROCEDIMIENTO PARA DETECTAR DATOS ERRÓNEOS:

En vez de hacer dobles punteros y tenerlo todo en este array de strings para luego meterlo
todo en el stack, vamos a ir directamente metiendo datos en el stack de una,

Para ello, tenemos que idear una función que para cada argumento obtenido nos analice 
primero si es un dato válido. Si lo es, ya lo convertimos a int, a su equivalente si 
es un cero a normalizar, y lo metemos en el stack. 

Si detectamos que no es válido, podemos ya salir de la ejecución.*/

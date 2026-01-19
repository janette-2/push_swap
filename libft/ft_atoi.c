/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:57:07 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/22 16:29:31 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Converts a char 'number' into an int number. It skips blank spaces, 
reads only one sign -/+ and converts the first number it finds.
If different letters appear after the number they are ingnored 
ex:(  -153nk) -> '-153'.
If they are found before the number (  +a412), it returns 0. 
Returns the string turned into a number if processed correctly. */
int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	result;

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
/*
#include<stdio.h>
int main (void)
{
	char str[] = "   -0123456vvvv"; 
	printf("%d\n", ft_atoi(str));
}

Ejemplos para entender el funcionamiento de la funcion original:
atoi("   42abc")     → 42  (espacios al inicio → bien)
atoi("+123")         → 123
atoi("-7test")       → -7
atoi("abc123")       → 0  ← empieza por letra
atoi("!42")          → 0  ← empieza por símbolo no válido
atoi("  +--42")      → 0   ← signos mal puestos
LOS 0 EQUIVALEN A 'NULL' O MAL USO DE LA FUNCIÓN.
 
Cuando se usa isspace, se considera que todos estos caracteres se consideran
  espacios: ' ' y los ascii del 9 al 13, inclusives.
 */
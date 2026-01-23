/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:35:14 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/23 19:51:00 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include "libft/libft.h"

int	main(int argc, char *argv[])
{
	//int		n_digit;
	char	**args;
	int		i;

	if (argc == 1)
		return (0);
	//n_digit = not_digits(argv[1]);
	args = separated_argv(argv[1]);
	i = 0;
	while (args[i])
		printf("Elemento: \n%s\n", args[i++]);
	// printf("Es un que contiene no-digitos?\n%d\n", n_digit);
	printf("MINIMO: %d\n", INT_MIN);
	printf("MAXIMO: %d\n", INT_MAX);

	i = 1;
	while (argv[i])
	{
		if (!check_entry(argv[i]))
		{
			clear_stack(stack_a);
			clear_stack(stack_b);
			exit(1); //o return??
		}
		i++;
	}
}
/* Como es un programa, cada vez que haces algún cambio, tienes
que volver a compilar el archivo (para pruebas sin el Makefile) y
después de hacerle cc [ddd.c] lo ejecutas con: ./a.out [datos] */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:35:14 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/19 00:14:07 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**new;
	char	**normalized;

	stack_a = NULL;
	stack_b = NULL;
	new = NULL;
	normalized = NULL;
	if (argc < 2)
		return (0);
	if (empty_argv(argv))
		clean_error(NULL, NULL, NULL);
	new = new_argv(argv);
	if (!new)
		return (free_string_array(&new), 0);
	if (check_entry(new) == 0)
		clean_error(NULL, NULL, &new);
	normalized = numbers_normalized(new);
	if (!normalized)
		return (free_string_array(&normalized), 0);
	if (!check_limits(normalized))
	{
		free_string_array(&new);
		free_string_array(&normalized);
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a = fill_stack(normalized);
	free_string_array(&new);
	free_string_array(&normalized);
	have_duplicates(&stack_a);
	fill_index(&stack_a);
	if (is_ordered(stack_a))
	{
		clear_stack(&stack_a);
		exit(1);
	}
	sort(&stack_a, &stack_b);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}


/* Como es un programa, cada vez que haces algún cambio, tienes
que volver a compilar el archivo (para pruebas sin el Makefile) y
después de hacerle cc [ddd.c] lo ejecutas con: ./a.out [datos] */
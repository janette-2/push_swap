/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:35:14 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/21 17:33:17 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stacks(t_stack **stack_a, t_stack **stack_b,
				char ***new, char ***normalized)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*new = NULL;
	*normalized = NULL;
}

static t_stack	*parse_input(int argc, char *argv[], char **new,
					char **normalized)
{
	t_stack	*stack_a;

	if (argc < 2 || empty_argv(argv))
		clean_error(NULL, NULL, NULL);
	new = new_argv(argv);
	if (!new || check_entry(new) == 0)
		clean_error(NULL, NULL, &new);
	normalized = numbers_normalized(new);
	if (!normalized || !check_limits(normalized))
	{
		free_string_array(&new);
		free_string_array(&normalized);
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_a = fill_stack(normalized);
	free_string_array(&new);
	free_string_array(&normalized);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**new;
	char	**normalized;

	init_stacks(&stack_a, &stack_b, &new, &normalized);
	stack_a = parse_input(argc, argv, new, normalized);
	have_duplicates(&stack_a);
	fill_index(&stack_a);
	if (is_ordered(stack_a))
		return (clear_stack(&stack_a), exit(0), 0);
	sort(&stack_a, &stack_b);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}

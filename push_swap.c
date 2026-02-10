/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:35:14 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/10 21:00:38 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack *temp;
	t_stack *temp1;
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
	printf("nbr_elements: %d\n", nbr_elements(new));
	normalized = numbers_normalized(new);
	printf("nbr_elements: %d\n", nbr_elements(normalized));
	if (!normalized)
		return (free_string_array(&normalized), 0);
	stack_a = fill_stack(normalized);
	free_string_array(&new);
	free_string_array(&normalized);
	have_duplicates(&stack_a);
	////TEST///
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	temp = stack_a;
	while (temp)
	{
		printf("Value A: %d\n", temp->value);
		temp = temp->next;
	}
	temp1 = stack_b;
	while (temp1)
	{
		printf("Value B: %d\n", temp1->value);
		temp1 = temp1->next;
	}
	//////////
	//-----------FINAL-------
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	//ADAPTAR A NUEVO NBR_CMP Y EL CLEAN_ERROR CON EL ARRAY
	// if (have_duplicates(array))
		// clean_error(&stack_a, &stack_b, &args);
	// stack_a = fill_stack(array);
	
	// //PROBAR LOS VALORES RECOGIDOS DENTRO DE LA LISTA DE STACK
	// temp = stack_a;
	// while (temp)
	// {
	// 	printf("Value: %d\n", temp->value);
	// 	temp = temp->next;
	// }
}


/* int	main(int argc, char *argv[])
{
	(void) argc;
	t_stack	*swap_a;

	swap_a = fill_stack(argv++);
	while (swap_a->next)
	{
		printf("Value: %d\n", swap_a->value);
		swap_a = swap_a->next;
	}
	return (0);
} */

/* Como es un programa, cada vez que haces algún cambio, tienes
que volver a compilar el archivo (para pruebas sin el Makefile) y
después de hacerle cc [ddd.c] lo ejecutas con: ./a.out [datos] */
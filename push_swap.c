/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:35:14 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/01 14:04:53 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	//int		i;

	if (argc == 1)
		return (0);
	args = new_argv(argv);
	if (!args)
		return (0);
	if (check_entry(args) == 0)
		clean_error(&stack_a, &stack_b, &args);
	args = numbers_conversion(args);
	if (have_duplicates(args))
		clean_error(&stack_a, &stack_b, &args);
	stack_a = fill_stack(args);

	//PROBAR LOS VALORES RECOGIDOS DENTRO DE LA LISTA DE STACK
	t_stack *temp;
	temp = stack_a;
	while (temp)
	{
		printf("Value: %d\n", temp->value);
		temp = temp->next;
	}
}





/* 
	//Primero separar en elementos separados o copiarlos si ya existen.
	args =  new_argv(argv);
	// Comprobar si los datos metidos tienen chars inválidos
	if (check_entry(args) == 0)
	{
		//CLEAN THE MEMORY USED / STACKS / CONTENT / args /
		// / memory and elements created in the program
		write(1, "Error\n", 6);
		exit(1); //Esto cierra streams (flujos de fd estandar y fd abiertos) 
		// y ejecuta atexit() si hay. Luego cierra programa.
	}
	//Tercero, comprobar si los numeros tras normalizarse se repiten
	args = numbers_conversion(args);
	if (have_duplicates(args))
	{
		//CLEAN THE MEMORY USED / STACKS / CONTENT / args /
		// / memory and elements created in the program
		write(1, "Error\n", 6);
		exit(1) //HACER FUNCIÓN DE INFO DE ERROR, LIMPIEZA Y SALIDA
	}
	
		
			 */


/* Como es un programa, cada vez que haces algún cambio, tienes
que volver a compilar el archivo (para pruebas sin el Makefile) y
después de hacerle cc [ddd.c] lo ejecutas con: ./a.out [datos] */
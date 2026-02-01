/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:00:44 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/01 15:15:11 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Check_Data */
int		valid_sign(char *argv);
int		zero_equivalents(char *argv);
int		filling_zeros(char *argv);
int		not_digits(char *argv);

/* Numbers_Check */
char	*clear_filling_zeros(char *args);
char	**numbers_normalized(char *args[]);
int		limits_check(char *normalized[]);
int		have_duplicates(char *conversion[]);

/* Separate_Data */
int		several_in_string(char *argv);
char	**separated_argv(char *argv);
int		check_entry(char *args[]);
int		nbr_elements(char *argv[]);
char	**new_argv(char *argv[]);

/* Stack */
t_stack	*stack_new(int value);
t_stack	*get_stack_bottom(t_stack *stack);
t_stack	*get_stack_before_bottom(t_stack *stack);
int		get_stack_size(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack *bottom);

/* Init (cambiar nombre aqui, en archivo y en Makefile) */
t_stack	*fill_stack(char *args[]);
void	clear_stack(t_stack **stack);

/* Utils */
void	clean_error(t_stack **stack_a, t_stack **stack_b, char ***args);


#endif
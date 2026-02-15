/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:00:44 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/15 01:18:49 by janrodri         ###   ########.fr       */
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
	struct s_stack	*next;
}	t_stack;

/* Check_Data */
int			empty_argv(char *argv[]);
int			valid_sign(char *argv);
int			zero_equivalents(char *argv);
int			filling_zeros(char *argv);
int			not_digits(char *argv);

/* Numbers_Check */
char		*clear_filling_zeros(char *new_args);
char		**numbers_normalized(char *args[]);
int			limits_check(t_stack *stack);
void		have_duplicates(t_stack **stack);
int			nbr_cmp(int n1, int n2);

/* Separate_Data */
int			several_in_string(char *argv);
char		**separated_argv(char *argv);
int			check_entry(char *args[]);
int			nbr_elements(char *argv[]);
char		**new_argv(char *argv[]);

/* Stack */
t_stack		*stack_new(int value);
t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
int			get_stack_size(t_stack *stack);
void		stack_add_bottom(t_stack **stack, t_stack *bottom);

/* Init (cambiar nombre aqui, en archivo y en Makefile) */
t_stack		*fill_stack(char **normalized);
void		clear_stack(t_stack **stack);
int			long_to_int_limits(char *normalized_element);
void		fill_index(t_stack **stack);

/* Utils */
void		clean_error(t_stack **stack_a, t_stack **stack_b, char ***args);
long int	ft_atol(const char *str);
void		free_string_array(char ***array);
int			assign_index(t_stack *stack_head, t_stack *stack_node);
int			chunks(int size_stack);

/* Movements */
void		swap(t_stack **stack);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		rotate(t_stack **stack);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate(t_stack **stack);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **origin, t_stack **destiny);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_b, t_stack **stack_a);

/* Sort_Chunks */
void		sorting_chunks(t_stack **stack_a, t_stack **stack_b, int chunks);
void		inside_chunk_range(t_stack **stack_a,
				t_stack **stack_b, int low, int chunks);
int			has_index_in_chunk(t_stack *stack_a, int low, int high);
int			high_index(int chunks, int size, int i);


#endif
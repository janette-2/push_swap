/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 21:00:44 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/19 19:34:45 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
//# include <limits.h>
# include <stdio.h>

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
int		several_in_string(char *argv);
int		valid_sign(char *argv);
int		zero_equivalents(char *argv);
int		filling_zeros(char *argv);
int		not_digits(char *argv);

/* Separate Data */

char	**separated_argv(char *argv);

/* Utils */

size_t	ft_strlen(const char *s);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_isdigit(int n);

#endif
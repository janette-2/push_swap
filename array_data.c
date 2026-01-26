/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:39:49 by janrodri          #+#    #+#             */
/*   Updated: 2026/01/26 20:54:10 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* nbr_elements

Description:

Arguments:

Returns:*/


int	nbr_elements(char *argv[])
{
	int		count;
	int		i;
	int		j;
	char	**to_separate;

	count = 0;
	i = 1;
	while (argv[i])
	{
		if (several_in_string(argv[i]))
		{
			to_separate = separated_argv(argv[i]);
			j = 0;
			while (to_separate[j++])
				count++;
		}
		else
			count++;
		i++;
	}
	return (count);
}

/* new_argv

Description:

Arguments:

Returns:*/

char	**new_argv(char *argv[])
{
	char	**new;
	char	**to_separate;
	int		i;
	int		j;
	int		k;

	new = (char **)malloc((nbr_elements(argv) + 1) * sizeof(char *));
	i = 1;
	k = 0;
	while (argv[i])
	{
		if (several_in_string(argv[i]))
		{
			to_separate = separated_argv(argv[i]);
			j = 0;
			while (to_separate[j])
				new[k++] = to_separate[j++];
			i++;
		}
		else
			new[k++] = argv[i++];
	}
	new[k] = NULL;
	return (new);
}



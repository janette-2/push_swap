/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:11:10 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/19 13:11:10 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count_nodes;
	t_list	*next_node;

	if (!lst)
		return (0);
	count_nodes = 1;
	next_node = lst->next;
	while (next_node != NULL)
	{
		count_nodes++;
		next_node = next_node->next;
	}
	return (count_nodes);
}

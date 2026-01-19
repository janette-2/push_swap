/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:58:34 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/19 16:58:34 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*mem_node;
	t_list	*temp;

	next_node = *lst;
	while (next_node != NULL)
	{
		del(next_node->content);
		next_node = next_node->next;
	}
	mem_node = *lst;
	while (mem_node)
	{
		temp = mem_node->next;
		free (mem_node);
		mem_node = temp;
	}
	*lst = NULL;
}

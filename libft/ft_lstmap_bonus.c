/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:49:47 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/20 18:49:47 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* ORIGINAL FUNCTION:
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
} */
//FUNCTION PROTECTING THAT new_content IS NOT NULL, IF SO RETURNS NULL
static t_list	*clear_node(t_list *new_list, void *new_content,
	void (*del)(void *))
{
	del(new_content);
	ft_lstclear(&new_list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (clear_node(new_list, new_content, del));
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (clear_node(new_list, new_content, del));
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/* static void	*f_toupper(void *s)
{
	unsigned int	i;
	char			*string;
	char			*upper;

	string = (char *)s;
	upper = malloc(ft_strlen(string) + 1);
	i = 0;
	while (i < ft_strlen(string) + 1)
	{
		upper[i] = ft_toupper(string[i]);
		i++;
	}
	upper[i] = '\0';
	return (upper);
}
// Deletes the structure not the content itself.

void	delete_node(void *node)
{
	free(node);
	return ;
}
#include <stdio.h>
int main(void)
{
	t_list	*head;
	t_list	*tail;
	t_list	*result;
	char string1[] = "hola";
	char string2[] = "adios";

	head = ft_lstnew((void *)string1);
	tail = ft_lstnew((void *)string2);
	ft_lstadd_back(&head, tail);
	result = ft_lstmap(head, &f_toupper, &delete_node);
	while (result)
	{
		printf("%s\n", (char *)result->content);
		result = result->next;
	}
	return (0);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:37:54 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/10 12:46:31 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Search the  n bytes from *s to find char c.
If found returns it's memory direction. Else, NULL*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	size_t			i;
	unsigned char	car;

	source = (unsigned char *)s;
	car = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (source[i] == car)
			return (&source[i]);
		i++;
	}
	source = NULL;
	return (source);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char source[] = "abcdefghij";
	printf("Result: %p\n",ft_memchr(source, 'd', 2));
	printf("Result: %p\n",memchr(source, 'd', 2));
}
*/
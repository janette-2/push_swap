/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:38:20 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/05 16:38:20 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* if ((char) c =='\0') 
//After arriving at the end, if you are searching '\0' */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char) c == '\0')
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	char str[] = "abcdef";
	printf("Result: %p\n", ft_strchr(str, '\0'));
	printf("Result: %p\n", strchr(str, '\0'));
	return (0);
}
*/
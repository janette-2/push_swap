/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:38:26 by janrodri          #+#    #+#             */
/*   Updated: 2026/02/05 23:29:05 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* LEAKS --------
The function that calls ft_strdup needs to free, after obtaining the 
desired data, the string created by this function.*/

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*src;
	int		i;

	src = (char *) s;
	dup = malloc(ft_strlen(src) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[] = "1234567890";
	printf("Duplicate: %s\n", ft_strdup(s));
	printf("Duplicate -original-: %s\n", strdup(s));
}
*/
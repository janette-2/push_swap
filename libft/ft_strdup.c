/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:38:26 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/22 18:19:43 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
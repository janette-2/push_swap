/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:38:56 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/05 16:38:56 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// The strings must have at least n elements, though not checked. 
// Returns int positive if s1>, int negative if s2> and 0 if s1==s2
// while(src1[i] && (i < n)) 
//As longs as there is readable chars and not arrived to n...
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;
	size_t			i;

	src1 = (unsigned char *) s1;
	src2 = (unsigned char *) s2;
	i = 0;
	while (src1[i] && (i < n))
	{
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
		i++;
	}
	if ((src1[i] == '\0' && src2[i] != '\0' && i < n))
		return (-src2[i]);
	if ((src2[i] == '\0' && src1[i] != '\0' && i < n))
		return (src1[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[] = "12345"; //len = 6
	char s2[] = "12645"; //len = 6
	printf("Result: %d\n", ft_strncmp(s1,s2, 3));
	printf("Result -original-: %d\n", strncmp(s1,s2, 3));
}
*/
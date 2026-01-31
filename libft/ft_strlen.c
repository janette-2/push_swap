/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:38:50 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/05 16:38:50 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Counts without taking into account the '\0' char.
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
int main(void){
	char op1[] = "String"; //6
	printf("Lenght: %d\n", ft_strlen(op1)); 
	// %ld, It's not a normal integer, it takes more bytes(long)
	printf("Lenght -original-: %ld\n", strlen(op1));
	return (0);
}
*/

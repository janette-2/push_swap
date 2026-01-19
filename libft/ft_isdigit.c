/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janrodri <janrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 16:37:44 by janrodri          #+#    #+#             */
/*   Updated: 2025/10/09 00:33:04 by janrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/* 
Returns a +int if the char passed is a digit. 
Remember '5' is of type int. */
int	ft_isdigit(int n)
{
	if ('0' <= n && n <= '9')
		return (n);
	return (0);
}

/*
 #include <stdio.h>
 int main(void){
	 printf("Result: %d\n", ft_isdigit('8'));
	 return(0);
 }
	 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:23:02 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/11 19:39:29 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int np;

	result = 0;
	np = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			np = np * -1;
		str++;
	}
	if (ft_isspace(*str) || !ft_isdigit(*str))
		return (0);
	else
	{
		while (ft_isdigit(*str))
		{
			result = result * 10;
			result = result + (*str - '0');
			str++;
		}
	}
	return (result * np);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:36:59 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/10 17:55:41 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr_str;
	char	to_find;

	ptr_str = str;
	to_find = (char)c;
	while (*ptr_str)
	{
		if (*ptr_str == to_find)
			return (ptr_str);
		else
			ptr_str++;
	}
	return (NULL);
}

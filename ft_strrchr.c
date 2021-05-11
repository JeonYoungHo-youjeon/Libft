/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:00:47 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/11 17:52:20 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr_str;
	char	to_find;
	int		i;

	ptr_str = str;
	to_find = (char)c;
	i = 0;
	while (*ptr_str++)
		i++;
	while (i-- > 0)
	{
		if (*ptr_str == to_find)
			return (ptr_str);
		else
			ptr_str--;
	}
	return (NULL);
}

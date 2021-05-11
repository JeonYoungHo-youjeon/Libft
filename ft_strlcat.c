/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:54:38 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/10 17:06:31 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	total_len;

	total_len = 0;
	while (*dest && total_len < len)
	{
		dest++;
		total_len++;
	}
	while (*src && total_len < len - 1)
	{
		*dest = *src;
		dest++;
		src++;
		total_len++;
	}
	*dest = '\0';
	while (*src)
	{
		src++;
		total_len++;
	}
	return (total_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:25:59 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/11 15:41:27 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	src_len;
	int		i;

	src_len = 0;
	i = 0;
	while (i < len)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
		src_len++;
	}
	*dst = '\0';
	while (*src)
	{
		src++;
		src_len++;
	}
	return (src_len);
}

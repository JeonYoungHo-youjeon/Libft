/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:29:05 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/10 15:46:17 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ptr_arr;
	unsigned char	find_c;
	int				i;

	ptr_arr = arr;
	find_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr_arr = c)
			return (ptr_arr);
		ptr_arr++;
		i++;
	}
	return (NULL);
}

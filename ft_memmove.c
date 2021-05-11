/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:53:17 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/11 14:43:37 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	int				i;

	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	if (ptr_src < ptr_dest)
		while (n - 1 <= i)
		{
			*ptr_dest = *ptr_src;
			ptr_dest++;
			ptr_src++;
			n--;
		}
	else
		while (i < n)
		{
			*ptr_dest = *ptr_src;
			ptr_dest++;
			ptr_src++;
			i++;
		}
	return (dest);
}

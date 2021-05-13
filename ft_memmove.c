/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:53:17 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/13 18:38:46 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char*)dest;
	ptr_src = (unsigned char*)src;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:27:45 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/11 11:32:40 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	int				i;

	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	while (i < n)
	{
		*ptr_dest = *ptr_src;
		if (*ptr_dest = (unsigned char)c)
			return (ptr_dest++);
		ptr_dest++;
		ptr_src++;
		i++;
	}
	return (NULL);
}

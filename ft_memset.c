/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:44:55 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/10 11:30:17 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	*ptr_dest;
	unsigned char	trans_c;
	int				i;

	ptr_dest = dest;
	trans_c = c;
	i = 0;
	while (i < len)
	{
		*ptr_dest = trans_c;
		ptr_dest++;
		i++;
	}
	return (dest);
}

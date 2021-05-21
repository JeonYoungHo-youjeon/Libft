/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:45:39 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/21 18:43:11 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*new_mem;
	size_t	length;

	length = size * n;
	if (length / n != size || length % size != 0)
		return (NULL);
	if (!(new_mem = malloc(length)))
		return (NULL);
	ft_bzero(new_mem, length);
	return (new_mem);
}

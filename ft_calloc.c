/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:45:39 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/13 18:08:50 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*new_mem;

	if (!(new_mem = malloc(size * n)))
		return (NULL);
	ft_bzero(new_mem, n * size);
	return (new_mem);
}

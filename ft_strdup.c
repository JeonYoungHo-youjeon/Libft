/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:40:22 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/13 14:46:50 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_mem;
	int		size;

	size = ft_strlen(s);
	if (!(new_mem = malloc(size)))
		return (NULL);
	ft_strlcpy(new_mem, s, size);
	return (new_mem);
}

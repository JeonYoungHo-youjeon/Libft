/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:58:08 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/11 18:55:16 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*ptr_s1;
	size_t	i;

	ptr_s1 = s1;
	i = 0;
	if (*s2 == NULL)
		return (NULL);
	while (i < n)
	{
		if (ft_strncmp(s1[i], s2, ft_strlen(s2)) == 0)
		{
			return (ptr_s1);
		}
		ptr_s1++;
		i++;
	}
	return (NULL);
}

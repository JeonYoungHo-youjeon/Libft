/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjeon <youjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:51:39 by youjeon           #+#    #+#             */
/*   Updated: 2021/05/20 18:08:35 by youjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_mem;

	if (!(new_mem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_mem->content = content;
	new_mem->next = NULL;
	return (new_mem);
}

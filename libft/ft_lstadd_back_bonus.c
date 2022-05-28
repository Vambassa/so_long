/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:55:49 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/09 13:55:50 by vambassa         ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*b_list;

	if (lst)
	{
		if (*lst)
		{
			b_list = ft_lstlast(*lst);
			b_list->next = new;
		}
		else
			*lst = new;
	}
}

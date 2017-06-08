/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:52:59 by lbrugero          #+#    #+#             */
/*   Updated: 2017/01/11 13:53:00 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstreverse(t_list **list)
{
	t_list		*new_list;
	t_list		*new;
	t_list		*tmp;

	new_list = NULL;
	tmp = *list;
	while (tmp)
	{
		if (!(new = ft_lstnew(tmp->content, sizeof(tmp->content))))
			exit(EXIT_FAILURE);
		new->content = tmp->content;
		new->content_size = tmp->content_size;
		ft_lstadd(&new_list, new);
		free(tmp);
		tmp = tmp->next;
	}
	*list = new_list;
	return (*list);
}

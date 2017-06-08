/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:09:49 by lbrugero          #+#    #+#             */
/*   Updated: 2017/01/10 12:09:51 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsort(t_list *list, int (*sort)(t_list *first, t_list *second))
{
	t_list	*tmp;
	int		changed;

	tmp = list;
	changed = 0;
	while (tmp && tmp->next)
	{
		if (sort(tmp, tmp->next))
			changed = 1;
		tmp = tmp->next;
	}
	if (changed)
		ft_lstsort(list, sort);
	return (list);
}

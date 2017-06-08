/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:14:52 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/12 09:32:02 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first_elem;
	t_list	*tmp_new;

	first_elem = 0;
	while (lst != NULL)
	{
		if (first_elem == NULL)
		{
			tmp_new = f(lst);
			first_elem = tmp_new;
		}
		else
		{
			tmp_new->next = f(lst);
			tmp_new = tmp_new->next;
		}
		lst = lst->next;
	}
	return (first_elem);
}

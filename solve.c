/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:38:11 by lbrugero          #+#    #+#             */
/*   Updated: 2017/03/15 17:38:12 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_salle		*find(t_data *data, int special)
{
	t_list	*lst;

	lst = data->salles;
	while (lst)
	{
		if (((t_salle*)lst->content)->special & special)
			return ((t_salle*)lst->content);
		lst = lst->next;
	}
	return (NULL);
}

void		salle_set_next(t_salle *end)
{
	t_salle	*tmp;

	tmp = end;
	while (tmp)
	{
		if (tmp->parent)
			((t_salle*)tmp->parent)->next = tmp;
		tmp = tmp->parent;
	}
}

static void	enqueue(t_data *data, t_list **queue, t_salle *salle)
{
	t_list *lst;

	lst = data->tubes;
	while (lst)
	{
		if (((t_tube*)lst->content)->salle[0] == salle
			&& !((t_salle*)((t_tube*)lst->content)->salle[1])->set)
		{
			((t_salle*)((t_tube*)lst->content)->salle[1])->set = 1;
			((t_salle*)((t_tube*)lst->content)->salle[1])->parent = salle;
			ft_lstadd(queue, ft_lstnew(((t_salle*)((t_tube*)lst->content)
				->salle[1]), 0));
		}
		else if (((t_tube*)lst->content)->salle[1] == salle
			&& !((t_salle*)((t_tube*)lst->content)->salle[0])->set)
		{
			((t_salle*)((t_tube*)lst->content)->salle[0])->set = 1;
			((t_salle*)((t_tube*)lst->content)->salle[0])->parent = salle;
			ft_lstadd(queue, ft_lstnew(((t_salle*)((t_tube*)lst->content)
				->salle[0]), 0));
		}
		lst = lst->next;
	}
}

t_salle		*breadth_first_search(t_data *data, t_salle *root)
{
	t_list	*queue;
	t_list	*current_list;
	t_salle	*current_salle;

	if (!root)
		return (NULL);
	queue = NULL;
	root->set = 1;
	enqueue(data, &queue, root);
	while (queue)
	{
		current_list = ft_lstdefile(&queue, lstdel_void);
		current_salle = (t_salle*)current_list->content;
		if (current_salle->special & SALLE_END)
			return (current_salle);
		enqueue(data, &queue, current_salle);
	}
	return (NULL);
}

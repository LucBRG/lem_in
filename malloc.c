/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:10:55 by lbrugero          #+#    #+#             */
/*   Updated: 2017/03/16 12:10:56 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_list		*create_salle(char *name, int x, int y, int special)
{
	t_salle	*salle;
	t_list	*list;

	salle = (t_salle*)malloc(sizeof(*salle));
	if (!salle)
		exit(EXIT_FAILURE);
	salle->name = name;
	salle->coord_x = x;
	salle->coord_y = y;
	salle->special = special;
	salle->set = 0;
	salle->parent = NULL;
	salle->next = NULL;
	salle->last_action = -1;
	list = ft_lstnew(salle, sizeof(salle));
	if (!list)
		exit(EXIT_FAILURE);
	return (list);
}

t_list		*create_tube(t_salle *salle1, t_salle *salle2)
{
	t_tube	*tube;
	t_list	*list;

	tube = (t_tube*)malloc(sizeof(*tube));
	if (!tube)
		exit(EXIT_FAILURE);
	tube->salle[0] = salle1;
	tube->salle[1] = salle2;
	list = ft_lstnew(tube, sizeof(tube));
	if (!list)
		exit(EXIT_FAILURE);
	return (list);
}

t_fourmis	*create_fourmis(t_data *data, t_salle *start)
{
	t_fourmis	*fourmis;
	int			i;

	fourmis = (t_fourmis*)malloc(sizeof(*fourmis) * data->nb_fourmis);
	if (!fourmis)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < data->nb_fourmis)
	{
		fourmis[i].current_salle = start;
		fourmis[i].last_action = -1;
	}
	return (fourmis);
}

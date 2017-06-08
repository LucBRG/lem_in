/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:57:55 by lbrugero          #+#    #+#             */
/*   Updated: 2017/03/13 16:57:56 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_data	*lemin_init(void)
{
	t_data *data;

	data = (t_data*)malloc(sizeof(*data));
	if (!data)
		exit(EXIT_FAILURE);
	data->salles = NULL;
	data->tubes = NULL;
	return (data);
}

static void		lem_in_print(t_data *data, t_fourmis *fourmis, int action)
{
	int	i;

	i = -1;
	ft_putchar('\n');
	while (++i < data->nb_fourmis)
	{
		if (action == fourmis[i].last_action)
		{
			ft_putchar('L');
			ft_putnbr(i + 1);
			ft_putchar('-');
			ft_putstr(((t_salle*)fourmis[i].current_salle)->name);
			ft_putchar(' ');
		}
	}
}

int				lem_in_fourmis(t_data *data, t_fourmis *fourmis, int action,
	t_salle *start)
{
	int		i;
	int		n;
	t_salle	*tmp;

	n = 0;
	i = -1;
	while (++i < data->nb_fourmis)
	{
		tmp = start;
		while (tmp && !(tmp->special & SALLE_END))
		{
			if (!(tmp->special & SALLE_END) && tmp->last_action != action
				&& fourmis[i].current_salle == tmp
				&& fourmis[i].last_action != action)
			{
				n++;
				fourmis[i].current_salle = tmp->next;
				fourmis[i].last_action = action;
				tmp->last_action = action;
			}
			tmp = tmp->next;
		}
	}
	lem_in_print(data, fourmis, action);
	return (n);
}

void			lem_in(t_data *data, t_salle *start)
{
	t_fourmis	*fourmis;
	int			action;

	fourmis = create_fourmis(data, start);
	action = 0;
	while (lem_in_fourmis(data, fourmis, action, start))
		action++;
	free(fourmis);
}

int				main(void)
{
	t_data	*data;
	t_salle	*end;
	t_salle	*start;

	data = lemin_init();
	lemin_parsing(data);
	start = find(data, SALLE_START);
	end = breadth_first_search(data, start);
	if (!end)
		ft_putendl_fd("\nERROR", 2);
	else
	{
		salle_set_next(end);
		lem_in(data, start);
	}
	ft_lstdel(&data->salles, delete_salle);
	ft_lstdel(&data->tubes, delete_tube);
	free(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 13:11:29 by lbrugero          #+#    #+#             */
/*   Updated: 2017/06/14 10:02:19 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	parsing_nb_fourmis(t_data *data)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
	{
		ft_putendl_fd("ERROR", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strdigit(line) || (data->nb_fourmis = ft_atoi(line)) <= 0)
	{
		free(line);
		ft_putendl_fd("ERROR", 2);
		exit(EXIT_FAILURE);
	}
	free(line);
	ft_putnbr(data->nb_fourmis);
	ft_putchar('\n');
}

static int	parsing_all2(t_data *data, char *line, int *special, int *total_spe)
{
	static int is_tube;

	if (!ft_strncmp(line, "#", 1))
	{
		if (!parsing_special(line, special, total_spe, is_tube))
		{
			free(line);
			return (0);
		}
	}
	else if (!is_tube && !ft_strchr(line, '-'))
	{
		if (!ft_strncmp(line, "L", 1)
			|| !parsing_salle(data, line, special, total_spe))
			return (0);
	}
	else
	{
		check_door(*total_spe, is_tube);
		is_tube = 1;
		if (!parsing_tube(data, line))
			return (0);
	}
	return (1);
}

static void	parsing_all(t_data *data, int *total_spe)
{
	char	*line;
	int		special;

	special = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!parsing_all2(data, line, &special, total_spe))
			return ;
		ft_putendl(line);
		free(line);
	}
	check_door(*total_spe, 0);
}

int			salle_exist(t_data *data, char *name, int coord[2])
{
	t_list *lst;

	lst = data->salles;
	while (lst)
	{
		if (!ft_strcmp(((t_salle*)lst->content)->name, name)
			|| (((t_salle*)lst->content)->coord_x == coord[0]
			&& ((t_salle*)lst->content)->coord_y == coord[1]))
			return (1);
		lst = lst->next;
	}
	return (0);
}

void		lemin_parsing(t_data *data)
{
	int		total_spe;

	parsing_nb_fourmis(data);
	total_spe = 0;
	parsing_all(data, &total_spe);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:17:41 by lbrugero          #+#    #+#             */
/*   Updated: 2017/06/06 11:56:35 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	find_salle(t_data *data, char **names, t_salle **salle1,
	t_salle **salle2)
{
	t_list *lst;

	lst = data->salles;
	while (lst)
	{
		if (!ft_strcmp(((t_salle*)lst->content)->name, names[0]))
			*salle1 = lst->content;
		else if (!ft_strcmp(((t_salle*)lst->content)->name, names[1]))
			*salle2 = lst->content;
		lst = lst->next;
	}
	return (*salle1 && *salle2);
}

static int	tube_exist(t_data *data, char **name)
{
	t_list	*lst;
	char	*sname1;
	char	*sname2;
	int		i;

	i = 0;
	lst = data->tubes;
	while (lst)
	{
		sname1 = ((t_salle*)((t_tube*)lst->content)->salle[0])->name;
		sname2 = ((t_salle*)((t_tube*)lst->content)->salle[1])->name;
		if (!ft_strcmp(sname1, name[0]) && !ft_strcmp(sname2, name[1]))
			return (1);
		if (!ft_strcmp(sname2, name[0]) && !ft_strcmp(sname1, name[1]))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int			parsing_salle(t_data *data, char *line, int *special,
	int *total_spe)
{
	char	**split;
	int		coord[2];

	split = ft_strsplit(line, ' ');
	if (ft_strsplit_len(split) != 3 || ft_strlenchar(line, ' ') != 2
		|| !ft_strdigit(split[1]) || !ft_strdigit(split[2]))
	{
		free(line);
		return (0);
	}
	coord[0] = ft_atoi(split[1]);
	coord[1] = ft_atoi(split[2]);
	if (salle_exist(data, split[0], coord))
	{
		free(line);
		return (0);
	}
	ft_lstaddafter(&data->salles,
		create_salle(ft_strdup(split[0]), coord[0], coord[1], *special));
	ft_strsplit_free(split);
	*total_spe |= *special;
	*special = 0;
	return (1);
}

int			parsing_special(char *line, int *special, int *total_spe,
		int is_tube)
{
	if (!is_tube && !ft_strcmp(line + 1, "#start"))
	{
		if (*total_spe & SALLE_START || *special & SALLE_START)
			return (0);
		*special = SALLE_START;
	}
	else if (!is_tube && !ft_strcmp(line + 1, "#end"))
	{
		if (*total_spe & SALLE_END || *special & SALLE_END)
			return (0);
		*special = SALLE_END;
	}
	else
		return (-1);
	return (1);
}

int			parsing_tube(t_data *data, char *line)
{
	char	**split;
	t_salle	*salle1;
	t_salle	*salle2;

	salle1 = NULL;
	salle2 = NULL;
	split = ft_strsplit(line, '-');
	if (ft_strsplit_len(split) != 2 || ft_strlenchar(line, '-') != 1
		|| !ft_strcmp(split[0], split[1])
		|| !find_salle(data, split, &salle1, &salle2))
	{
		ft_strsplit_free(split);
		return (0);
	}
	else if (!tube_exist(data, split))
		ft_lstaddafter(&data->tubes, create_tube(salle1, salle2));
	ft_strsplit_free(split);
	return (1);
}

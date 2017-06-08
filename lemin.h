/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:57:51 by lbrugero          #+#    #+#             */
/*   Updated: 2017/06/06 11:48:48 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft/libft.h"
# include <stdlib.h>

# define SALLE_START 1
# define SALLE_END 2

typedef struct	s_data
{
	int			nb_fourmis;
	t_list		*salles;
	t_list		*tubes;
}				t_data;

typedef struct	s_salle
{
	char		*name;
	int			coord_x;
	int			coord_y;
	int			special;
	int			set;
	void		*parent;
	void		*next;
	int			last_action;
}				t_salle;

typedef struct	s_tube
{
	t_salle		*salle[2];
}				t_tube;

typedef struct	s_fourmis
{
	t_salle		*current_salle;
	int			last_action;
}				t_fourmis;

t_list			*create_salle(char *name, int x, int y, int special);
t_list			*create_tube(t_salle *salle1, t_salle *salle2);
t_fourmis		*create_fourmis(t_data *data, t_salle *start);

void			lstdel_void(void *a, size_t b);
void			delete_salle(void *salle, size_t size);
void			delete_tube(void *tube, size_t size);
void			lemin_parsing(t_data *data);
int				parsing_salle(t_data *data, char *line, int *special,
	int *total_spe);
int				parsing_tube(t_data *data, char *line);
int				parsing_special(char *line, int *special, int *total_spe,
		int is_tube);
void			salle_set_next(t_salle *end);
int				salle_exist(t_data *data, char *name, int coord[2]);
t_salle			*find(t_data *data, int special);
t_salle			*breadth_first_search(t_data *data, t_salle *root);

void			check_door(int total_spe, int is_tube);

#endif

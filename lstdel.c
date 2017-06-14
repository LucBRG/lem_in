/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:12:04 by lbrugero          #+#    #+#             */
/*   Updated: 2017/06/14 10:00:18 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		lstdel_void(void *a, size_t b)
{
	(void)(a && b);
}

void		delete_salle(void *salle, size_t size)
{
	free(((t_salle*)salle)->name);
	free(salle);
	(void)size;
}

void		delete_tube(void *tube, size_t size)
{
	free(tube);
	(void)size;
}

void		check_door(int total_spe, int is_tube)
{
	if (!is_tube)
	{
		if (!(total_spe & SALLE_START) || !(total_spe & SALLE_END))
		{
			ft_putendl_fd("ERROR", 2);
			exit(EXIT_FAILURE);
		}
	}
}

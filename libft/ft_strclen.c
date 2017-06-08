/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:12:05 by lbrugero          #+#    #+#             */
/*   Updated: 2017/01/23 10:12:06 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (!((*s >> 7) && !(*s >> 6 & 1)))
			i++;
		s++;
	}
	return (i);
}

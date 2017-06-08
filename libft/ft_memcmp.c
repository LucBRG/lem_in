/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:49:36 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 07:50:01 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if ((*(unsigned char *)(ptr1 + i)) != (*(unsigned char *)(ptr2 + i)))
			break ;
		i++;
	}
	if (i < len)
	{
		return ((*(unsigned char *)(ptr1 + i)) -
				(*(unsigned char *)(ptr2 + i)));
	}
	return ((*(unsigned char *)(ptr1 + i - 1)) -
			(*(unsigned char *)(ptr2 + i - 1)));
}

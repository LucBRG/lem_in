/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:46:01 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/14 10:58:47 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(len * sizeof(*tmp) + 1);
	if (tmp == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		*(char*)&tmp[i] = *(char*)&src[i];
	i = -1;
	while (++i < len)
		*(char*)&dst[i] = *(char*)&tmp[i];
	free(tmp);
	return (dst);
}

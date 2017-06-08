/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 07:58:23 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/08 07:58:26 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_i;
	size_t	dest_len;
	size_t	i;

	dest_i = ft_strlen(dst);
	dest_len = dest_i;
	if ((dest_len + 1) > size)
		return (ft_strlen(src) + size);
	i = -1;
	while (src[++i] != '\0')
	{
		if (dest_i >= (size - 1))
			break ;
		dst[dest_i++] = src[i];
	}
	dst[dest_i] = '\0';
	return (dest_len + (size_t)ft_strlen(src));
}

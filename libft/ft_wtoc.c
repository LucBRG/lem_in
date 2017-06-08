/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 14:10:19 by lbrugero          #+#    #+#             */
/*   Updated: 2017/01/20 14:10:20 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wtoc_second(wchar_t w, char *str, int i)
{
	if (w <= 0x7F)
		str[i++] = w;
	else if (w <= 0x7FF)
	{
		str[i++] = (w >> 6) + 0xC0;
		str[i++] = (w & 0x3F) + 0x80;
	}
	else if (w <= 0xFFFF)
	{
		str[i++] = (w >> 12) + 0xE0;
		str[i++] = ((w >> 6) & 0x3F) + 0x80;
		str[i++] = (w & 0x3F) + 0x80;
	}
	else if (w <= 0x1FFFFF)
	{
		str[i++] = (w >> 18) + 0xF0;
		str[i++] = ((w >> 12) & 0x3F) + 0x80;
		str[i++] = ((w >> 6) & 0x3F) + 0x80;
		str[i++] = (w & 0x3F) + 0x80;
	}
	return (i);
}

char		*ft_wtoc(wchar_t *w)
{
	char			*str;
	int				byte;
	size_t			i;

	if (!w)
		return (NULL);
	i = 0;
	byte = ft_strwoctet(w);
	if (!(str = (char*)malloc(byte + 1)))
		return (NULL);
	while (*w)
	{
		i = ft_wtoc_second(*w, str, i);
		w++;
	}
	str[i] = 0;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:57:10 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 07:57:12 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

wchar_t	*ft_strwdup(const wchar_t *src)
{
	wchar_t	*dest;
	int		i;

	i = 0;
	if (!(dest = (wchar_t*)malloc((ft_strwlen(src) + 1) * sizeof(*dest))))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

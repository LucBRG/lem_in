/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:05:24 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 10:05:26 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

wchar_t	*ft_strwjoin(wchar_t const *s1, wchar_t const *s2)
{
	wchar_t	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (wchar_t *)
		malloc((ft_strwlen(s1) + ft_strwlen(s2)) * sizeof(*str) + 1)))
		return (NULL);
	i = 0;
	while (*s1)
	{
		str[i++] = *s1;
		s1++;
	}
	while (*s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

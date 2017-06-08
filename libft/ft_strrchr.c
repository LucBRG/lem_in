/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:03:11 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 08:03:13 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last_result;

	last_result = 0;
	while (*s != '\0')
	{
		if (*s == c)
			last_result = (char *)(s);
		s++;
	}
	if (!c)
		return ((char *)(s));
	return (!last_result) ? (NULL) : (last_result);
}

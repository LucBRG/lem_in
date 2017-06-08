/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:38:02 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 07:38:08 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = -1;
	if (needle[0] == '\0')
		return (char *)(haystack);
	while (haystack[i] != '\0' && needle[j] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			start = (start != -1) ? start : i;
			j++;
		}
		else if (start != -1 && haystack[i] != needle[j])
		{
			i = start;
			start = -1;
			j = 0;
		}
		i++;
	}
	return (char *)((start == -1 || needle[j]) ? NULL : haystack + start);
}

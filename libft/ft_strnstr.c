/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:02:04 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/12 17:24:31 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	init_var(int *i, int *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = -1;
}

char			*ft_strnstr(const char *haystack, const char *needle,
	size_t len)
{
	int	i;
	int	j;
	int	start;

	init_var(&i, &j, &start);
	if (needle[0] == '\0')
		return (char *)(haystack);
	while (haystack[i] != '\0' && needle[j] != '\0')
	{
		if (i == (int)len)
			return (NULL);
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

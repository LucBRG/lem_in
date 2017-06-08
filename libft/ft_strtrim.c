/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:30:44 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 10:30:50 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_is_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
	{
		return (1);
	}
	return (0);
}

static void		count_white_space(char const *s, size_t len,
	size_t *nb_whitespace)
{
	size_t i;
	size_t after;
	size_t before;

	i = 0;
	before = 0;
	after = 0;
	while (s[i] != '\0' && ft_is_white_space(s[i]))
	{
		i++;
		before++;
	}
	i = len - 1;
	while (s[i] != '\0' && ft_is_white_space(s[i]))
	{
		i--;
		after++;
	}
	if (after == len && before == len)
		*nb_whitespace = 0;
	else
		*nb_whitespace = after + before;
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	nb_whitespace;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	count_white_space(s, len, &nb_whitespace);
	str = (char *)malloc((len - nb_whitespace) * sizeof(*str) + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	i = -1;
	while (s[++i] != '\0')
		if (!ft_is_white_space(s[i]))
			break ;
	while (s[i] != '\0' && j < (len - nb_whitespace))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

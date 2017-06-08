/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:31:34 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 11:31:37 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_args(char const *s, char c)
{
	size_t	count;
	int		word;

	count = 0;
	word = 0;
	while (*s != '\0')
	{
		if (!word && *s != c)
		{
			word = 1;
			count++;
		}
		else if (word && *s == c)
			word = 0;
		s++;
	}
	return (count);
}

static void		split_string(char const *s, char **tab, char *c)
{
	int		in_a_word;
	int		i;
	int		tab_i;

	in_a_word = -1;
	i = -1;
	tab_i = 0;
	while (s[++i] != '\0')
	{
		if (in_a_word == -1 && s[i] != *c)
			in_a_word = i;
		else if (in_a_word != -1 && s[i] == *c)
		{
			tab[tab_i++] = ft_strsub(s, in_a_word, (i - in_a_word));
			in_a_word = -1;
		}
		if (in_a_word != -1 && !s[i + 1])
		{
			tab[tab_i++] = ft_strsub(s, in_a_word, (i - in_a_word + 1));
			in_a_word = -1;
		}
	}
	tab[tab_i] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = count_args(s, c);
	tab = (char **)malloc((len + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	split_string(s, tab, &c);
	return (tab);
}

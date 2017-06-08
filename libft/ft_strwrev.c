/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:18:27 by lbrugero          #+#    #+#             */
/*   Updated: 2017/01/19 14:18:28 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_strwrev(wchar_t *str)
{
	wchar_t	swp;
	int		i;
	int		j;

	i = -1;
	j = ft_strwlen(str);
	while (++i < j--)
	{
		swp = str[i];
		str[i] = str[j];
		str[j] = swp;
	}
	return (str);
}

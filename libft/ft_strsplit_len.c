/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 15:31:04 by lbrugero          #+#    #+#             */
/*   Updated: 2017/03/14 15:31:05 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strsplit_len(char **str)
{
	int i;
	int n;

	if (!str)
		return (0);
	i = -1;
	n = 0;
	while (str[++i])
		++n;
	return (n);
}

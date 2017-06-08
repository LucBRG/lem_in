/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:27:42 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/04 16:27:44 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int n;
	int i;
	int neg;

	n = 0;
	i = 0;
	neg = 1;
	while (nptr[i] == ' ' || nptr[i] == '\a' || nptr[i] == '\b'
		|| nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	else if (nptr[i] == '+')
		neg = 1;
	else
		i--;
	while (nptr[++i] != '\0')
	{
		if (!ft_isdigit(nptr[i]))
			break ;
		n = n * 10 + (nptr[i] - '0');
	}
	return (n * neg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:19:39 by lbrugero          #+#    #+#             */
/*   Updated: 2017/01/12 13:19:40 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long int n, int count_sign)
{
	int	i;

	i = 1;
	if (n < 0 && count_sign)
		i++;
	while ((n /= 10))
	{
		i++;
		if (!n)
			break ;
	}
	return (i);
}

int		ft_nbrulen(unsigned long long int n)
{
	int	i;

	i = 1;
	while ((n /= 10))
	{
		i++;
		if (!n)
			break ;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 08:38:12 by lbrugero          #+#    #+#             */
/*   Updated: 2017/01/19 17:08:50 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char	*ft_itoa(long long n, int force_sign)
{
	long long			ncopy;
	unsigned long long	nb;
	char				*str;
	int					nlen;
	int					i;

	i = -1;
	ncopy = n;
	nb = (n < 0) ? -(unsigned long long int)n : (unsigned long long int)n;
	nlen = ft_nbrlen(n, 0);
	if (!(str = (char*)malloc(ft_nbrlen(n, 1) + (!!force_sign) + 1)))
		return (NULL);
	while (nlen--)
	{
		str[++i] = (nb % 10) + '0';
		nb /= 10;
	}
	if (ncopy < 0)
		str[++i] = '-';
	else if (ncopy >= 0 && force_sign)
		str[++i] = '+';
	str[++i] = 0;
	return (ft_strrev(str));
}

char	*ft_utoa(unsigned long long n)
{
	unsigned long long	ncopy;
	char				*str;
	int					nlen;
	int					i;

	i = -1;
	ncopy = n;
	nlen = ft_nbrulen(n);
	if (!(str = (char*)malloc(ft_nbrulen(n) + 1)))
		return (NULL);
	while (nlen--)
	{
		str[++i] = (n % 10) + '0';
		n /= 10;
	}
	str[++i] = 0;
	return (ft_strrev(str));
}

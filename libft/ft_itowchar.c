/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itowchar.c                                      :+:      :+:    :+:   */
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

wchar_t	*ft_itowchar(long long n, int force_sign)
{
	long long	ncopy;
	wchar_t		*str;
	int			nlen;
	int			i;

	nlen = ft_nbrlen(n, 0);
	if (!(str = (wchar_t*)
		malloc(sizeof(*str) * (ft_nbrlen(n, 1) + (!!force_sign) + 1))))
		return (NULL);
	i = -1;
	ncopy = n;
	if (n < 0)
		n = -n;
	while (nlen--)
	{
		str[++i] = (n % 10) + '0';
		n /= 10;
	}
	if (ncopy < 0)
		str[++i] = '-';
	else if (ncopy >= 0 && force_sign)
		str[++i] = '+';
	str[++i] = 0;
	return (ft_strwrev(str));
}

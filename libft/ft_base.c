/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:07:19 by lbrugero          #+#    #+#             */
/*   Updated: 2017/01/19 19:07:20 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_base(unsigned long long nb, int base, char *base_str)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(250 + 1))
		|| base < 2 || base > (int)ft_strlen(base_str))
		return (NULL);
	if (!nb)
		str[i++] = '0';
	while (nb > 0)
	{
		str[i++] = base_str[nb % base];
		nb /= base;
	}
	if (nb)
		str[i++] = base_str[0];
	str[i] = 0;
	return (ft_strrev(str));
}

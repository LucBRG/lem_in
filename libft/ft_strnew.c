/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:27:29 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 08:27:34 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	void *str;

	str = malloc(++size);
	if (str == NULL)
		return (NULL);
	while (size)
		*(unsigned char *)(str + --size) = 0;
	return (str);
}

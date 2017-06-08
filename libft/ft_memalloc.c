/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:09:04 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 08:09:45 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *result;

	result = malloc(size);
	if (result == NULL)
		return (NULL);
	while (size > 0)
		*(unsigned int *)(result + --size) = 0;
	return (result);
}

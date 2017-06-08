/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:58:23 by lbrugero          #+#    #+#             */
/*   Updated: 2016/11/07 07:58:26 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	dest_i;
	size_t	i;

	dest_i = ft_strlen(dest);
	i = -1;
	while (src[++i] != '\0' && i < n)
		dest[dest_i++] = src[i];
	dest[dest_i] = '\0';
	return (dest);
}

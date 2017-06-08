/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdefile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrugero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 09:13:11 by lbrugero          #+#    #+#             */
/*   Updated: 2017/03/16 09:13:12 by lbrugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdefile(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*final;

	if (!*alst)
		return (NULL);
	else if (!(*alst)->next)
	{
		final = *alst;
		ft_lstdelone(alst, del);
		return (final);
	}
	tmp = *alst;
	while (tmp->next->next)
		tmp = tmp->next;
	final = tmp->next;
	ft_lstdelone(&tmp->next, del);
	return (final);
}

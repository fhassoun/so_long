/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassoun <fhassoun@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:41:44 by fhassoun          #+#    #+#             */
/*   Updated: 2022/12/11 06:40:48 by fhassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **node, void (*del)(void*))
{
	t_list	*nextnode;

	while (node && *node)
	{
		nextnode = (*node)->next;
		ft_lstdelone(*node, del);
		*node = nextnode;
	}
	*node = NULL;
}

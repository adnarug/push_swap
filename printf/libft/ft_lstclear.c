/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:38:00 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/21 08:22:59 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (del)(int))
{
	t_list				*curr;
	t_list				*temp;

	curr = *lst;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr -> next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}

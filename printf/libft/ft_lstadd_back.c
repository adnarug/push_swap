/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:24:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/22 17:15:06 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new, int *counter)
{
	t_list				*last;

	if (lst == NULL)
		return (NULL);
	if (*lst == NULL)
	{
		*lst = new;
		return (NULL);
	}
	last = ft_lstlast(*lst);
	last->init_index = *counter;
	last -> next = new;
	return (last);
}
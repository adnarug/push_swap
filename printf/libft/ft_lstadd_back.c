/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:24:08 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/09 15:16:44 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back(t_list **lst, t_list *new)
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
	new	-> index = 0;

	last -> next = new;
	return (last);
}
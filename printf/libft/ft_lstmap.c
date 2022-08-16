/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:10:00 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/21 08:34:32 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (f)(int), int (*del)(int))
{
	t_list				*new_lst;
	t_list				*new_node;
	t_list				*curr;

	new_lst = NULL;
	curr = lst;
	while (curr != NULL)
	{
		new_node = ft_lstnew(f(curr->content));
		if (new_node != NULL)
			ft_lstadd_back(&new_lst, new_node);
		else
		{
			ft_lstclear (&new_lst, del);
			return (NULL);
		}
		curr = curr -> next;
	}
	return (new_lst);
}

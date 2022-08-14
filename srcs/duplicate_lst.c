/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplciate_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:37:33 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 18:38:41 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Duplicating relevant struct values*/
void	lst_copy_content(t_list **src, t_list **dst)
{
	(*dst)->content = (*src)->content;
	(*dst)->position = (*src)->position;
	(*dst)->index = (*src)->index;
	(*dst)->next = NULL;
}

/*Creating a duplciate linked list for sorting*/
t_list	*ft_lst_duplicate(t_list **a)
{
	t_list	*temp_a;
	t_list	*new_lst;
	t_list	*new_head;
	t_list	*new_node;

	temp_a = *a;
	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	lst_copy_content(&temp_a, &new_lst);
	new_head = new_lst;
	temp_a = temp_a->next;
	while (temp_a != NULL)
	{
		new_node = malloc(sizeof(t_list));
		lst_copy_content(&temp_a, &new_node);
		ft_lstadd_back(&new_lst, new_node);
		temp_a = temp_a->next;
		new_lst = new_lst->next;
	}
	give_index(&new_head);
	return (new_head);
}

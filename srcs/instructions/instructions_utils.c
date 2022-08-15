/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:07:53 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 15:02:40 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*Support function for instructions*/
t_list	*reassign_front_node(t_list **list)
{
	t_list	*head;

	if (list == NULL)
		return (NULL);
	head = *list;
	*list = head->next;
	return (head);
}

/*Support function for instructions*/
t_list	*reassign_back_node(t_list **list)
{
	t_list	*last;
	t_list	*head;

	head = *list;
	last = ft_lstlast(*list);
	last->next = head;
	while ((*list)->next != last)
		*list = (*list)->next;
	(*list)->next = NULL;
	head = last;
	return (head);
}

/*ss not used*/
void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
	write (1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:07:53 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 18:45:34 by pguranda         ###   ########.fr       */
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

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
	write (1, "ss\n", 3);
}

void	push_below_median(t_list **a, t_list **b, t_list *median, t_list *min)
{
	t_list	*temp;

	temp = *a;
	while (temp != NULL)
	{
		if (temp->position < median->position + 1 && \
		temp != min && temp != median)
		{
			move_from_a_to_b(a, b, temp);
			temp = *a;
		}
		else
			temp = temp->next;
	}
}

void	push_above_median(t_list **a, t_list **b, t_list *median, t_list *max)
{
	t_list	*temp;

	temp = *a;
	rrb(b);
	while (temp != NULL)
	{
		if (temp->position > median->position + 1 && temp != max)
		{
			move_from_a_to_b(a, b, temp);
			temp = *a;
		}
		else
			temp = temp->next;
	}
}

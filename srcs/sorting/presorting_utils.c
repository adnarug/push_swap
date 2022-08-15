/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:08:29 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 12:21:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*Swapping two nodes in the same list*/
t_list	*lst_swap(t_list **first, t_list **second)
{
	int	temp;

	temp = (*first)->content;
	(*first)->content = (*second)->content;
	(*second)->content = temp;
	return (*first);
}

/*Search by index*/
t_list	*search_midpoint(t_list **a)
{
	int		indexof_midpoint;
	t_list	*mid_point;
	t_list	*temp;

	temp = *a;
	indexof_midpoint = ft_lstsize(*a) / 2;
	while (temp != NULL)
	{
		if (temp->index == indexof_midpoint)
			mid_point = temp;
		temp = temp->next;
	}
	return (mid_point);
}

/* Finds greater values  to the left of the pivot*/
t_list	*scan_left(t_list **a, t_list *mid_point)
{
	t_list	*temp;

	temp = *a;
	while (temp != mid_point)
	{
		if (temp->content > mid_point->content)
			return (temp);
		temp = temp->next;
	}
	return (mid_point);
}

/* Finds greater values  to the right of the pivot*/
t_list	*scan_right(t_list *mid_point)
{
	t_list	*temp;

	temp = mid_point;
	while (temp != NULL)
	{
		if (temp->content < mid_point->content)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/*Moving the desired element from stack_a to stack_b*/
void	move_from_a_to_b(t_list **a, t_list **b, t_list *element)
{
	rotating_a(a, element);
	pb(a, b);
}

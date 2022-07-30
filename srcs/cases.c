/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:08:29 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/30 17:28:23 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// int	no_of_inputs(int *argc)
// {
// 	if (argc <= 5)
// 		return(1);
// 	else if (argc > 5 && argc <= 100)
// 		return(2);
// 	else if (argc > 100)
// 		return(3);
// }

void lst_swap(t_list **first, t_list **second)
{
	t_list	*temp_second;
	t_list	*temp_second_last;
	t_list	*temp_first;
	t_list	*temp_first_last;
	
	temp_first = *first;
	temp_second = *second;
	temp_first_last = (*first)->next;
	temp_second_last = (*second)->next;

	(*first)->previous->next = temp_second;
	(*first)->next = temp_first_last;
	temp_first_last->previous = (*first)->previous;
	//*temp_first = *temp_second;
	// (*first)->next = temp_first->next;

	(*second)->previous->next = temp_first;
	(*second)->next = temp_second_last;
	temp_second = temp_first;
// 	(*second)->previous->next = temp_first;
// 	(*second)->next = temp_second->next;
// // 	(*second)->previous = temp_second->previous;
}

// t_list *find_midpoint(t_list **a)
// {
// 	t_list	*mid_point;
// 	t_list	*temp;
// 	int		indexof_midpoint;

// 	temp = *a;
// 	indexof_midpoint = (*a)->total_count / 2;
// 	while (temp != NULL)
// 	{
// 		if (temp->index == indexof_midpoint)
// 			mid_point = temp;
// 		temp = temp->next;
// 	}
// 	return (mid_point);
// }

// void sorting_small(t_list **a, t_list **b)
// {
	
// }
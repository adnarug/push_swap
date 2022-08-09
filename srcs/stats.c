/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:41:17 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/08 19:42:42 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Search for the min algo; Indexes and translation of the indeces
t_list	*search_min(t_list **a)
{
	t_list	*min;
	t_list	*temp;
	
	min = *a;
	temp = *a;
	temp = temp->next;
	if ((*a)->total_count == 1)
		min = *a;
	while(temp != NULL && temp->total_count > 1)
	{
		if(min->content > temp->content)
			min = temp;
		else
			temp = temp->next;
	}
	printf("Min is %d \n", min->content);
	min -> min_flag = 1;
	return(min);
}

t_list *search_max(t_list **a)
{	
	t_list	*max;
	t_list	*temp;
	
	max = *a;
	temp = *a;
	temp = temp->next;
	if ((*a)->total_count == 1)
		max = *a;
	while(temp != NULL && temp->total_count > 1)
	{
		if(max->content < temp->content)
			max = temp;
		else
			temp = temp->next;
	}
	printf("Max is %d \n", max->content);
	return(max);
}

t_list *search_median(t_list **a)
{
	t_list *temp;

	temp = *a;
	while (temp->position != (ft_lstsize(*a))/2)
		temp = temp->next;
	printf("Median is %d \n", temp->content);
	return(temp);	
}
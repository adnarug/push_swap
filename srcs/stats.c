/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:41:17 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 19:37:03 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Find and return the min value in a stack*/
t_list	*search_min(t_list **a)
{
	t_list	*min;
	t_list	*temp;

	min = *a;
	temp = *a;
	temp = temp->next;
	while (temp != NULL)
	{
		if (min->content > temp->content)
			min = temp;
		else
			temp = temp->next;
	}
	return (min);
}

/*Find and return the max value in a stack*/
t_list	*search_max(t_list **a)
{	
	t_list	*max;
	t_list	*temp;

	max = *a;
	temp = *a;
	temp = temp->next;
	while (temp != NULL)
	{
		if (max->content < temp->content)
			max = temp;
		else
			temp = temp->next;
	}
	return (max);
}

/*Find and return the median value by position*/
t_list	*search_median(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while ((temp->position != (ft_lstsize(*a)) / 2) && temp != NULL)
		temp = temp->next;
	return (temp);
}

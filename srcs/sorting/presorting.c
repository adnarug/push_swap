/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:15:18 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 12:24:27 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*Check if the sorting is done i.e. no grater to the left and 
smaller to the right of pivot*/
static int	end_sorting(t_list **left_scan, t_list **right_scan, t_list **pivot)
{
	while (*left_scan == *pivot && *right_scan == NULL)
	{
		*pivot = (*pivot)->next;
		if (*pivot == NULL)
			return (1);
		*right_scan = scan_right(*pivot);
		*left_scan = *pivot;
	}
	return (0);
}

/*Checking for greater to the left of pivot and
smaller to the right of pivot, if found swapping, shifting the pivot*/
static t_list	*quicksort(t_list *presorted_a, t_list *pivot)
{
	t_list	*presorted_header;
	t_list	*left_scan_result;
	t_list	*right_scan_result;

	presorted_header = presorted_a;
	while (pivot != NULL)
	{
		left_scan_result = scan_left(&presorted_a, pivot);
		right_scan_result = scan_right(pivot);
		if (end_sorting(&left_scan_result, &right_scan_result, &pivot) == 1)
			return (presorted_header);
		if (left_scan_result != pivot && right_scan_result == NULL)
		{
			right_scan_result = pivot;
			lst_swap(&left_scan_result, &right_scan_result);
			pivot = left_scan_result;
		}
		else
			lst_swap(&left_scan_result, &right_scan_result);
	}
	return (presorted_header);
}

/*Carrying out quicksort with two pivtos: midpoint and min*/
t_list	*sorting(t_list **a)
{
	t_list	*min;
	t_list	*midpoint;
	t_list	*presorted;
	t_list	*final_sorted;

	presorted = ft_lst_duplicate(a);
	midpoint = search_midpoint(&presorted);
	presorted = quicksort(presorted, midpoint);
	min = search_min(&presorted);
	final_sorted = quicksort(presorted, min);
	return (final_sorted);
}

/*Giving each element in stack_a a position value 
(i.e. place in a sorted stack)*/
void	lst_indexing(t_list **a, t_list *presorted_a)
{
	t_list	*head_a;
	t_list	*head_presorted_a;

	head_a = *a;
	head_presorted_a = presorted_a;
	while (head_a != NULL)
	{
		if (head_a->content == head_presorted_a->content)
		{
			head_a->position = head_presorted_a->index;
			head_a = head_a->next;
			head_presorted_a = presorted_a;
		}
		else
			head_presorted_a = head_presorted_a->next;
	}
}

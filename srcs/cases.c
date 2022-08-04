/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:08:29 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/04 17:42:31 by pguranda         ###   ########.fr       */
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
//Swapping only the contents. What about positons?

static t_list *lst_swap(t_list **first, t_list **second)
{
	t_list	temp;
	
	temp = **first;
	(*first)->content = (*second)->content;
	(*second)->content = temp.content;
	return (*first);
}

static t_list *find_midpoint(t_list *a)
{
	t_list	*mid_point;
	t_list	*temp;
	int		indexof_midpoint;

	temp = a;
	indexof_midpoint = (a)->total_count / 2;
	while (temp != NULL)
	{
		if (temp->index == indexof_midpoint)
			mid_point = temp;
		temp = temp->next;
	}
	return (mid_point);
}

//Finds bigger to the left;
static t_list *scan_left(t_list **a, t_list *mid_point)
{
	t_list *temp;

	temp = *a;
	while(temp != mid_point)
	{
		if(temp->content > mid_point->content)
			return(temp);
		temp = temp->next;
	}
		return (mid_point);
}

//Finds smaller to the right
static t_list *scan_right(t_list **a, t_list *mid_point)
{
	t_list *temp;

	temp = mid_point;
	while (temp != NULL)
	{
		if (temp->content < mid_point->content)
			return (temp);
		temp = temp->next;
	}
		return(NULL);
}


static void	lst_copy_content(t_list **src, t_list **dst)
{
	(*dst)->content = (*src)->content;
	(*dst)->position = (*src)->position;
	(*dst)->index = (*src)->index;
	(*dst)->min_flag = (*src)->min_flag;
	(*dst)->total_count = (*src)->total_count;
	(*dst)->next = NULL;
	
}

static t_list	*ft_lst_duplicate(t_list **a)
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
		ft_lstadd_back(&new_lst, new_node, new_node->index);
		temp_a = temp_a->next;
		new_lst = new_lst->next;
	}
	new_lst = NULL;
	return (new_head);
}

t_list	*sorting(t_list **a)
{
	t_list	*mid_point;
	t_list	*presorted_a;
	t_list	*presorted_header;
	t_list	*left_scan_result;
	t_list	*right_scan_result;
	int i = 0;
	
	presorted_a = ft_lst_duplicate(a);
	presorted_header = presorted_a;
	mid_point = find_midpoint(presorted_a);
	while (mid_point != NULL)
	{
		printf("Mid point is: %d \n", mid_point->content);
		left_scan_result = scan_left(&presorted_a, mid_point);
		right_scan_result = scan_right(&presorted_a, mid_point);
		while(left_scan_result == mid_point && right_scan_result == NULL)
		{
			mid_point = mid_point->next;
			if (mid_point == NULL)
				return NULL;
			right_scan_result = scan_right(&presorted_a, mid_point);
			left_scan_result = mid_point;
		}
		if(left_scan_result != mid_point && right_scan_result == NULL)
		{
			right_scan_result = mid_point;
			mid_point = lst_swap(&left_scan_result, &right_scan_result);
		}
		else
			lst_swap(&left_scan_result, &right_scan_result);
		i++;
	}
	ft_print_lst_a(presorted_header);
	return(presorted_header);
}

// void assign_list(t_list **a, t_list **a_temp)
// {
// 	t_list temp1;
// 	t_list temp2;
// 	while (*a_temp != NULL)
// 	{
// 		while (*a != NULL)
// 		{
// 			*a 
// 		}
// 		*a_temp = a_temp->next; 
// 	}
// }

// void sorting_small(t_list **a, t_list **b)
// {
	
// }
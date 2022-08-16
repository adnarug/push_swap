/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:12:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 17:57:25 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Freeing the stack and all the elements in it.*/
void	ft_lst_free(t_list *lst)
{
	t_list	*pointer;

	pointer = NULL;
	while (lst != NULL)
	{
		pointer = lst->next;
		free(lst);
		lst = NULL;
		lst = pointer;
	}
	free (pointer);
	pointer = NULL;
}

/*Returning the node with a given position (i.e. its place in sorted stack)*/
t_list	*search_by_postion(t_list *stack, int position)
{
	t_list	*temp;

	temp = stack;
	while (temp != NULL)
	{
		if (temp->position == position)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/*Transfering everything except min, max, med from stack_a to stack_b*/
void	move_to_b(t_list **a, t_list **b)
{
	t_list	*min;
	t_list	*max;
	t_list	*median;
	t_list	*temp;

	temp = *a;
	min = search_min(a);
	max = search_max(a);
	median = search_median(a);
	temp = search_by_postion(*a, median->position + 1);
	move_from_a_to_b(a, b, temp);
	temp = *a;
	while (temp == min || temp == max || temp == median)
	{
		ra(a);
		temp = *a;
	}
	while (ft_lstsize(*a) > 3)
	{
		push_below_median(a, b, median, min);
		push_above_median(a, b, median, max);
	}
}

/*Indexing elements in a stack*/
void	give_index(t_list **stack)
{
	int		i;
	t_list	*temp;

	temp = *stack;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:12:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 15:07:33 by pguranda         ###   ########.fr       */
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

void	ft_print_lst_a(t_list *a)
{
	ft_printf("A: \n");
	while (a != NULL)
	{
		ft_printf(" %-5d   [i: %d, position:%d]\n", a->content, a->index, a->position);
		a = a->next;
	}
}

void	ft_print_lst_b(t_list *b)
{
	ft_printf("B: \n");
	while (b != NULL)
	{
		ft_printf(" %-5d   [i: %d, position:%d, total_score:%d]\n", b->content,  b->index, b->position, b->score);
		b = b->next;
	}
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

// void ft_default_struct(t_list **b, int total_count)
// {

// 	(*b)->content = 0;
// 	(*b)->index = 0;
// 	(*b)->total_count = total_count;
// }

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
	while (temp == min || temp == max || temp == median)
	{
		ra(a);
		temp = *a;
	}
	while (ft_lstsize(*a) != 3)
	{
		pb(a, b);
		temp = *a;
		while (ft_lstsize(*a) > 3 \
		&& (temp == min || temp == max || temp == median))
		{
			ra(a);
			temp = *a;
		}
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

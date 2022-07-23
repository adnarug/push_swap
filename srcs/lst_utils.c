/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:12:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/23 14:24:33 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void   ft_lst_free(t_list *lst)
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

void ft_print_lst_a(t_list *a)
{
	printf("A: \n");
	while (a != NULL)
	{
		printf(" %-5d   [in_i: %d, i: %d, ttl: %d]\n", a->content, a->init_index, a->index, a->total_count);
		a = a->next;
	}
}

void ft_print_lst_b(t_list *b)
{
	printf("B: \n");
	while (b != NULL)
	{
		printf(" %-5d   [in_i: %d, i: %d, ttl: %d]\n", b->content, b->init_index, b->index, b->total_count);
		b = b->next;
	}
}

void ft_default_struct(t_list **b, int total_count)
{

	(*b)->content = 0;
	(*b)->init_index = 0;
	(*b)->index = 0;
	(*b)->total_count = total_count;
}

void    decrease_index(t_list **lst)
{
	t_list	*head;

	head = *lst;
	while (*lst != NULL)
	{
		(*lst)->init_index -= 1;
		if((*lst)->init_index < 0)
			(*lst)->init_index = (*lst)->total_count - 1;
		if ((*lst)->init_index >= (*lst)->total_count)
			(*lst)->init_index = 0;
		*lst = (*lst)->next;
	}
	*lst = head;
}

void    increase_index(t_list **lst)
{
	t_list	*head;

	head = *lst;
	while (*lst != NULL)
	{
		(*lst)->init_index += 1;
		if((*lst)->init_index < 0)
			(*lst)->init_index = (*lst)->total_count - 1;
		if ((*lst)->init_index >= (*lst)->total_count)
			(*lst)->init_index = 0;
		*lst = (*lst)->next;
	}
	*lst  = head;
}
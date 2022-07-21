/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:12:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/21 08:30:59 by pguranda         ###   ########.fr       */
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
		printf(" %d \n", a->content);
		a = a->next;
	}
}

void ft_print_lst_b(t_list *b)
{
	printf("B: \n");
	while (b != NULL)
	{
		printf(" %d \n", (int)b->content);
		b = b->next;
	}
}

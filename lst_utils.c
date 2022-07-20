/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:12:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/20 13:33:14 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*ft_lstlast(t_num *lst)
{
	int				i;

	i = ft_lstsize(lst);
	while (i > 1)
	{
		lst = lst -> next;
		i--;
	}
	return (lst);
}

int	ft_lstsize(t_num *lst)
{
	int				i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_num	*ft_lstadd_back(t_num **lst, t_num *new)
{
	t_num				*last;

	if (lst == NULL)
		return (NULL);
	if (*lst == NULL)
	{
		*lst = new;
		return (NULL);
	}
	last = ft_lstlast(*lst);
	last -> next = new;
	return (last);
}

t_num	*ft_lstnew(int  content)
{
	t_num			*node;
	
	node = malloc(sizeof(t_num));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void   ft_lst_free(t_num *lst)
{
	t_num	*pointer;
	
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

void ft_print_lst_a(t_num *a)
{
	printf("A: \n");
	while (a != NULL)
	{
		printf(" %d \n", a->content);
		a = a->next;
	}
}

void ft_print_lst_b(t_num *b)
{
	printf("B: \n");
	while (b != NULL)
	{
		printf(" %d \n", b->content);
		b = b->next;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


void	ft_lstadd_front(t_num **lst, t_num	*new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

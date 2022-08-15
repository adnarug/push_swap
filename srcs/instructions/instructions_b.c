/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:50:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 12:21:15 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*Swap the first 2 elements on the top of stack b*/
void	sb(t_list *b)
{
	t_list	*first;
	t_list	*second;
	t_list	swap;

	if (b->next == NULL || b == NULL)
		return ;
	first = b;
	second = b->next;
	swap.content = first->content;
	swap.position = first->position;
	first->content = second->content;
	first->position = second->position;
	second->content = swap.content;
	second->position = swap.position;
	first->index = 0;
	second->index = 1;
	write (1, "sb\n", 3);
}

/*Push b - take the first element on the top of stack a and put it on top b*/
void	pb(t_list **a, t_list **b)
{
	if (a == NULL)
		return ;
	ft_lstadd_front(b, reassign_front_node(a));
	give_index(a);
	give_index(b);
	write (1, "pb\n", 3);
}

/*Rotate b - Shift up all elements in b by one*/
void	rb(t_list **b)
{
	t_list	*tmp;

	tmp = reassign_front_node(b);
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	give_index(b);
	write(1, "rb\n", 3);
}

/*Reverse rotate b - Shift down all elements in b by one*/
void	rrb(t_list **b)
{
	*b = reassign_back_node(b);
	give_index(b);
	write(1, "rrb\n", 4);
}

/*ra and rb together*/
void	rr(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = reassign_front_node(a);
	tmp_a->next = NULL;
	ft_lstadd_back(a, tmp_a);
	give_index(a);
	tmp_b = reassign_front_node(b);
	tmp_b->next = NULL;
	ft_lstadd_back(b, tmp_b);
	give_index(b);
	write(1, "rr\n", 3);
}

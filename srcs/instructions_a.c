/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:51:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 19:57:57 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Swap the first 2 elements on the top of stack a*/
void	sa(t_list *a)
{
	t_list	*first;
	t_list	*second;
	t_list	swap;

	if (a->next == NULL || a == NULL)
		return ;
	first = a;
	second = a->next;
	swap.content = first->content;
	swap.position = first->position;
	first->content = second->content;
	first->position = second->position;
	second->content = swap.content;
	second->position = swap.position;
	first->index = 0;
	second->index = 1;
	write (1, "sa\n", 3);
}

/* Push a - take the first element on the top of stack b and put it on top a*/
void	pa(t_list **a, t_list **b)
{
	if (b == NULL)
		return ;
	ft_lstadd_front(a, reassign_front_node(b));
	give_index(b);
	give_index(a);
	write (1, "pa\n", 3);
}

/*Rotate a - shift up all elements in a by one*/
void	ra(t_list **a)
{
	t_list	*tmp;

	tmp = reassign_front_node(a);
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	give_index(a);
	write(1, "ra\n", 3);
}

/*Reverse rotate a - Shift down all elements in a by one*/
void	rra(t_list **a)
{
	*a = reassign_back_node(a);
	give_index(a);
	write(1, "rra\n", 4);
}

//rra and rrb together
void	rrr(t_list **a, t_list **b)
{
	*a = reassign_back_node(a);
	give_index(a);
	*b = reassign_back_node(b);
	give_index(b);
	write(1, "rrr\n", 4);
}

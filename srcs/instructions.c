/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:50:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/08 19:33:06 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Swap the first 2 elements on the top of stack a*/
void	sa(t_list *a)
{
	if (a->next == NULL || a == NULL)
		return;
	t_list *first;
	t_list *second;
	t_list swap;
	
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

/*Swap the first 2 elements on the top of stack b*/ //TODO: missing the index update
void	sb(t_list *b)
{
	if (b->next == NULL || b == NULL)
		return;
	int first;
	int second;
	
	first = b->content;
	second = b->next->content;
	first = first + second;
	second = first - second;
	first = first - second;
	b->content = first;
	b->next->content = second;
	write (1, "sb\n", 3);
}

/* sa and sb */
void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
	write (1, "ss\n", 3);
}

//Push a - take the first element on the top of stack b and put it on top a*/
void	pa(t_list **a, t_list **b)
{
	if(b == NULL)
		return ;
	ft_lstadd_front(a, reassign_front_node(b));

	give_index(b);
	give_index(a);
	write (1, "pa\n", 3);
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

t_list	*reassign_front_node(t_list **list)
{
	t_list *head;

	if(list == NULL)
		return (NULL);
	head = *list;
	*list = head->next;
	return (head);
}

t_list	*reassign_back_node(t_list **list)
{
	t_list	*last;
	t_list	*head;
	
	head = *list;
	last = ft_lstlast(*list);
	last->next = head;
	while ((*list)->next != last)
		*list = (*list)->next;
	(*list)->next = NULL;
	head = last;
	return (head);
}

/*Rotate a - shift up all elements in a by one*/
void	ra(t_list **a)
{
	t_list	*tmp;
	// index = 
	tmp = reassign_front_node(a);
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	give_index(a);
	write(1, "ra\n", 3);
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

// ra and rb together
void rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
}

/*Reverse rotate a - Shift down all elements in a by one*/
void	rra(t_list **a)
{
	*a = reassign_back_node(a);
	give_index(a);
	write(1,"rra\n", 4);
}

/*Reverse rotate b - Shift down all elements in b by one*/
void rrb(t_list **b)
{
	*b = reassign_back_node(b);
	give_index(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
}

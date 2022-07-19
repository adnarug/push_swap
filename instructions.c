/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:50:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/19 17:59:15 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

/*Swap the first 2 elements on the top of stack a*/
void sa(t_num *a)
{
	if (a->next == NULL || a == NULL)
		return;
	int first;
	int second;
	
	first = a->content;
	second = a->next->content;
	first = first + second;
	second = first - second;
	first = first - second;
	a->content = first;
	a->next->content = second;
	write (1, "sa\n", 3);
}

/*Swap the first 2 elements on the top of stack b*/
void sb(t_num *b)
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
void ss(t_num *a, t_num *b)
{
	sa(a);
	sb(b);
}

/* Push a - take the first element on the top of stack b and put it on top a*/
void pa(t_num *a, t_num *b)
{
	if (b == NULL)
		return ;
	ft_lstadd_front(&a, b);
	ft_lstdelone(b, del_node(b));
}

void del_node(t_num *b)
{
	t_num *temp;
	
	temp = malloc(sizeof(t_num));
	temp = b->next;
	free (b);
	b = NULL;
	b = temp;
	free(temp);
	temp = NULL;
}

// /*Push b - take the first element on the top of stack a and put it on top b*/
// void pa(t_num *list)
// {
	
// }

// /*Rotate a - shift up all elements in a by one*/
// void ra(t_num *list)
// {
	
// }

// /*Rotate b - Shift up all elements in b by one*/
// void rb(t_num *list)
// {
	
// }

// /*Reverse rotate a - Shift down all elements in a by one*/
// void rra(t_num *list)
// {
	
// }

// /*Reverse rotate b - Shift down all elements in b by one*/
// void rrb(t_num *list)
// {
	
// }

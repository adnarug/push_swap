/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:12:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/12 17:57:09 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	printf("A: \n");
	while (a != NULL)
	{
		printf(" %-5d   [i: %d, position:%d]\n", a->content, a->index, a->position);
		a = a->next;
	}
}

void	ft_print_lst_b(t_list *b)
{
	printf("B: \n");
	while (b != NULL)
	{
		printf(" %-5d   [i: %d, position:%d, total_score:%d]\n", b->content,  b->index, b->position, b->score);
		b = b->next;
	}
}

// void ft_default_struct(t_list **b, int total_count)
// {

// 	(*b)->content = 0;
// 	(*b)->index = 0;
// 	(*b)->total_count = total_count;
// }

// void	decrease_index(t_list **lst, int flag_for_ttl)
// {
// 	t_list	*head;
// 	int		total;

// 	head = *lst;
// 	while(*lst != NULL)
// 	{
// 		total = ft_lstsize(*lst);
// 		(*lst)->total_count = total;
// 		if(flag_for_ttl == 1)
// 			(*lst)->total_count =(*lst)->total_count - 1;
// 		(*lst)->index -= 1;
// 		if((*lst)->index < 0)
// 			(*lst)->index = (*lst)->total_count - 1;
// 		if ((*lst)->index >= (*lst)->total_count)
// 			(*lst)->index = 0;
// 		*lst = (*lst)->next;
// 	}
// 	*lst = head;
// }



void	lst_indexing(t_list **a, t_list *presorted_a)
{
	t_list *head_a;
	t_list *head_presorted_a;

	head_a = *a;
	head_presorted_a = presorted_a;
	while (head_a != NULL)
	{
		if(head_a->content == head_presorted_a->content)
		{
			head_a->position = head_presorted_a->index;
			head_a = head_a->next;
			head_presorted_a = presorted_a;
		}
		else
			head_presorted_a = head_presorted_a->next;
	}
}

int	check_raw_sorted(t_list **a)
{
	t_list *temp;
	t_list *min;
	
	temp = *a;
	min = search_min(a);
	while (min != NULL && min->next != NULL)
	{
		if (min->content < (min->next)->content)
			min = min->next;
		else
			return (0);
	}
	if(temp->next == search_min(a))
	{
		if (temp->content < min->content)
			return (0);
	}
	min = search_min(a);
	while (temp != min && temp->next != min)
	{
		if (temp->content < temp->next->content)
			temp=temp->next;
		else
			return(0);
	}
	return(1);
}

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
	while(temp == min || temp == max || temp == median)
	{
		ra(a);
		temp = *a;
	}
	while(ft_lstsize(*a) != 3)//could it turn out to be less than 3?
	{
		pb(a, b);
		temp = *a;
		while(ft_lstsize(*a) > 3 && (temp == min || temp == max || temp == median))
		{
			ra(a);
			temp = *a;
		}
	}
}

void	sort_triple(t_list **stack)
{
{
	int	n_1;
	int	n_2;
	int	n_3;

	n_1 = (*stack)->content;
	n_2 = (*stack)->next->content;
	n_3 = (*stack)->next->next->content;
	if ((n_1 > n_2) && (n_1 < n_3) && (n_2 < n_3))
		sa(*stack);
	else if ((n_1 > n_2) && (n_1 > n_3) && (n_2 > n_3))
	{
		sa(*stack);
		rra(stack);
	}
	else if ((n_1 > n_2) && (n_1 > n_3) && (n_2 < n_3))
		ra(stack);
	else if ((n_1 < n_2) && (n_1 < n_3) && (n_2 > n_3))
	{
		sa(*stack);
		ra(stack);
	}
	else if ((n_1 < n_2) && (n_1 > n_3) && (n_2 > n_3))
		rra(stack);
}
}

void give_index(t_list **stack)
{
	t_list *temp;
	int		i;
	
	temp = *stack;
	i = 0;
	while (temp != NULL)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}
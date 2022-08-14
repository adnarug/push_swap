/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:12:37 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 14:23:16 by pguranda         ###   ########.fr       */
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

/*Giving each element in stack_a a position value 
(i.e. place in a sorted stack)*/
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

/* Stack that can be rotated without pushing e.g 34512.
	Find min and then check that until null is increasing*/
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
	// if(temp->next == search_min(a))
	// {
	if (temp->content < min->content)
		return (0);
	// }
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

/*Indexing elements in a stack*/
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
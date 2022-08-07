/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:49:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/07 16:09:39 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*search_cheapest_move(t_list **b)
{
	t_list	*min;
	t_list	*temp;
	
	min = *b;
	temp = *b;
	temp = temp->next;
	while(temp != NULL)
	{
		if(temp->total_score < min->total_score)
			min = temp;
		else
			temp = temp->next;
	}
	return(min);
}

static void	rotating_b(t_list **a, t_list **b, t_list *node_to_move)
{
	int		distance_to_bottom;
	int		distance_to_top;
	int		index_of_node;
	int		total;
	t_list	*temp;
	
	temp = *b;
	index_of_node = node_to_move->index;
	total = ft_lstlast(*b)->index + 1;
	// printf("Total is: %d \n", total);
	distance_to_bottom = total - (index_of_node + 1);
	distance_to_top = index_of_node;
	if(distance_to_bottom < distance_to_top)
	{
		while(distance_to_bottom != 0)
		{
			rra(a);
			distance_to_bottom--;
		}
		rra(a);
	}
	else
		while(index_of_node != 0)
		{
			ra(a);
			index_of_node--;
		}
}


void	move_process(t_list **a, t_list **b)
{
	t_list	*to_move;

	to_move = search_cheapest_move(b);
	// rotating_b(a, b, to_move);
	printf("Element to move: %d score : %d \n",to_move->content, to_move->total_score);
}
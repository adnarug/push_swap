/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:49:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/12 19:56:17 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*search_cheapest_move(t_list **b)
{
	t_list	*min;
	t_list	*temp;
	
	min = *b;
	temp = *b;
	while(temp != NULL)
	{
		if(temp->score < min->score)
			min = temp;
		else
			temp = temp->next;
	}
	return(min);
}

static void	rotating_b(t_list **b, t_list *node_to_move)
{
	int		distance_to_bottom;
	int		distance_to_top;
	int		index_of_node;
	int		total;
	t_list	*temp;
	
	temp = *b;
	index_of_node = node_to_move->index;
	total = ft_lstsize(*b);
	// printf("Total is: %d \n", total);
	distance_to_bottom = total - (index_of_node + 1);
	distance_to_top = index_of_node;
	if(distance_to_bottom == 0)
	{
		rrb(b);
		return ;
	}
	if(distance_to_bottom < distance_to_top)
	{
		while(distance_to_bottom != 0)
		{
			rrb(b);
			distance_to_bottom--;
		}
		rrb(b);
	}
	else
	{
		while(index_of_node != 0)
		{
			rb(b);
			index_of_node--;
		}
	}
}

void	rotating_a(t_list **a, t_list *target_spot)
{
	int		distance_to_bottom;
	int		distance_to_top;
	int		index_of_node;
	int		total;
	t_list	*temp;
	
	temp = *a;
	index_of_node = target_spot->index;
	total = ft_lstsize(*a);
	// printf("Total is: %d \n", total);
	distance_to_bottom = total - (index_of_node + 1);
	distance_to_top = index_of_node;
	if(distance_to_bottom == 0)
	{
		rra(a);
		return ;
	}
	if(distance_to_bottom < distance_to_top)
	{
		while(distance_to_bottom != 0)
		{
			rra(a);
			// printf("distance to bottom: %d \n", distance_to_bottom);
			distance_to_bottom--;
		}
		rra(a);
	}
	else
	{
		while(index_of_node != 0)
		{
			ra(a);
			index_of_node--;
		}
	}
}

void	move_process(t_list **a, t_list **b)
{
	t_list	*to_move;
	t_list	*target_spot;

	to_move = search_cheapest_move(b);
	target_spot = target_spot_in_a(a, to_move);
	// printf("BEFORE MOVE \n NODE  : %d position: %d score: %d \n TARGET: %d position: %d\n\n",to_move->content, to_move->position, to_move->total_score, target_spot->content, target_spot->position);	
	// ft_print_lst_b(b);
	rotating_b(b, to_move);
	rotating_a(a, target_spot);
	pa(a, b);	
}

void	move_process_for_5(t_list **a, t_list **b)
{
	t_list	*to_move;
	t_list	*target_spot;

	// to_move = search_cheapest_move(a);
	target_spot = target_spot_in_b(b, a);
	// printf("BEFORE MOVE \n NODE  : %d position: %d score: %d \n TARGET: %d position: %d\n\n",to_move->content, to_move->position, to_move->total_score, target_spot->content, target_spot->position);	
	// ft_print_lst_b(b);
	rotating_b(b, target_spot);
	// rotating_a(a, to_move);
	pb(a, b);	
}

void	move_process_for_5_back(t_list **a, t_list **b)
{
	t_list	*to_move;
	t_list	*target_spot;

	to_move = search_cheapest_move(b);
	// printf("BEFORE MOVE \n NODE  : %d position: %d score: %d \n TARGET: %d position: %d\n\n",to_move->content, to_move->position, to_move->total_score, target_spot->content, target_spot->position);	
	// ft_print_lst_b(b);
	rotating_b(b, to_move);
	pa(a, b);	
}

// void	move_process_median(t_list **b, t_list *median)
// {
// 	t_list	*to_move;
// 	t_list	*target_spot;

// 	// target_spot = target_spot_in_a(a, to_move);
// 	// // printf("BEFORE MOVE \n NODE  : %d position: %d score: %d \n TARGET: %d position: %d\n\n",to_move->content, to_move->position, to_move->total_score, target_spot->content, target_spot->position);	
// 	// // ft_print_lst_b(b);
// 	// // rotating_b(b, to_move);
// 	rotating_a(a, median);
// 	pa(a, b);	
// }
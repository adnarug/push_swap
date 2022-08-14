/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:49:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 14:20:55 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Finding the cheapest element in stack_b to move
by the score (incl. rotations in stack_a and stack_b)*/
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

/*Bringing the desired element in stack_b on top
with the least instructons. Not doing the push.*/
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

/*Bringing the desired element in stack_a on top
with the least instructons.*/
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

/*Identifying instances for rr and rrr. Where in stack_a and stack_b
 at the same time either ra or rra used. NB: ra == rb, rra == rrb */
static int finding_rr_rrr(t_list *to_move, t_list *target_spot)
{
	if (to_move == NULL || target_spot == NULL)
		return (0);
	to_move->count_rr = 0;
	to_move->count_rrr = 0;
	target_spot->count_rr = 0;
	target_spot->count_rrr = 0 ;
	if(to_move->score_ra <= to_move->score_rra && target_spot->score_ra <= target_spot->score_rra)
	{
		if(to_move->score_ra >= target_spot->score_ra)
			to_move->count_rr = target_spot->score_ra;
		else
			to_move->count_rr = to_move->score_ra;
		target_spot->count_rr = to_move->count_rr;
		return (1);
	}
	if(to_move->score_ra > to_move->score_rra && target_spot->score_ra > target_spot->score_rra)
	{
		if(to_move->score_rra >= target_spot->score_rra)
			to_move->count_rrr = target_spot->score_rra;
		else
			to_move->count_rrr = to_move->score_rra;
		target_spot->count_rrr = to_move->count_rrr;
		return (1);
	}
	return (0);
}

/*The main push process, move the right element from stack_b to the right place
in stack_a*/
void	move_process(t_list **a, t_list **b)
{
	t_list	*to_move;
	t_list	*target_spot;


	to_move = search_cheapest_move(b);
	target_spot = target_spot_in_a(a, to_move);
	// printf ("\n\nElement to be moved: %d, ras: %d rras:%d SCORE: %d \n", to_move->content, to_move->score_ra, to_move->score_rra, to_move->score);
	// printf ("Target spot: %d, ras: %d rras:%d \n", target_spot->content, target_spot->score_ra, target_spot->score_rra);
	// printf ("Score for the element: %d\n\n", to_move->score);
	finding_rr_rrr(to_move, target_spot);
	// printf("BEFORE MOVE \n NODE  : %d position: %d score: %d \n TARGET: %d position: %d\n\n",to_move->content, to_move->position, to_move->total_score, target_spot->content, target_spot->position);	
	// ft_print_lst_b(b);
	if (to_move->count_rr > 0)
	{
		while (to_move->count_rr != 0 )
		{
			rr(a, b);
			to_move->count_rr--;
		}
	}
	if (to_move->count_rrr > 0)
	{
		while (to_move->count_rrr != 0 )
		{
			rrr(a, b);
			to_move->count_rrr--;
		}
	}
	rotating_b(b, to_move);
	rotating_a(a, target_spot);
	pa(a, b);	
}
/*Moving the desired element from stack_a to stack_b*/
void move_from_a_to_b(t_list **a, t_list **b, t_list *element)
{
	rotating_a(a, element);
	pb(a, b);
}
// void	move_process_for_5(t_list **a, t_list **b)
// {
// 	t_list	*to_move;
// 	t_list	*target_spot;

// 	// to_move = search_cheapest_move(a);
// 	target_spot = target_spot_in_b(b, a);
// 	// printf("BEFORE MOVE \n NODE  : %d position: %d score: %d \n TARGET: %d position: %d\n\n",to_move->content, to_move->position, to_move->total_score, target_spot->content, target_spot->position);	
// 	// ft_print_lst_b(b);
// 	rotating_b(b, target_spot);
// 	// rotating_a(a, to_move);
// 	pb(a, b);	
// }

// void	move_process_for_5_back(t_list **a, t_list **b)
// {
// 	t_list	*to_move;
// 	t_list	*target_spot;

// 	to_move = search_cheapest_move(b);
// 	// printf("BEFORE MOVE \n NODE  : %d position: %d score: %d \n TARGET: %d position: %d\n\n",to_move->content, to_move->position, to_move->total_score, target_spot->content, target_spot->position);	
// 	// ft_print_lst_b(b);
// 	rotating_b(b, to_move);
// 	pa(a, b);	
// }

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
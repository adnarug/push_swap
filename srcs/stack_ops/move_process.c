/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:49:27 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 12:21:55 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*Finding the cheapest element in stack_b to move
by the score (incl. rotations in stack_a and stack_b)*/
t_list	*search_cheapest_move(t_list **b)
{
	t_list	*min;
	t_list	*temp;

	min = *b;
	temp = *b;
	while (temp != NULL)
	{
		if (temp->score < min->score)
			min = temp;
		else
			temp = temp->next;
	}
	return (min);
}

/*Identifying instances for rr and rrr. Where in stack_a and stack_b
 at the same time either ra or rra used. NB: ra == rb, rra == rrb */
int	finding_rrs(t_list *to_move, t_list *target)
{
	if (to_move == NULL || target == NULL)
		return (0);
	to_move->count_rr = 0;
	to_move->count_rrr = 0;
	target->count_rr = 0;
	target->count_rrr = 0;
	if (to_move->score_ra <= to_move->score_rra \
		&& target->score_ra <= target->score_rra)
	{
		if (to_move->score_ra >= target->score_ra)
			to_move->count_rr = target->score_ra;
		else
			to_move->count_rr = to_move->score_ra;
		return (1);
	}
	if (to_move->score_ra > to_move->score_rra \
		&& target->score_ra > target->score_rra)
	{
		if (to_move->score_rra >= target->score_rra)
			to_move->count_rrr = target->score_rra;
		else
			to_move->count_rrr = to_move->score_rra;
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
	finding_rrs(to_move, target_spot);
	executing_rrs(a, b, to_move);
	// printf("BEFORE MOVE \n NODE  : %d position: %d score: %d \n TARGET: %d position: %d\n\n",to_move->content, to_move->position, to_move->total_score, target_spot->content, target_spot->position);	
	// ft_print_lst_b(b);
	rotating_b(b, to_move);
	rotating_a(a, target_spot);
	pa(a, b);
}

/*Checking a cheapest way to move given node in a given stack
rra + 1 (to put on top) + 1 (to push) */
int	distance_to_move(t_list **stack, t_list *node)
{
	int		distance_to_bottom;
	int		distance_to_top;
	int		index_of_node;
	int		total;
	t_list	*temp;
	
	temp = *stack;
	index_of_node = node->index;
	total = ft_lstlast(*stack)->index + 1;
	distance_to_bottom = total - (index_of_node + 1);
	distance_to_top = index_of_node;
	node->score_ra = distance_to_top;
	node->score_rra = distance_to_bottom + 1;//to move to the top of the stack + pb
	if(distance_to_bottom < distance_to_top)
		return(distance_to_bottom + 1);//to move to the top of the stack
	else
		return(distance_to_top);
}
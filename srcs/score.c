/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:16:30 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/08 18:44:50 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	distance_to_move(t_list **stack, t_list *node)
{
	int		distance_to_bottom;
	int		distance_to_top;
	int		index_of_node;
	int		total;
	t_list	*temp;
	
	temp = *stack;
	index_of_node = node->index;
	total = ft_lstlast(*stack)->index + 1;
	// printf("Total is: %d \n", total);
	distance_to_bottom = total - (index_of_node + 1);
	distance_to_top = index_of_node;
	if(distance_to_bottom < distance_to_top)
		return(distance_to_bottom + 1);//to move to the top of the stack
	else
		return(distance_to_top);
}

//Going thorugh stack a and check the diffs in positions with pos of node. Skipping initial 
//values with the lower positions, before the init. Looking at difference 
t_list *target_spot_in_a(t_list **a, t_list *node)
{
	t_list 	*temp;
	t_list	*best_match;
	int		best_diff;
	int		actual_diff;

	temp = *a;
	best_diff = 0;
	actual_diff = 0;
	while (temp->position < node->position)
		temp = temp->next;
	best_diff = temp->position - node->position;
	best_match = temp;
	while(temp != NULL)
	{
		actual_diff = temp->position - node->position;
		if(actual_diff < best_diff && actual_diff > 0)
		{
			best_match = temp;
			best_diff = actual_diff;
		}
		temp = temp->next;
	}
	return(best_match);
}
// Distance to move or distance to the tail?
void	scoring(t_list **a, t_list **b)
{
	t_list *target_spot;
	t_list *temp_b;
	
	temp_b = *b;
	target_spot = NULL;
	while (temp_b != NULL)
	{
		temp_b->score_b = distance_to_move(b, temp_b) + 1;//+pb
		target_spot = target_spot_in_a(a, temp_b);
		temp_b->score_a = distance_to_move(a, target_spot);
		temp_b->total_score = temp_b->score_a + temp_b->score_b;
		temp_b = temp_b->next;
	}
	// t_list	*match_in_a;
	// score_b = distance_to_move(*b);
	// match_in_a = match_with_a(*a, *b);
	// score_a = distance_to_move(*a, match_in_a);
	// total_sore = score_b + score_a// put into the struct
	return ;
}


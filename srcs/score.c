/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:16:30 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/13 17:17:44 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Deciding whether it is worth moving the element up or down before pushing.
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
	node->score_ra = distance_to_top;
	node->score_rra = distance_to_bottom + 1;//to move to the top of the stack + pb
	if(distance_to_bottom < distance_to_top)
		return(distance_to_bottom + 1);//to move to the top of the stack
	else
		return(distance_to_top);
}

// Finding the best element (by position) to be put on top of stack a, before pushing from b.
t_list *target_spot_in_a(t_list **a, t_list *node)
{
	t_list 	*temp;
	t_list	*best_match;
	int		best_diff;
	int		actual_diff;

	temp = *a;
	best_diff = 0;
	actual_diff = 0;
	if (ft_lstsize(temp) > 1)
	{
		while(temp->position < node->position)
			temp = temp->next;
	}
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

t_list *target_spot_in_a_for_5(t_list **a, t_list *node)
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

// Finding the best element (by position) to be put on top of stack a, before pushing from b.
t_list *target_spot_in_b(t_list **b, t_list *node)
{
	t_list 	*temp;
	t_list	*best_match;
	int		best_diff;
	int		actual_diff;

	temp = *b;
	best_diff = 0;
	actual_diff = 0;
	if (ft_lstsize(temp) == 1)
		return (temp);
	while (temp->position > node->position)
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

// Scoring elements in b on how many instr in both stack are needed to place it correctly
void	scoring(t_list **a, t_list **b)
{
	t_list *target_spot;
	t_list *temp_b;
	int		score_a;
	int		score_b;
	
	temp_b = *b;
	target_spot = NULL;
	score_a = 0;
	score_b = 0;
	while (temp_b != NULL)
	{
		score_b = distance_to_move(b, temp_b) + 1;//+pb
		target_spot = target_spot_in_a(a, temp_b);
		score_a = distance_to_move(a, target_spot);
		temp_b->score = score_a + score_b;
		temp_b->score_ra += 1;
		temp_b->score_rra += 1; 
		temp_b = temp_b->next;
	}
	return ;
}

void	presorting_check(t_list **a)
{
	if(check_for_sorted(a) == 1)
		exit (0);
	if(check_raw_sorted(a) == 1)
	{
		final_sort(a);
		exit (0);
	}
	if(ft_lstsize(*a) == 3)
	{
		sort_triple(a);
		final_sort(a);
		exit(0);
	}
}
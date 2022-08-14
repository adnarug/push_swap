/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:20:44 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 19:27:43 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	moving_to_a_top(t_list **a, t_list **to_move, \
							int distance_to_bottom, int distance_to_top)
{
	if (distance_to_bottom == 0)
	{
		rra(a);
		return ;
	}
	if (distance_to_bottom < distance_to_top)
	{
		while (distance_to_bottom != 0)
		{
			rra(a);
			distance_to_bottom--;
		}
		rra(a);
	}
	else
	{
		while (distance_to_top != 0)
		{
			ra(a);
			distance_to_top--;
		}
	}
}

static void	moving_to_b_top(t_list **b, t_list **to_move, \
							int distance_to_bottom, int distance_to_top)
{
	if (distance_to_bottom == 0)
	{
		rrb(b);
		return ;
	}
	if (distance_to_bottom < distance_to_top)
	{
		while (distance_to_bottom != 0)
		{
			rrb(b);
			distance_to_bottom--;
		}
		rrb(b);
	}
	else
	{
		while (distance_to_top != 0)
		{
			rb(b);
			distance_to_top--;
		}
	}
}

void	executing_rrs(t_list **a, t_list **b, t_list *to_move)
{
	if (to_move->count_rr > 0)
	{
		while (to_move->count_rr != 0)
		{
			rr(a, b);
			to_move->count_rr--;
		}
	}
	if (to_move->count_rrr > 0)
	{
		while (to_move->count_rrr != 0)
		{
			rrr(a, b);
			to_move->count_rrr--;
		}
	}
}

/*Bringing the desired element in stack_b on top
with the least instructons. Not doing the push.*/
void	rotating_b(t_list **b, t_list *node_to_move)
{
	int		distance_to_bottom;
	int		distance_to_top;
	int		index_of_node;
	int		total;
	t_list	*temp;

	temp = *b;
	index_of_node = node_to_move->index;
	total = ft_lstsize(*b);
	distance_to_bottom = total - (index_of_node + 1);
	distance_to_top = index_of_node;
	moving_to_b_top(b, node_to_move, distance_to_bottom, distance_to_top);
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
	distance_to_bottom = total - (index_of_node + 1);
	distance_to_top = index_of_node;
	moving_to_a_top(a, target_spot, distance_to_bottom, distance_to_top);
}

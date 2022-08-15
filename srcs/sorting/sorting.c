/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 13:55:23 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 12:21:35 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*Executing final sort (e.g. 123) on the raw-sorted stack (e.g. 312)*/
void	final_sort(t_list **a)
{
	t_list	*start;

	start = search_min(a);
	while (check_for_sorted(a) == 0)
		rotating_a(a, start);
	return ;
}

/*Assigning a position (i.e. place in the sorted stack) for each node,
by creating a duplicate list, sorting it with quicksort and copying the index
as position (lst_indexing) for stack_a*/
void	presorting(t_list **a)
{
	t_list	*temp_a;

	temp_a = sorting(a);
	lst_indexing(a, temp_a);
	ft_lst_free(temp_a);
	temp_a = NULL;
}

/*Executing stack sorting algo, moving all except min, max, med to stack_b
and then returning in the sorted manner*/
void	stacks_sorting(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 5)
	{
		if (check_raw_sorted(a) == 1)
		{
			final_sort(a);
			return ;
		}
		sorting_stack_of_5(a, b);
		return ;
	}
	move_to_b(a, b);
	sort_triple(a);
	while (*b != NULL)
	{
		scoring(a, b);
		move_process(a, b);
	}
	final_sort(a);
}

/*Sorting a stack of 5, locating nodes by position, moving them to stack_b
returning in the correct place*/
void	sorting_stack_of_5(t_list **a, t_list **b)
{
	t_list	*first;
	t_list	*second;

	first = search_by_postion(*a, 0);
	second = search_by_postion(*a, 1);
	move_from_a_to_b(a, b, second);
	move_from_a_to_b(a, b, first);
	sort_triple(a);
	if ((*b)->position < (*b)->next->position)
		sb(*b);
	pa(a, b);
	pa(a, b);
}

/*Sorting a stack with 3 elements*/
void	sort_triple(t_list **stack)
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

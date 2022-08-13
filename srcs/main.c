/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/13 13:49:46 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO: насвинячил с сортировкой 5. остановился на этапе возрата из б в а(где 2 элемента)
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if(argc < 2)
		return (0);
	a = input_parsing(argv, &argc); 
	presorting_check(&a);
	presorting(&a);
	check_for_sorted(&a);//check for raw sorted also
	// ft_print_lst_a(a);
	stacks_sorting(&a, &b);
	// ft_print_lst_a(a);
	ft_lst_free(a);
	a = NULL;
	ft_lst_free(b);
	b = NULL;
	// system("leaks push_swap");
	return (0);
}

//Returns 0 is not sorted
int	check_for_sorted(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while(temp->next != NULL)
	{
		if(temp->content < temp->next->content)
			temp = temp->next;
		else 
			return(0);
	}
	return (1);
}

void	final_sort(t_list **a)
{
	t_list *start;

	start = search_min(a);
	// printf("The final min is: %d", start->content);
	while(check_for_sorted(a) == 0)
		rotating_a(a, start);
	return ;
}

void	presorting(t_list **a)
{
	t_list *temp_a;
	
	temp_a = sorting(a);
	lst_indexing(a, temp_a);
	ft_lst_free(temp_a);
	temp_a = NULL;
	
}

void	stacks_sorting(t_list **a, t_list **b)
{
	// printf("Before indexing\n");
	// ft_print_lst_a(*a);
	// ft_print_lst_b(*b);
	// printf("After indexing\n");
	if (ft_lstsize(*a) == 5)
	{
		if(check_raw_sorted(a) == 1)
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
		// ft_print_lst_a(*a);
		// ft_print_lst_b(*b);
	}
	final_sort(a);
}

// void	sorting_stack_of_5(t_list **a, t_list **b)
// {
// 	t_list *median;
// 	median = search_median(a);

// 	rotating_a(a, median);
// 	pb(a, b);	
// 	while (ft_lstsize(*a) != 2)
// 		move_process_for_5(a, b);
// 	if((*a)->position < (*a)->next->position)
// 		sa(*a);
// 	while (*b != NULL)
// 	{
// 		scoring(a, b);
// 		move_process_for_5_back(a, b);
// 		// ft_print_lst_a(*a);
// 		// ft_print_lst_b(*b);
// 	}
// 	final_sort(a);
// }

static t_list *search_by_postion(t_list *stack, int position)
{
	t_list *temp;

	temp = stack;
	while (temp != NULL)
	{
		if (temp->position == position)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}
void	sorting_stack_of_5(t_list **a, t_list **b)
{
	t_list *first;
	t_list *second;
	t_list *third;
	t_list *fourth;
	t_list *fifth;

	first = search_by_postion(*a, 0);
	second = search_by_postion(*a, 1);
	third = search_by_postion(*a, 2);
	fourth = search_by_postion(*a, 3);
	fifth = search_by_postion(*a, 4);
	move_from_a_to_b(a, b, second);
	move_from_a_to_b(a, b, first);
	sort_triple(a);
	// ft_print_lst_a(*a);
	// ft_print_lst_b(*b);
	if((*b)->position < (*b)->next->position)
		sb(*b);
	// ft_print_lst_b(*b);
	pa(a, b);
	pa(a, b);
	// // move_from_a_to_b(a, b, third);
	// // scoring(b, a);
	// // if(second->score <= first->score)
	// // {
	// // 	move_from_a_to_b(a, b, second);
	// 	move_from_a_to_b(a, b, first);
	// 	if((*a)->position > (*a)->next->position)
	// 		sa(*a);
	// 	rrb(b);
	// 	pa(a, b);
	// 	rrb(b);
	// 	pa(a, b);
	// 	pa(a, b);
	// }
	// else
	// {
	// 	move_from_a_to_b(a, b, first);
	// 	move_from_a_to_b(a, b, second);
	// 	if((*a)->position > (*a)->next->position)
	// 		sa(*a);
	// 	rrb(b);
	// 	pa(a, b);
	// 	pa(a, b);
	// 	pa(a, b);
	// }
}

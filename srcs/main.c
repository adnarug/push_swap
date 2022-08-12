/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/12 17:26:05 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO: atoi of --50	123 9487
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if(argc < 2)
		return (0);
	a = input_parsing(argv, &argc); 
	check_for_sorted(&a);
	// ft_print_lst_a(a);
	presorting_check(&a);
	presorting(&a);
	stacks_sorting(&a, &b);
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
	move_to_b(a, b);
	sort_triple(a);
	while (*b != NULL)
	{
		scoring(a, b);
		move_process(a, b);
	}
	final_sort(a);
}
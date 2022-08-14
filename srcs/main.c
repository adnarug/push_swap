/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/14 14:27:47 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Parsing the input and turning into a linked list. 
Approach: 1. Leave min, max, med in stack_a, sort it. 
		  2. Score each element stack_b on how many instr needed to move to a
		  3. Move from stack_a to stack_b always in the right place
Nuance:During presorting I give the correct position to each element, after that
		working with the position rather than the indeces.
		Separate algo for stacks of 3 and stacks of 5.*/
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
	// ft_print_lst_b(b);
	ft_lst_free(a);
	a = NULL;
	ft_lst_free(b);
	b = NULL;
	system("leaks push_swap");
	return (0);
}

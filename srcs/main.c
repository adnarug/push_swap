/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/08 19:34:49 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//TODO: lst util indexing
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*temp_a;
	t_list	*target_spot;
	int		i;

	b = NULL;
	i = 1;
	if(argc < 2)
		return (0);
	argv = typeof_input(argv, &argc, &i);
	if (argc == 2)
		return (0);
	a = ft_lstnew(atoi(argv[i]));
	if (i == 0)
	{
		argc--;
		a->total_count = argc;
	}
	else
		a->total_count = argc - 1;
	i += 1;
	//ft_default_struct(&b, a->total_count);
	ft_argv2list(argv, argc, a, i);
	give_index(&a);
	check_for_sorted(&a);
	temp_a = sorting(&a);
	lst_indexing(&a, &temp_a);
	search_max(&a);
	search_median(&a);
	search_min(&a);
	move_to_b(&a, &b);//Check!!
	sort_triple(&a);
	// // rb(&b);
	// printf("Sorted or not: %d", check_raw_sorted(&a));
	while (b != NULL)
	{
		scoring(&a, &b);
		move_process(&a, &b);
	}
	final_sort(&a);
	ft_print_lst_a(a);
	ft_print_lst_b(b);
	ft_lst_free(a);
	a = NULL;
	ft_lst_free(b);
	b = NULL;
	//system("leaks push_swap");
	return (0);
}


void ft_argv2list(char **argv, int argc, t_list *a, int start)
{
	int 	counter;
	t_list	*first;
	int		number;
	int		*arrayfor_check;
	
	number = 0;
	counter = 1;
	first = a;
	//here argc is including the ./a.out
	printf("argc: %d i: %d \n", argc, start);
	arrayfor_check = malloc((argc) * sizeof(int));
	if (arrayfor_check == NULL)
		return ;
	arrayfor_check[0] = first->content;
	while(start < argc)
	{
		checkis_digit(argv[start]);
		number = ft_atoi(argv[start]);
		if (number >= MAX_INT || number <= MIN_INT)
		{
			write(2, "Error", 6);
			exit (0);
		}
		check_repeats(arrayfor_check, number, counter);
		arrayfor_check[counter] = number;
		first = ft_lstadd_back(&first, ft_lstnew(number));
		start++;
		counter++;
	}
	free(arrayfor_check);
	arrayfor_check = NULL;
}

void	check_repeats(int *arrayfor_check, int number, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		if (arrayfor_check[i] == number)
		{
			write (2, "Error", 6);
			exit (1);
		}
		i++;
	}
}

void	checkis_digit(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != '+' && s[i] != '-')// Check if there is a non-digit
		{
			write (2, "Error", 6);
			exit(1);
		}
		i++;
	}
}

char	**typeof_input(char **nums, int *argc, int *i)
{
	int		counter;

	counter = 0;
	if(ft_strchr(nums[1], ' ') != NULL)
	{
		nums = ft_split(nums[1], ' ', &counter);
		*argc = counter;
		*i = 0;
	}
	return(nums);
}

void	move_min_to_b(t_list **a, t_list **b, t_list *min)
{
	int		distance_to_bottom;
	int		index_min;
	
	index_min = min->index;
	distance_to_bottom = min->total_count - (min->index + 1);
	if(distance_to_bottom <= min->index)
	{
		while(distance_to_bottom != 0)
		{
			rra(a);
			distance_to_bottom--;
		}
		rra(a);
		pb(a, b);
	}
	else if (index_min < distance_to_bottom)
	{
		while(index_min != 0)
		{
			ra(a);
			index_min--;
		}
		pb(a, b);
	}
}

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
		if(temp->next == NULL)
			return (1);
	}
	// temp = *a;
	// while(temp->next != NULL)// the case if the numbers are decreasing, only rra needed. recursion will exit after the first one 
	// {
	// 	if(temp->content > temp->next->content)
	// 		temp = temp->next;
	// 	else 
	// 		return (0);
	// 	if (temp->next == NULL)
	// 	{
	// 		rra(a);
	// 		check_for_sorted(&temp);
	// 	}
	// }
}

void	final_sort(t_list **a)
{
	t_list *start;

	start = search_min(a);
	printf("The final min is: %d", start->content);
	while(check_for_sorted(a) == 0)
		rotating_a(a, start);
}
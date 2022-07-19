/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/19 15:43:40 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
	t_num	*head_p;
	int		start;
	int		counter;
	int		i;

	start = 0;
	counter = 0;
	i = 1;
	if (argc < 2)
		return (0);
	argv = typeof_input(argv, &argc, &i);
	head_p = ft_lstnew(atoi(argv[i]));//argv[1] can be in quotation marks
	i += 1;
	ft_argv2list(argv, argc, head_p, i);
	ft_print_lst(head_p);
	ft_lst_free(head_p);
	head_p = NULL;
	//system("leaks a.out");
	return (0);
}

void ft_argv2list(char **nums, int count, t_num *head_p, int start)
{
	int 	counter;
	t_num	*first;
	int		number;
	int		new_nums[count];
	
	number = 0;
	counter = 1;
	first = head_p;
	new_nums[0] = first->content;
	while(start < count)
	{
		check_isdigit(nums[start]);
		number = atoi(nums[start]);
		check_repeats(new_nums, number, count);
		new_nums[counter] = number;
		first = ft_lstadd_back(&first, ft_lstnew(number));
		start++;
		counter++;
	}
}

void check_repeats(int *new_nums, int number, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (new_nums[i] == number)
		{
			write (2, "Error", 6);
			exit (1);
		}
		i++;
	}
}

void	check_isdigit(char *s)
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

char **typeof_input(char **nums, int *argc, int *start)
{
	int		counter;

	counter = 0;
	if(strchr(nums[1], ' ') != NULL)
	{
		nums = ft_split(nums[1], ' ', &counter);
		*argc = counter;
		*start = 0;
	}
	return (nums);
}

// void clean_nums(char **nums, int length)
// {
// 	int	i;
	
// 	i = 1;
// 	while(i < length)
// 	{
// 		free(nums[i]);
// 		nums[i] = NULL;
// 		i++;
// 	}	
// 	free(nums);
// 	nums = NULL;
// }

// void ft_news_nums2list(char **nums, int count, t_num *head_p)
// {
// 	int		i;
// 	t_num	*first;
// 	int		number;
	
// 	i = 0;
// 	number = 0;
// 	first = head_p;
// 	while(i < count)
// 	{
// 		number = atoi(nums[i]);
// 		first = ft_lstadd_back(&first, ft_lstnew(number));
// 		i++;
// 	}
// 	return ;
// }

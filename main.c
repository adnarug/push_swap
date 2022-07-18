/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:53:14 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/18 18:19:08 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
	t_num	*head_p;
	int		start;

	start = 0;
	if (argc < 2)
		return (0);
	input_check(argv[1]);
	head_p = ft_lstnew(atoi(argv[1]));//argv[1] can be in quotation marks
	argv += 2;
	ft_argv2list(argv, argc, head_p);
	ft_print_lst(head_p);
	ft_lst_free(head_p);
	head_p = NULL;
	//system("leaks a.out");
	return (0);
}

void ft_argv2list(char **nums, int count, t_num *head_p)
{
	int		i;
	int 	counter;
	t_num	*first;
	int		number;
	
	i = 0;
	number = 0;
	counter = 0;
	first = head_p;
	while(i < count)
	{
		parsing_input(nums[i], &count, first);
		input_check(nums[i]);
		number = atoi(nums[i]);
		first = ft_lstadd_back(&first, ft_lstnew(number));
		i++;
	}
}

void	input_check(char *s)
{
	int i;

	i = 0;
	if ((*s < '0' || *s > '9'))// Check if there is a non-digit
	{
		write (2, "Error", 6);
		exit(1);
	}
	// while (s[i] != '\0')// Check for the dupes
	// {
	// 	if((strchr((const char*)s, s[i]) != NULL) && (&s[i] != strchr((const char*)s, s[i])))
	// 		{
	// 			write(2, "Error", 6);
	// 			exit(1);
	// 		}
	// 	i++;
	// }
}

void clean_nums(char **nums, int length)
{
	int	i;
	
	i = 1;
	while(i < length)
	{
		free(nums[i]);
		nums[i] = NULL;
		i++;
	}	
	free(nums);
	nums = NULL;
}

void parsing_input(char *nums, int *count, t_num *latest_element)
{
	int	i;
	int counter;
	char **new_nums;

	i = 0;
	counter = 0;
	if(strchr(nums, ' ') != NULL)
	{
		//clean_nums(nums, count);
		new_nums = ft_split(nums, ' ', &counter);
		//ft_argv2list(new_nums, counter, latest_element);
		ft_news_nums2list(new_nums, counter, latest_element);
	}
}

void ft_news_nums2list(char **nums, int count, t_num *head_p)
{
	int		i;
	t_num	*first;
	int		number;
	
	i = 0;
	number = 0;
	first = head_p;
	while(i < count - 1)
	{
		number = atoi(nums[i]);
		first = ft_lstadd_back(&first, ft_lstnew(number));
		i++;
	}
	return ;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:30:21 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/12 17:33:51 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_repeats(int *arrayfor_check, int number, int counter)
{
	int	i;

	i = 0;
	while (i < counter)
	{
		if (arrayfor_check[i] == number)
		{
			write (2, "Error\n", 6);

			exit (1);
		}
		i++;
	}
}

static void	checkis_digit(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0 && s[i] != '+' && s[i] != '-')// Check if there is a non-digit
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		// if (ft_isdigit(s[i]) == 1 && ft_isdigit(s[i + 1]) != 0 && s[i + 1] != '\0')// Check if there is a non-digit
		// {
		// 	write (2, "Error\n", 6);
		// 	exit(1);
		// }
		i++;
	}
}

static void	check_limits(long int number)
{
	if(number > MAX_INT || number < MIN_INT)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
}
static char	**typeof_input(char **new_argv, int *argc, int *i)
{
	int		counter;
	int		iter;

	counter = 0;
	iter = 0;
	if(ft_strchr(new_argv[1], ' ') != NULL || ft_strchr(new_argv[1], '	') != NULL)
	{
		if (*argc != 2)
		{
			write (2, "Error\n", 6);
			exit(0);
		}
		new_argv = ft_split(new_argv[1], ' ', &counter);
		*argc = counter;
		*i = 0;
	}
	while (*i == 0 && iter < (counter - 1))
	{
		checkis_digit(new_argv[iter]);
		iter++;
	}
	return(new_argv);
}

static void ft_argv2list(char **argv, int argc, t_list *a, int start)
{
	int 			counter;
	t_list			*first;
	long int		number;
	int				*arrayfor_check;
	
	number = 0;
	counter = 1;
	first = a;
	//here argc is including the ./a.out
	//printf("argc: %d i: %d \n", argc, start);
	arrayfor_check = malloc((argc) * sizeof(int));
	if (arrayfor_check == NULL)
		return ;
	arrayfor_check[0] = first->content;
	while(start < argc)
	{
		checkis_digit(argv[start]);
		number = ft_atoi(argv[start]);
		check_limits(number);
		check_repeats(arrayfor_check, number, counter);
		arrayfor_check[counter] = number;
		first = ft_lstadd_back(&first, ft_lstnew(number));
		start++;
		counter++;
	}
	free(arrayfor_check);
	arrayfor_check = NULL;
}

t_list	*input_parsing(char **argv,int *argc)
{
	t_list		*stack_a;
	int			i;
	long int	number;
	
	i = 1;
	stack_a = NULL;
	if (argv[1] == NULL || *argv[1] == '\0')
		exit(0);
	argv = typeof_input(argv, argc, &i);
	number = ft_atoi(argv[i]);
	check_limits(number);
	stack_a = ft_lstnew(number);
	// if (*argc <= 2)
	// 	exit (0);
	if (i == 0)
		*argc = *argc - 1;
	i = i + 1;
	ft_argv2list(argv, *argc, stack_a, i);
	give_index(&stack_a);
	return (stack_a);
}

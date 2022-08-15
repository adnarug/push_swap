/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:30:21 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 15:37:32 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Checking if line contains spaces or tabs, then split
reassignign the argv*/
static char	**typeof_input(char **new_argv, int *argc, int *i)
{
	int		counter;
	int		iter;

	counter = 0;
	iter = 0;
	if (new_argv[0] == NULL || *new_argv[0] == '\0')
		error_message(1);
	if (ft_strchr(new_argv[1], ' ') != NULL \
		|| ft_strchr(new_argv[1], '	') != NULL)
	{
		if (*argc != 2)
			error_message(1);
		new_argv = ft_split(new_argv[1], ' ', &counter);
		*argc = counter;
		*i = 0;
	}
	while (*i == 0 && iter < (counter - 1))
	{
		checkis_digit(new_argv[iter]);
		iter++;
	}
	return (new_argv);
}

/*Checking if int is more than MAX or MIN or repeated*/
static int	check_limits_repeats(int **arrayfor_check, char *s, int *counter)
{
	long int	number;
	
	number = ft_atoi(s);
	check_limits(number);
	if (arrayfor_check != NULL)
		check_repeats(*arrayfor_check, (int)number, *counter);
	return (number);
}

/*Converting the final argv into a linked list*/
static void	argv_to_list(char **argv, int argc, t_list *a, int start)
{
	int				counter;
	t_list			*first;
	long int		number;
	int				*arrayfor_check;

	number = 0;
	counter = 1;
	first = a;
	arrayfor_check = malloc((argc) * sizeof(int));
	if (arrayfor_check == NULL)
		return ;
	arrayfor_check[0] = first->content;
	while (start < argc)
	{
		if (argv[start] == NULL)
			error_message(1);
		checkis_digit(argv[start]);
		number = check_limits_repeats(&arrayfor_check, argv[start], &counter);
		first = ft_lstadd_back(&first, ft_lstnew(number));
		arrayfor_check[counter] = number;
		start++;
		counter++;
	}
	free(arrayfor_check);
	arrayfor_check = NULL;
}

/*Driver function for the parsing*/
t_list	*input_parsing(char **argv, int *argc)
{
	t_list		*stack_a;
	int			i;
	long int	number;

	i = 1;
	stack_a = NULL;
	if ((argv[1] == NULL || *argv[1] == '\0') && *argc == 2)
		error_message(0);
	argv = typeof_input(argv, argc, &i);
	number = check_limits_repeats(NULL, argv[i], 0);
	stack_a = ft_lstnew(number);
	if (i == 0)
		*argc = *argc - 1;
	i = i + 1;
	argv_to_list(argv, *argc, stack_a, i);
	give_index(&stack_a);
	return (stack_a);
}

void	error_message(int error)
{
	if (error == 1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	if (error == 0)
		exit (0);

}

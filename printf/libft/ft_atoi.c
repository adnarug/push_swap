/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:52:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/15 16:23:38 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_white_space(const char *str)
{
	int				i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

static int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long int	get_num(const char *str, int *i)
{
	long int	result_integer;

	result_integer = 0;
	while (ft_isnum(str[*i]) == 1)
	{
		result_integer = result_integer * 10 + str[*i] - '0';
		*i = *i + 1;
	}
	return (result_integer);
}

static void	error_message(int error)
{
	if (error == 1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

long int	ft_atoi(const char *str)
{
	int				i;
	long int		result_integer;
	int				sign;
	int				flag_for_sign;

	i = 0;
	flag_for_sign = 0;
	sign = 1;
	i = ft_white_space(str);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		flag_for_sign = 1;
	}
	if (ft_isnum(str[i]) == 0)
		error_message(1);
	result_integer = get_num(str, &i);
	if (ft_isnum(str[i]) == 0 && str[i] != '\0' \
		&& str[i] != '\t' && str[i] != ' ')
		error_message(1);
	if (result_integer == 0 && flag_for_sign == 1)
		error_message(1);
	return (result_integer * sign);
}

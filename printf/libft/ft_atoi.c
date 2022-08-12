/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:52:34 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/12 17:22:53 by pguranda         ###   ########.fr       */
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

long int	ft_atoi(const char *str)
{
	int				i;
	long int		result_integer;
	int				sign;

	i = 0;
	result_integer = 0;
	sign = 1;
	i = ft_white_space(str);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (ft_isnum(str[i]) == 0)
	{
		write (2, "Error\n", 6);
		exit(0);
	}
	while (ft_isnum(str[i]) == 1)
	{
		result_integer = result_integer * 10 + str[i] - '0';
		i++;
	}
	if(ft_isnum(str[i]) == 0 && str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
	{
		write (2, "Error\n", 6);
		exit(0);
	}
	return (result_integer * sign);
}
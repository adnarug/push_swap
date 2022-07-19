/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:04:33 by pguranda          #+#    #+#             */
/*   Updated: 2022/07/19 14:15:00 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <string.h>

static unsigned int		ft_count_strings(char const *s, char c);
static int				ft_str_len(char const *s, char c);
static int				ft_assign(char const *s, char *p_str, char c, int i);


char	**ft_split(char const *s, char c, int *counter)
{
	char				**arr_str;
	int					i;
	int					arr_len;

	if (s == NULL)
		return (NULL);
	*counter = 0;
	i = 0;
	arr_len = ft_count_strings(s, c);
	arr_str = (char **)malloc(arr_len * sizeof(char *) + sizeof(void *));
	if (arr_str == NULL)
		return (NULL);
	while (*counter < arr_len)
	{
		while (ft_str_len(s + i, c) == 0)
			i++;
		arr_str[*counter] = (char *)malloc(sizeof(char) * ft_str_len(s + i, c));
		i = ft_assign(s, arr_str[*counter], c, i);
		*counter += 1;
		if (s[i] == c)
			i++;
	}
	// *counter += 1;
	// arr_str[*counter] = 0;
	return (arr_str);
}

static int	ft_assign(char const *s, char *p_str, char c, int i)
{
	while (s[i] != c && s[i] != '\0')
	{
		*p_str = s[i];
		i++;
		p_str++;
	}
	*p_str = '\0';
	return (i);
}

static unsigned int	ft_count_strings(char const *s, char c)
{
	int				i;
	int				counter;
	int				len;

	i = 0;
	counter = 0;
	len = strlen(s);
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static int	ft_str_len(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (i > 0)
		return (i + 1);
	return (0);
}


// int main ()
// {
// 	char **check;
// 	int *num;

// 	num = malloc(sizeof(int));
// 	*num = 0;
// 	check = ft_split ("Hello World Again!", ' ', num);
// 	printf ("%d ", *num);
// 	printf ("%s ", check[1]);
// 	return (0);
// }
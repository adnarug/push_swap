/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:28:50 by pguranda          #+#    #+#             */
/*   Updated: 2022/08/12 17:08:38 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strchr(char *s, char c)
{
	char				z;
	char			*p_c;

	z = c;
	p_c = s;
	while (*p_c != '\0' || z == '\0')
	{
		if (*p_c == z)
			return ((char *)p_c);
		p_c++;
	}
	return (NULL);
}

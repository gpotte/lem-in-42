/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpotte <gpotte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:06:53 by gpotte            #+#    #+#             */
/*   Updated: 2016/01/29 13:05:46 by gpotte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, int n)
{
	char	*s2;
	size_t	i;

	if (!(s2 = malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && i < (unsigned int)n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

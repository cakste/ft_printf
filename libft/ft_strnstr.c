/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:35:20 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 09:35:21 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	To explain the restart: if we have a string like "ozarabozaraboze123"
**	and try to find "ozaraboze", when the needle doesn't match any more,
**	we have already read a part of needle bit of the haystack ("oz").
**	That's why we go back to the start, and then push the restart by
**	one everytime.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	restart;
	char	*haystack_cpy;

	i = 0;
	j = 0;
	restart = 0;
	haystack_cpy = (char *)haystack;
	while (haystack_cpy[i] != '\0' && needle[j] != '\0' && i < len)
	{
		if (haystack_cpy[i] == needle[j])
			j++;
		else
		{
			j = 0;
			i = restart;
			restart++;
		}
		i++;
	}
	if (needle[j] == '\0')
		return (&haystack_cpy[i - j]);
	return (NULL);
}

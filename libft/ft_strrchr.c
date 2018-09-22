/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 09:08:54 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 09:08:56 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_cpy;
	char	*s_last;

	s_cpy = (char *)s;
	s_last = NULL;
	while (*s_cpy != '\0')
	{
		if (*s_cpy == (char)c)
			s_last = s_cpy;
		s_cpy++;
	}
	if (*s_cpy == (char)c)
		s_last = s_cpy;
	return (s_last);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 10:48:43 by acakste           #+#    #+#             */
/*   Updated: 2018/09/12 10:49:23 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_chars(int n)
{
	int	i;

	i = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*new;
	int		i;
	int		len;

	len = ft_count_chars(n);
	new = (char*)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = len - 1;
	if (n < 0)
		new[0] = '-';
	if (n == 0)
		new[i] = '0';
	while (n != 0)
	{
		if (n < 0)
			new[i] = (n % 10) * -1 + '0';
		else
			new[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	new[len] = '\0';
	return (new);
}

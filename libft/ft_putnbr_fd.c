/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:34:48 by acakste           #+#    #+#             */
/*   Updated: 2018/09/12 11:34:51 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 10 && n > -10)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd(n * -1 + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	if (n < 0)
		ft_putchar_fd((n % 10) * -1 + '0', fd);
	else
		ft_putchar_fd((n % 10) + '0', fd);
}

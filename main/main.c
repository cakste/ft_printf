/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:40:27 by acakste           #+#    #+#             */
/*   Updated: 2018/09/18 16:40:29 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/ft_printf.h"

/*
int	main(void)
{
	char str[] = "DARKNESS MY OLD FRIEND";

	printf("%50.5dsafs\n", 4298);
	printf("%010s\n", ft_itoa_base(256, "01"));
	return (0);
}
*/
int	main(void)
{
	char str[] = "DARKNESS MY OLD FRIEND";
	/*ft_putnbr_base(255, "0123456789abcdef");
	ft_putnbr(100000);
	ft_putnbr(-23);
	ft_putnbr(9);
	ft_putnbr(0);
	ft_putnbr(-2);*/
/*	ft_printf("%d\n", ft_printf("HELLO %s\n", str));
	ft_printf("HELLO %c\n", *str);
	ft_printf("%d\n", ft_printf("HELLO %d\n", -424564856));
	ft_printf("HELLO %d\n", -42);
	ft_printf("HELLO %p\n", str);
	ft_printf("HELLO %o\n", 100);
	ft_printf("HELLO %u\n", 456);
	ft_printf("HELLO %u\n", 255);

	printf("%d\n", printf("HELLO %s\n", str));
	printf("HELLO %c\n", *str);
	printf("%d\n", printf("HELLO %d\n", -424564856));
	printf("HELLO %d\n", -42);
	printf("HELLO %p\n", str);
	printf("HELLO %o\n", 100);
	printf("HELLO %u\n", 456);
	printf("HELLO %u\n", 255);*/
	//ft_printf("hello%      10u sljl %s", 4657, "Hellooo\n");
	//printf("hello%      10u sljl %s", 4657, "Hellooo\n");
	//ft_printf("hello %+20.5d kk %s\n", 0, "HEY");
	//printf("hello %+20.5d kk %s\n", 0, "HEY");
	//printf("Return my: %d\n", ft_printf("%p size of int:%5lu%%\n", str, sizeof(int)));
	//printf("Return real: %d\n", printf("%p size of int:%5lu%%\n", str, sizeof(int)));
	//printf("hello 12345678901234567890123456789\n");
	//printf("hello %-10d\n", 42);

	/*int i = printf("hello %-10.6d, %5d\n", 42, 55);
	int i2 = ft_printf("hello %-10.6d, %5d\n", 42, 55);
	printf("I = %d\nI2 = %d\n", i, i2);
	printf("%x %-10.6d, %5d\n",-200 ,42, 55);
	ft_printf("%x %-10.6d, %5d\n\n",-200 ,42, 55);

	int i3 = printf("18888888879879897897877978888888888888\n");
	int i4 = ft_printf("18888888879879897897877978888888888888\n");
	printf("I3 = %d\nI4 = %d\n", i3, i4);*/

	//ft_printf("%f2\n", 253.23);
	//printf("%f2\n", 253.23);

	//printf("test %15sffssa\n", NULL);
//	ft_printf("test %15sffssa\n", NULL);

	//ft_printf("% w\n");
	//printf("% w\n");


	//printf("%l x\n", 2);
	//ft_printf("%l x\n", 2);
	//ft_printf("%  #0+10.44y\n");
	/*int	wides[5];

	wides[0] = L'貓';
	wides[1] = L'\0';

	wchar_t	wide = L'😋';
	printf("%lu\n", sizeof(wchar_t));
	printf("%C\n", wide);*/
	//ft_printf("%10.5x\n", 542);
	//printf("%10.5x\n", 542);
  //	ft_printf("%#20llx\n", 9223372036854775807);
  	//printf("%#18llx\n", 9223372036854775807);
	//ft_printf("%10x\n", 42);
	//printf("%10x\n", 42);
  ft_printf("%5.2x\n", 5427);
  printf("%5.2x\n", 5427);




//ft_printf("%ld\n", 2147483648);
//printf("%ld\n", 2147483648);
  	//ft_printf("%.2s is a string", "this");
	printf("12345678901234567890\n");

	//printf("%10.12x\n", 542);
	return (0);
}

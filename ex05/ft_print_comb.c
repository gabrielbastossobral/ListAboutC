/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:29:58 by gabastos          #+#    #+#             */
/*   Updated: 2024/08/21 10:06:44 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(char number1, char number2, char number3)
{
	ft_putchar(number1);
	ft_putchar(number2);
	ft_putchar(number3);
	if (number1 != '7' || number2 != '8' || number3 != '9')
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	number1;
	char	number2;
	char	number3;

	number1 = '0';
	while (number1 <= '9')
	{
		number2 = number1 + 1;
		while (number2 <= '9')
		{
			number3 = number2 + 1;
			while (number3 <= '9')
			{
				print_comb(number1, number2, number3);
				number3++;
			}
			number2++;
		}
		number1++;
	}
}

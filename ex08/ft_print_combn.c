/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:14:39 by gabastos          #+#    #+#             */
/*   Updated: 2024/08/26 09:31:09 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX_COMBINATION_SIZE 9

void	print_combination(int n, char *combination)
{
	write(1, combination, n);
}

void	generate_combinations(int n, int start, int depth, char *combination)
{
	int	i;

	i = start;
	if (depth == n)
	{
		print_combination(n, combination);
		write(1, ", ", 2);
		return ;
	}
	while (i <= 9)
	{
		combination[depth] = i + '0';
		generate_combinations(n, i + 1, depth + 1, combination);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	combination[MAX_COMBINATION_SIZE];

	if (n <= 0 || n > MAX_COMBINATION_SIZE)
	{
		return ;
	}
	generate_combinations(n, 0, 0, combination);
	if (n > 0)
	{
		write(1, "\b\b ", 2);
	}
}

int	main(void)
{
	ft_print_combn(3);
	return (0);
}

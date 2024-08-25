/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:14:39 by gabastos          #+#    #+#             */
/*   Updated: 2024/08/25 16:59:57 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(int n, char *combination, int is_last)
{
	write(1, combination, n);
	if (!is_last)
	{
		write(1, ", ", 2);
	}
}


void	generate_combinations(int n, int start, int depth, char *combination){
	int	i;

	i = start;
	if (depth == n)
	{
		print_combination(n, combination, 0);
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
	char	combination[n];

	if (n <= 0 || n >= 10)
	{
		return ;
	}
	generate_combinations(n, 0, 0, combination);
}

// int	main(void)
// {
// 	ft_print_combn(8);
// 	return (0);
// }

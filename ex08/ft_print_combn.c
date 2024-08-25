/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabastos <gabastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:14:39 by gabastos          #+#    #+#             */
/*   Updated: 2024/08/25 17:18:39 by gabastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define MAX_COMBINATION_SIZE 9

void print_combination(int n, char *combination) {
    write(1, combination, n);
}

// Função recursiva para gerar combinações
void generate_combinations(int n, int start, int depth, char *combination, int total_combinations, int *current_index) {
    int i;

    if (depth == n) {
        print_combination(n, combination);
        (*current_index)++;
        if (*current_index < total_combinations) {
            write(1, ", ", 2);
        }
        return;
    }

    i = start;
    while (i <= 9) {
        combination[depth] = i + '0'; // Converte dígito para caractere
        generate_combinations(n, i + 1, depth + 1, combination, total_combinations, current_index);
        i++;
    }
}

// Função principal que inicia o processo
void ft_print_combn(int n) {
    char combination[MAX_COMBINATION_SIZE];
    int total_combinations = 1;
    int current_index = 0;
    int i;

    if (n <= 0 || n > MAX_COMBINATION_SIZE) {
        return;
    }

    // Calcula o total de combinações para verificar a última combinação
    i = 0;
    while (i < n) {
        total_combinations *= (10 - i);
        total_combinations /= (i + 1);
        i++;
    }

    generate_combinations(n, 0, 0, combination, total_combinations, &current_index);
}

int main(void) {
    ft_print_combn(3);
    return 0;
}

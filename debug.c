/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:21:51 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:22:26 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

// print the board
// ONLY FOR DEBUG
void	ft_print_board(int tab[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			fprintf(stderr, "%d\t", tab[i][j]);
			j++;
		}
		fprintf(stderr, "\n");
		i++;
	}
}

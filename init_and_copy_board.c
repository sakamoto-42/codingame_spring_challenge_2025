/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_copy_board.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:25:28 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:25:35 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

// initalize the board
// with the parameters
// provided by scanf
void	ft_init_board(int tab[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			scanf("%d", &(tab[i][j]));
			j++;
		}
		i++;
	}
}

// copy the board
// for the backtracking
void	ft_copy_board(int dest[3][3], int src[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

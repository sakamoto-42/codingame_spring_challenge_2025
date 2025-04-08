/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_is_solved.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:34:16 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:40:40 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

// check if the board is solved
// (if there is no empty cell
// and no possible capture)
bool	ft_board_is_solved(int tab[3][3], t_capture c[11])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (tab[i][j] == 0)
			{
				if (ft_check_captures(tab, i, j, c) == false)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

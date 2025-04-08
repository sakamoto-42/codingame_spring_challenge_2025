/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:34:02 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:41:35 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

// solve the board
// recursive function
void	ft_solve_board(t_solver *solver, int tab[3][3],
	t_backtracking_state *bts)
{
	int						tab_copy[3][3];
	bool					capture_done;
	int						hash;

	if (bts->depth == solver->max_depth || ft_board_is_solved(tab, solver->c))
	{
		hash = ft_get_hash(tab);
		solver->total_sum = (solver->total_sum + hash) % (1LL << 30);
		return ;
	}
	bts->i = 0;
	while (bts->i < 3)
	{
		bts->j = 0;
		while (bts->j < 3)
		{
			capture_done = ft_try_and_apply_captures(solver, tab,
					tab_copy, bts);
			if (!capture_done && tab[bts->i][bts->j] == 0)
				ft_apply_non_capture(solver, tab, bts);
			bts->j++;
		}
		bts->i++;
	}
}

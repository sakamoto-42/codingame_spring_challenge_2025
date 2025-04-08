/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_capture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:33:23 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:34:48 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

// try to apply all captures in the cell
bool	ft_try_and_apply_captures(t_solver *solver, int tab[3][3],
	int tab_copy[3][3], t_backtracking_state *bts)
{
	int						m;
	bool					capture_done;
	t_backtracking_state	next_state;

	capture_done = false;
	m = 0;
	while (m < 11)
	{
		if (bts->depth < solver->max_depth && tab[bts->i][bts->j] == 0
			&& ft_capture_is_possible(tab, bts->i, bts->j, solver->c[m]))
		{
			ft_copy_board(tab_copy, tab);
			ft_apply_capture(tab_copy, bts, solver->c[m]);
			next_state = *bts;
			next_state.depth++;
			ft_solve_board(solver, tab_copy, &next_state);
			capture_done = true;
		}
		m++;
	}
	return (capture_done);
}

// apply a capture
void	ft_apply_capture(int tab[3][3], t_backtracking_state *bts, t_capture c)
{
	int	dice_sum;
	int	n;
	int	ic;
	int	jc;

	dice_sum = 0;
	n = 0;
	while (n < c.nb_captures)
	{
		ic = bts->i + c.ic[n];
		jc = bts->j + c.jc[n];
		dice_sum += tab[ic][jc];
		tab[ic][jc] = 0;
		n++;
	}
	if (dice_sum <= 6)
		tab[bts->i][bts->j] = dice_sum;
}

// apply a non capture
void	ft_apply_non_capture(t_solver *solver, int tab[3][3],
	t_backtracking_state *bts)
{
	t_backtracking_state	next_state;
	int						tab_copy[3][3];

	ft_copy_board(tab_copy, tab);
	tab_copy[bts->i][bts->j] = 1;
	next_state = *bts;
	next_state.depth++;
	ft_solve_board(solver, tab_copy, &next_state);
}

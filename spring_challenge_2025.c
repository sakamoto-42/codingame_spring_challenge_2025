/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spring_challenge_2025.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:58:57 by julien            #+#    #+#             */
/*   Updated: 2025/04/08 16:47:15 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

int	main(void)
{
	t_solver				solver;
	t_backtracking_state	bts;

	solver.total_sum = 0;
	ft_init_capture(solver.c);
	scanf("%d", &solver.max_depth);
	ft_init_board(solver.tab);
	fprintf(stderr, "\nmax depth : %d\n\n", solver.max_depth);
	ft_print_board(solver.tab);
	bts.depth = 0;
	ft_solve_board(&solver, solver.tab, &bts);
	printf("%llu\n", solver.total_sum % (1ULL << 30));
	return (0);
}

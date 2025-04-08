/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spring_challenge_2025_raw.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:58:57 by julien            #+#    #+#             */
/*   Updated: 2025/04/08 16:47:06 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// CAPTURES MOVES
#define CAPTURE_LEFT_UP             0
#define CAPTURE_UP_RIGHT            1
#define CAPTURE_RIGHT_DOWN          2
#define CAPTURE_DOWN_LEFT           3
#define CAPTURE_UP_DOWN             4
#define CAPTURE_LEFT_RIGHT          5
#define CAPTURE_LEFT_UP_RIGHT       6
#define CAPTURE_LEFT_UP_DOWN        7
#define CAPTURE_UP_RIGHT_DOWN       8
#define CAPTURE_RIGHT_DOWN_LEFT     9
#define CAPTURE_LEFT_UP_RIGHT_DOWN  10

// nb_captures : number of 
// dices required for the capture
// ic[n] and jc[n] : positions (i and j)
// to the n neighbor (compared to the cell)
// see ft_init_capture_* functions
typedef struct s_capture
{
	int	nb_captures;
	int	ic[4];
	int	jc[4];
}				t_capture;

typedef struct s_solver
{
	unsigned long long	total_sum;
	t_capture			c[11];
	int					max_depth;
	int					tab[3][3];
}				t_solver;

typedef struct s_backtracking_state
{
	int	tab_copy[3][3];
	int	i;
	int	j;
	int	depth;
}				t_backtracking_state;

// debug.c
void	ft_print_board(int tab[3][3]);
// init_and_copy_board.c
void	ft_init_board(int tab[3][3]);
void	ft_copy_board(int dest[3][3], int src[3][3]);
// get_hash.c
int		ft_get_hash(int tab[3][3]);
// init_capture_1.c
void	ft_init_capture(t_capture *c);
void	ft_init_capture_left(int *i, int *j);
void	ft_init_capture_up(int *i, int *j);
void	ft_init_capture_right(int *i, int *j);
void	ft_init_capture_down(int *i, int *j);
// init_capture_2.c
void	ft_init_capture_left_up(t_capture *c);
void	ft_init_capture_up_right(t_capture *c);
void	ft_init_capture_right_down(t_capture *c);
void	ft_init_capture_down_left(t_capture *c);
void	ft_init_capture_up_down(t_capture *c);
// init_capture_3.c
void	ft_init_capture_left_right(t_capture *c);
void	ft_init_capture_left_up_right(t_capture *c);
void	ft_init_capture_left_up_down(t_capture *c);
void	ft_init_capture_up_right_down(t_capture *c);
void	ft_init_capture_right_down_left(t_capture *c);
// init_capture_4.c
void	ft_init_capture_left_up_right_down(t_capture *c);
// check_captures.c
bool	ft_check_captures(int tab[3][3], int i, int j, t_capture c[11]);
bool	ft_capture_is_possible(int tab[3][3], int i, int j, t_capture c);
// apply_capture.c
bool	ft_try_and_apply_captures(t_solver *solver, int tab[3][3],
			int tab_copy[3][3], t_backtracking_state *bts);
void	ft_apply_capture(int tab[3][3], t_backtracking_state *bts, t_capture c);
void	ft_apply_non_capture(t_solver *solver, int tab[3][3],
			t_backtracking_state *bts);
// solve_board.c
void	ft_solve_board(t_solver *solver, int tab[3][3],
			t_backtracking_state *bts);
// board_is_solved.c
bool	ft_board_is_solved(int tab[3][3], t_capture c[11]);

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

// compute the hash of one solution
int	ft_get_hash(int tab[3][3])
{
	int	i;
	int	j;
	int	hash;

	i = 0;
	j = 0;
	hash = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			hash = hash * 10 + tab[i][j];
			j++;
		}
		i++;
	}
	return (hash);
}

// init all possibles captures moves
void	ft_init_capture(t_capture *c)
{
	ft_init_capture_left_up(c);
	ft_init_capture_up_right(c);
	ft_init_capture_right_down(c);
	ft_init_capture_down_left(c);
	ft_init_capture_up_down(c);
	ft_init_capture_left_right(c);
	ft_init_capture_left_up_right(c);
	ft_init_capture_left_up_down(c);
	ft_init_capture_up_right_down(c);
	ft_init_capture_right_down_left(c);
	ft_init_capture_left_up_right_down(c);
}

void	ft_init_capture_left(int *i, int *j)
{
	*i = -1;
	*j = 0;
}

void	ft_init_capture_up(int *i, int *j)
{
	*i = 0;
	*j = -1;
}

void	ft_init_capture_right(int *i, int *j)
{
	*i = 1;
	*j = 0;
}

void	ft_init_capture_down(int *i, int *j)
{
	*i = 0;
	*j = 1;
}

void	ft_init_capture_left_up(t_capture *c)
{
	c[CAPTURE_LEFT_UP].nb_captures = 2;
	ft_init_capture_left(&c[CAPTURE_LEFT_UP].ic[0], &c[CAPTURE_LEFT_UP].jc[0]);
	ft_init_capture_up(&c[CAPTURE_LEFT_UP].ic[1], &c[CAPTURE_LEFT_UP].jc[1]);
}

void	ft_init_capture_up_right(t_capture *c)
{
	c[CAPTURE_UP_RIGHT].nb_captures = 2;
	ft_init_capture_up(&c[CAPTURE_UP_RIGHT].ic[0], &c[CAPTURE_UP_RIGHT].jc[0]);
	ft_init_capture_right(&c[CAPTURE_UP_RIGHT].ic[1],
		&c[CAPTURE_UP_RIGHT].jc[1]);
}

void	ft_init_capture_right_down(t_capture *c)
{
	c[CAPTURE_RIGHT_DOWN].nb_captures = 2;
	ft_init_capture_right(&c[CAPTURE_RIGHT_DOWN].ic[0],
		&c[CAPTURE_RIGHT_DOWN].jc[0]);
	ft_init_capture_down(&c[CAPTURE_RIGHT_DOWN].ic[1],
		&c[CAPTURE_RIGHT_DOWN].jc[1]);
}

void	ft_init_capture_down_left(t_capture *c)
{
	c[CAPTURE_DOWN_LEFT].nb_captures = 2;
	ft_init_capture_down(&c[CAPTURE_DOWN_LEFT].ic[0],
		&c[CAPTURE_DOWN_LEFT].jc[0]);
	ft_init_capture_left(&c[CAPTURE_DOWN_LEFT].ic[1],
		&c[CAPTURE_DOWN_LEFT].jc[1]);
}

void	ft_init_capture_up_down(t_capture *c)
{
	c[CAPTURE_UP_DOWN].nb_captures = 2;
	ft_init_capture_up(&c[CAPTURE_UP_DOWN].ic[0], &c[CAPTURE_UP_DOWN].jc[0]);
	ft_init_capture_down(&c[CAPTURE_UP_DOWN].ic[1], &c[CAPTURE_UP_DOWN].jc[1]);
}

void	ft_init_capture_left_right(t_capture *c)
{
	c[CAPTURE_LEFT_RIGHT].nb_captures = 2;
	ft_init_capture_left(&c[CAPTURE_LEFT_RIGHT].ic[0],
		&c[CAPTURE_LEFT_RIGHT].jc[0]);
	ft_init_capture_right(&c[CAPTURE_LEFT_RIGHT].ic[1],
		&c[CAPTURE_LEFT_RIGHT].jc[1]);
}

void	ft_init_capture_left_up_right(t_capture *c)
{
	c[CAPTURE_LEFT_UP_RIGHT].nb_captures = 3;
	ft_init_capture_left(&c[CAPTURE_LEFT_UP_RIGHT].ic[0],
		&c[CAPTURE_LEFT_UP_RIGHT].jc[0]);
	ft_init_capture_up(&c[CAPTURE_LEFT_UP_RIGHT].ic[1],
		&c[CAPTURE_LEFT_UP_RIGHT].jc[1]);
	ft_init_capture_right(&c[CAPTURE_LEFT_UP_RIGHT].ic[2],
		&c[CAPTURE_LEFT_UP_RIGHT].jc[2]);
}

void	ft_init_capture_left_up_down(t_capture *c)
{
	c[CAPTURE_LEFT_UP_DOWN].nb_captures = 3;
	ft_init_capture_left(&c[CAPTURE_LEFT_UP_DOWN].ic[0],
		&c[CAPTURE_LEFT_UP_DOWN].jc[0]);
	ft_init_capture_up(&c[CAPTURE_LEFT_UP_DOWN].ic[1],
		&c[CAPTURE_LEFT_UP_DOWN].jc[1]);
	ft_init_capture_down(&c[CAPTURE_LEFT_UP_DOWN].ic[2],
		&c[CAPTURE_LEFT_UP_DOWN].jc[2]);
}

void	ft_init_capture_up_right_down(t_capture *c)
{
	c[CAPTURE_UP_RIGHT_DOWN].nb_captures = 3;
	ft_init_capture_up(&c[CAPTURE_UP_RIGHT_DOWN].ic[0],
		&c[CAPTURE_UP_RIGHT_DOWN].jc[0]);
	ft_init_capture_right(&c[CAPTURE_UP_RIGHT_DOWN].ic[1],
		&c[CAPTURE_UP_RIGHT_DOWN].jc[1]);
	ft_init_capture_down(&c[CAPTURE_UP_RIGHT_DOWN].ic[2],
		&c[CAPTURE_UP_RIGHT_DOWN].jc[2]);
}

void	ft_init_capture_right_down_left(t_capture *c)
{
	c[CAPTURE_RIGHT_DOWN_LEFT].nb_captures = 3;
	ft_init_capture_right(&c[CAPTURE_RIGHT_DOWN_LEFT].ic[0],
		&c[CAPTURE_RIGHT_DOWN_LEFT].jc[0]);
	ft_init_capture_down(&c[CAPTURE_RIGHT_DOWN_LEFT].ic[1],
		&c[CAPTURE_RIGHT_DOWN_LEFT].jc[1]);
	ft_init_capture_left(&c[CAPTURE_RIGHT_DOWN_LEFT].ic[2],
		&c[CAPTURE_RIGHT_DOWN_LEFT].jc[2]);
}

void	ft_init_capture_left_up_right_down(t_capture *c)
{
	c[CAPTURE_LEFT_UP_RIGHT_DOWN].nb_captures = 4;
	ft_init_capture_left(&c[CAPTURE_LEFT_UP_RIGHT_DOWN].ic[0],
		&c[CAPTURE_LEFT_UP_RIGHT_DOWN].jc[0]);
	ft_init_capture_up(&c[CAPTURE_LEFT_UP_RIGHT_DOWN].ic[1],
		&c[CAPTURE_LEFT_UP_RIGHT_DOWN].jc[1]);
	ft_init_capture_right(&c[CAPTURE_LEFT_UP_RIGHT_DOWN].ic[2],
		&c[CAPTURE_LEFT_UP_RIGHT_DOWN].jc[2]);
	ft_init_capture_down(&c[CAPTURE_LEFT_UP_RIGHT_DOWN].ic[3],
		&c[CAPTURE_LEFT_UP_RIGHT_DOWN].jc[3]);
}

// check all captures
bool	ft_check_captures(int tab[3][3], int i, int j, t_capture c[11])
{
	int	m;

	m = 0;
	while (m < 11)
	{
		if (ft_capture_is_possible(tab, i, j, c[m]))
			return (false);
		m++;
	}
	return (false);
}

// test if a capture can be applied
// n : index of the neighbor
bool	ft_capture_is_possible(int tab[3][3], int i, int j, t_capture c)
{
	int	n;
	int	ic;
	int	jc;
	int	dice_sum;

	n = 0;
	dice_sum = 0;
	while (n < c.nb_captures)
	{
		ic = i + c.ic[n];
		jc = j + c.jc[n];
		if (ic < 0 || ic >= 3 || jc < 0 || jc >= 3)
			return (false);
		if (tab[ic][jc] == 0)
			return (false);
		dice_sum += tab[ic][jc];
		n++;
	}
	if (dice_sum > 6)
		return (false);
	return (true);
}

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

int	main(void)
{
	t_solver				solver;
	t_backtracking_state	bts;

	solver.total_sum = 0;
	ft_init_capture(solver.c);
	scanf("%d", &solver.max_depth);
	ft_init_board(solver.tab);
	//fprintf(stderr, "\nmax depth : %d\n\n", solver.max_depth);
	//ft_print_board(solver.tab);
	bts.depth = 0;
	ft_solve_board(&solver, solver.tab, &bts);
	printf("%llu\n", solver.total_sum % (1ULL << 30));
	return (0);
}

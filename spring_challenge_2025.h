/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spring_challenge_2025.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:06:30 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:19:09 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRING_CHALLENGE_2025_H
# define SPRING_CHALLENGE_2025_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

// CAPTURES MOVES
# define CAPTURE_LEFT_UP             0
# define CAPTURE_UP_RIGHT            1
# define CAPTURE_RIGHT_DOWN          2
# define CAPTURE_DOWN_LEFT           3
# define CAPTURE_UP_DOWN             4
# define CAPTURE_LEFT_RIGHT          5
# define CAPTURE_LEFT_UP_RIGHT       6
# define CAPTURE_LEFT_UP_DOWN        7
# define CAPTURE_UP_RIGHT_DOWN       8
# define CAPTURE_RIGHT_DOWN_LEFT     9
# define CAPTURE_LEFT_UP_RIGHT_DOWN  10

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

#endif
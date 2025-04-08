/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_capture_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:27:49 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:35:14 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

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

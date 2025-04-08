/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_capture_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:28:10 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:28:15 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

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

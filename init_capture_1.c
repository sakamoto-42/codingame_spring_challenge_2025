/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_capture_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:26:58 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:27:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

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

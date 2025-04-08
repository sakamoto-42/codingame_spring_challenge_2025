/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_captures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:28:32 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:30:04 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

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
// k : index of the neighbor
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

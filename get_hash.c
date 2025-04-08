/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 16:25:56 by juduchar          #+#    #+#             */
/*   Updated: 2025/04/08 16:49:46 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "spring_challenge_2025.h"

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
	fprintf(stderr, "%d\n", hash);
	return (hash);
}

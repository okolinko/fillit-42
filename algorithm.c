/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 00:02:46 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/03 04:41:21 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		enable_position(t_cord *cordinat, char **map, int size, t_pos square)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (cordinat->y[i] + square.y >= size ||
				cordinat->x[i] + square.x >= size ||
				map[cordinat->y[i] + square.y][cordinat->x[i] +
				square.x] != '.')
			return (0);
	return (1);
}

void	del_cordinat(t_cord *cordinat, char **map, int size)
{
	int		y;
	int		x;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			if (map[y][x] == cordinat->letter)
				map[y][x] = '.';
	}
}

void	fill(char **map, t_cord *cordinat, t_pos square)
{
	int i;

	i = -1;
	while (++i < 4)
		map[cordinat->y[i] + square.y][cordinat->x[i] +
		square.x] = cordinat->letter;
}

void	change_position(t_pos *square, int size)
{
	if (square->x == size - 1)
	{
		square->y++;
		square->x = 0;
	}
	else
		square->x++;
}

int		algorithm(t_cord *cordinat, char **map, int size, t_pos square)
{
	t_pos	zero;

	if (enable_position(cordinat, map, size, square))
	{
		fill(map, cordinat, square);
		if (cordinat->next->letter == '\0')
			return (1);
		zero.x = 0;
		zero.y = 0;
		if (!algorithm(cordinat->next, map, size, zero))
		{
			del_cordinat(cordinat, map, size);
			change_position(&square, size);
			return (algorithm(cordinat, map, size, square));
		}
		return (1);
	}
	else
	{
		if (square.y == size - 1 && square.x == size - 1)
			return (0);
		change_position(&square, size);
		return (algorithm(cordinat, map, size, square));
	}
}

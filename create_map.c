/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:45:45 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/03 04:40:50 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_map(char **map, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_putendl(map[i]);
}

void	clear(char **map, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(map[i]);
}

char	**create_map(int size)
{
	char	**map;
	int		n;
	int		k;
	int		l;

	n = -1;
	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	map[size] = 0;
	while (++n < size)
		map[n] = ft_strnew(size + 1);
	l = n;
	n = -1;
	while (++n < l)
	{
		k = -1;
		while (++k < size)
			map[n][k] = '.';
	}
	return (map);
}

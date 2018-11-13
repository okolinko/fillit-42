/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 19:20:52 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/08 23:11:10 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_error(void)
{
	write(1, "error\n", 6);
	return (0);
}

char		*ft_reader(char *test_file)
{
	int		fd;
	int		read_stat;
	int		i;
	char	tmp[545];
	char	buffer[BUFF_SIZE + 1];

	i = 0;
	fd = open(test_file, O_RDONLY);
	if (fd < 0)
	{
		ft_error();
		return (0);
	}
	while ((read_stat = read(fd, buffer, BUFF_SIZE)))
	{
		tmp[i] = buffer[0];
		if (i > 545)
		{
			ft_error();
			return (0);
		}
		i++;
	}
	tmp[i] = '\0';
	return (ft_strdup(tmp));
}

void		ft_fillit_result(char *read)
{
	t_cord		*cordinat;
	t_pos		square;
	int			tetrominoes;
	int			size;
	char		**map;

	square.x = 0;
	square.y = 0;
	size = 1;
	tetrominoes = ft_check(read);
	while (size * size < tetrominoes * 4)
		size++;
	cordinat = cordinates(read);
	map = create_map(size);
	while (!algorithm(cordinat, map, size, square))
	{
		clear(map, size);
		size++;
		map = create_map(size);
	}
	show_map(map, size);
}

int			main(int argc, char **argv)
{
	char	*read;
	int		i;
	int		connect;
	int		sharp;

	i = -1;
	connect = 0;
	read = NULL;
	sharp = 0;
	if (argc != 2)
	{
		write(1, "usage: invalid files\n", 22);
		return (0);
	}
	else
	{
		read = ft_reader(argv[1]);
		if (read == 0)
			return (0);
	}
	if (!(validation(read, i, connect, sharp)) || (ft_check(read) == 0))
		ft_error();
	else
		ft_fillit_result(read);
	return (0);
}

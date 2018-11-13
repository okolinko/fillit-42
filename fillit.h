/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 22:02:33 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/03 02:59:43 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef	struct	s_cord
{
	int				x[4];
	int				y[4];
	char			letter;
	struct s_cord	*next;
}				t_cord;

typedef	struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

int				algorithm(t_cord *cordinat, char **map, int size, t_pos square);
char			*validation(char *str, int i, int connect, int sharp);
int				ft_sharp(char *str, int i);
t_cord			*cordinates(char *str);
void			fill_struct(t_cord *cordinat, char	*str);
void			show_map(char **map, int size);
void			clear(char **map, int size);
void			x_changing(t_cord *cordinat);
void			y_changing(t_cord *cordinat);
char			**create_map(int j);
int				ft_error();
int				ft_check(char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 19:34:37 by hmuravch          #+#    #+#             */
/*   Updated: 2018/06/03 04:47:34 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	y_changing(t_cord *cordinat)
{
	t_cord	*tmp;
	int		i;
	int		k;

	tmp = cordinat;
	while (tmp->next != NULL)
	{
		{
			k = 0;
			i = -1;
			while (++i < 4)
			{
				if (tmp->y[i] != 0)
					k++;
				if (k == 4)
					while (i >= 0)
					{
						tmp->y[i] -= 1;
						k--;
						i--;
					}
			}
		}
		tmp = tmp->next;
	}
}

void	x_changing(t_cord *cordinat)
{
	t_cord	*tmp;
	int		i;
	int		k;

	tmp = cordinat;
	while (tmp->next != NULL)
	{
		{
			k = 0;
			i = -1;
			while (++i < 4)
			{
				if (tmp->x[i] != 0)
					k++;
				if (k == 4)
					while (i >= 0)
					{
						tmp->x[i] -= 1;
						k--;
						i--;
					}
			}
		}
		tmp = tmp->next;
	}
}

void	fill_struct(t_cord *cordinat, char *str)
{
	t_cord	*tmp;
	int		d;
	int		l;

	d = 0;
	l = 0;
	tmp = cordinat;
	while (d < 20)
	{
		if (str[d] == '#')
		{
			tmp->y[l] = d / 5;
			tmp->x[l] = d % 5;
			l++;
		}
		d++;
	}
}

t_cord	*cordinates(char *str)
{
	t_cord	*cordinat;
	t_cord	*tmp;
	char	letter;
	int		len;

	len = ft_strlen(str);
	letter = 'A';
	cordinat = (t_cord *)malloc(sizeof(t_cord));
	tmp = cordinat;
	while (len > 0)
	{
		tmp->next = (t_cord *)malloc(sizeof(t_cord));
		fill_struct(tmp, str);
		tmp->letter = letter++;
		tmp = tmp->next;
		len -= 21;
		str += 21;
	}
	tmp->next = NULL;
	x_changing(cordinat);
	y_changing(cordinat);
	return (cordinat);
}

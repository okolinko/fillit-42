/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:03:01 by akolinko          #+#    #+#             */
/*   Updated: 2018/06/08 23:11:18 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					check(char s1, char s2, char s3, char s4)
{
	if (s1 != '#' && s2 != '#' && s3 != '#' && s4 != '#')
		return (1);
	return (0);
}

int					ft_sharp(char *str, int i)
{
	int connect;

	connect = 0;
	if (str[i - 1] == '#' && str[i + 1] == '#')
		connect++;
	if (str[i - 5] == '#' && str[i + 5] == '#')
		connect++;
	if (str[i - 5] == '#' && str[i + 1] == '#')
		connect++;
	if (str[i + 5] == '#' && str[i - 1] == '#')
		connect++;
	if (str[i + 5] == '#' && str[i + 1] == '#')
		connect++;
	return (connect);
}

char				*validation(char *str, int i, int connect, int sharp)
{
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
		{
			if (check(str[i - 5], str[i + 5], str[i - 1], str[i + 1]))
				return (NULL);
			connect += ft_sharp(str, i);
			sharp++;
		}
		if (str[i] == '\n' && ((i + 1) % 5 != 0))
			return (NULL);
		if ((i + 1) % 20 == 0)
		{
			if (sharp != 4 || connect < 1)
				return (NULL);
			if (str[i + 1] == '\0')
				break ;
			str++;
			connect = 0;
			sharp = 0;
		}
	}
	if (((i - 19) % 20 != 0))
		return (NULL);
	return (str);
}

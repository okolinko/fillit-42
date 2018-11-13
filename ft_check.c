/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akolinko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:34:22 by akolinko          #+#    #+#             */
/*   Updated: 2018/06/08 23:11:42 by hmuravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_check(char *read)
{
	int dot;
	int diese;
	int endl;

	dot = 0;
	diese = 0;
	endl = 0;
	while (*read)
	{
		if (*read == '.')
			dot++;
		else if (*read == '#')
			diese++;
		else if (*read == '\n')
			endl++;
		else
			return (0);
		read++;
	}
	if (diese < 4 || dot % 4 || diese % 4 || (endl + 1) % 5)
		return (0);
	return (diese / 4);
}

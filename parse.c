/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 22:59:25 by solefir           #+#    #+#             */
/*   Updated: 2019/04/20 16:01:31 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	add_figure(char *buf, t_tetris *figures)
{
	int i;
	int j;
	int first_x;
	int first_y;

	i = 0;
	j = 0;
	while (j < 4)
	{
		if (buf[i] == '#' && j == 0)
		{
			first_x = i % 5;
			first_y = i / 5;
			j++;
		}
		else if (buf[i] == '#')
		{
			printf("[i = %d]\n", i);
			figures->x[j - 1] = (i % 5) - first_x;
			printf("[x = %d]\n", figures->x[j - 1]);
			figures->y[j - 1] = (i / 5) - first_y;
			printf("[y = %d]\n", figures->y[j - 1]);
			j++;
		}
		i++;
	}
}

void		parse(char *buf, t_tetris *figures)
{
	int i;
	char l;

	i = 0;
	l = 'A';
	while (buf[i])
	{
		add_figure(buf + i, figures);
		i += 20;
		figures->letter = l;
		l++;
		if (buf[i] == '\n')
			i++;
		if (buf[i] != '\0')
		{
			figures->next = (t_tetris*)malloc(sizeof(t_tetris));
			figures = figures->next;
			figures->next = NULL;
		}
	}
}

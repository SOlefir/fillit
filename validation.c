/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:40:17 by solefir           #+#    #+#             */
/*   Updated: 2019/04/20 15:49:27 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void	check_figure(char *buf, int i, int *figure) // форма фигуры. считаем совпадения
{
	if (buf[i] == '#')
	{
		if ((i + 1) % 5 < 4 && buf[i + 1] == '#')
			(*figure)++;
		if (i % 5 != 4 && i + 5 < 19 && buf[i + 5] == '#')
			(*figure)++;
	}
}

static inline void	count_char(char c, int *dot, int *nl, int *hash) //ин лайн, чтобы это был не вызов функции, а конструкция
{
	if (c == '.')
		(*dot)++;
	else if (c == '#')
		(*hash)++;
	else if (c == '\n')
		(*nl)++;
}

static _Bool 			validation_figure(char *buf, int i)
{
	int	dot;
	int	nl;
	int	hash;
	int figure;

	dot = 0;
	nl = 0;
	hash = 0;
	figure = 0;
	while (i < 20)
	{
		count_char(buf[i], &dot, &nl, &hash);
		check_figure(buf, i, &figure);
		i++;
	}
	if ((figure != 3 && figure != 4) || buf[4] != '\n' || buf[9] != '\n' || // количество символов и
	buf[14] != '\n' || buf[19] != '\n' || dot != 12 || hash != 4 || nl != 4) //костыльчик на проверку порядка \n
		return (1);
	return (0);
}

void				validation(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (validation_figure(buf + i, 0)) //каждые 20 символов, пропуская переносы строки между фигурами
		{
			free(buf);
			error();
		}
		i += 20;
		if (buf[i] == '\n')
			i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetramin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:30:34 by solefir           #+#    #+#             */
/*   Updated: 2019/04/18 00:54:38 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_form(char *input)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (input[i] != '\0' || input[j] != '\0')
	{
		while (input[i] != '#' && input[i] != '\0')
			i++;
		j = i + 1;
		while (input[j] != '#' && input[j] != '\0')
			j++;
		if (j - i != 5 && j - i != 1 && input[j] == '\0')
			return(-1);
		i = j;
		i++;
	}
	return (1);
}

static int	count_char(char *input, int len, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i <= len)
	{
		if (input[i] == c)
			count++;
		i++;
	}
	printf("(%d)", count);
	return (count);
}

int		valid_tetraminos(char *input, int len)
{
	int	hash;
	int	n;
	int dot;

	hash = count_char(input, len, '#') % 4; 
	n = (count_char(input, len, '\n') + 2) % 5;
	dot = count_char(input, len, '.') % 3;
	if ((dot + hash + n) != 0) //опред. валидное кол-во символов
		return (-1);
	if (valid_form(input) < 0) // правильная ли форма фигуры
		return (-1);
	return (1);
}

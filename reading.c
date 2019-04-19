/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:18:29 by solefir           #+#    #+#             */
/*   Updated: 2019/04/19 22:58:39 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reading(int fd, t_tetris *figures)
{
	int		size;
	char 	*buf;

	buf = (char *)malloc(546);
	size = read(fd, buf, 546);
	close(fd);
	if (size <= 0 || size > 545 || size < 19 || (size - 20) % 21 != 0) //проверка на кол-во символов
		error();
	buf[size] = '\0';
	validation(buf);
	parse(buf, figures);
	free(buf);
}

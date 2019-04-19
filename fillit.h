/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:49:28 by solefir           #+#    #+#             */
/*   Updated: 2019/04/19 22:59:01 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h> //del

typedef struct	s_tetris	t_tetris;

struct	s_tetris
{
	int			x[4];
	int			y[4];
	t_tetris	*next;
};

void	error(void);
void	reading(int fd, t_tetris *figures);
void	validation(char *buf);
void	parse(char *buf, t_tetris *figures);

#endif
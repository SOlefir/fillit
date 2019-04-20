/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:49:28 by solefir           #+#    #+#             */
/*   Updated: 2019/04/20 18:01:41 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h> //del

typedef struct	s_tetris	t_tetris;
typedef struct	s_map		t_map;

struct	s_map
{
	int		i;
	int		j;
	int		size;
	char	**map;
};

struct	s_tetris
{
	int			x[3];
	int			y[3];
	char 		letter;
	t_tetris	*next;
};

void	error(void);
void	reading(int fd, t_tetris *figures);
void	validation(char *buf);
void	parse(char *buf, t_tetris *figures);
void	solve(t_tetris *figures);
void	free_map(t_map *map);
void	create_map(t_map *map);

#endif
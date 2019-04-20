/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:05:08 by solefir           #+#    #+#             */
/*   Updated: 2019/04/20 18:26:42 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		put_figure(t_map *map, t_tetris *f, _Bool put)
{
	if (put)
	{
		map->map[map->i][map->j] = f->letter;
		map->map[map->i + f->y[0]][map->j + f->x[0]] = f->letter;
		map->map[map->i + f->y[1]][map->j + f->x[1]] = f->letter;
		map->map[map->i + f->y[2]][map->j + f->x[2]] = f->letter;
	}
	else
	{
		map->map[map->i][map->j] = '.';
		map->map[map->i + f->y[0]][map->j + f->x[0]] = '.';
		map->map[map->i + f->y[1]][map->j + f->x[1]] = '.';
		map->map[map->i + f->y[2]][map->j + f->x[2]] = '.';
	}
}

static _Bool	check_place(t_map *map, t_tetris *f)
{
	if (f->x[0] + map->j >= 0 && f->x[1] + map->j >= 0 &&
		f->x[2] + map->j >= 0 && f->y[0] + map->i >= 0 &&
		f->y[1] + map->i >= 0 && f->y[2] + map->i >= 0 &&
		f->x[0] + map->j < map->size && f->x[1] + map->j < map->size &&
		f->x[2] + map->j < map->size && f->y[0] + map->i < map->size &&
		f->y[1] + map->i < map->size && f->y[2] + map->i < map->size &&
		map->map[map->i][map->j] == '.' &&
		map->map[map->i + f->y[0]][map->j + f->x[0]] == '.' &&
		map->map[map->i + f->y[1]][map->j + f->x[1]] == '.' &&
		map->map[map->i + f->y[2]][map->j + f->x[2]] == '.')
		return (1);
	return (0);
}

static _Bool	backtracking(t_map map, t_tetris *figures)
{
	if (figures == NULL)
		return (0);
	map.i = 0;
	while (map.map[map.i])
	{
		map.j = 0;
		while (map.map[map.i][map.j])
		{
			if (check_place(&map, figures))
			{
				put_figure(&map, figures, 1);
				if (backtracking(map, figures->next) == 0)
					return (0);
				else
					put_figure(&map, figures, 0);
			}
			map.j++;
		}
		map.i++;
	}
	return (1);
}

void			solve(t_tetris *figures)
{
	t_map	map;

	map.size = 2;
	map.map = NULL;
	create_map(&map);
	while (backtracking(map, figures))
	{
		map.size++;
		create_map(&map);
	}
	map.i = 0;
	while (map.map[map.i])
	{
		write(1, map.map[map.i], map.size);
		write(1, "\n", 1);
		map.i++;
	}
	free_map(&map);
}

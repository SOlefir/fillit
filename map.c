/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:00:45 by solefir           #+#    #+#             */
/*   Updated: 2019/04/20 18:01:39 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(t_map *map)
{
	map->i = 0;
	while (map->map[map->i])
	{
		free(map->map[map->i]);
		map->i++;
	}
	free(map->map);
}

void	create_map(t_map *map)
{
	if (map->map != NULL)
		free_map(map);
	map->i = 0;
	map->map = (char**)malloc(sizeof(char*) * (map->size + 1));
	while (map->i < map->size)
	{
		map->j = 0;
		map->map[map->i] = (char*)malloc(map->size + 1);
		while (map->j < map->size)
		{
			map->map[map->i][map->j] = '.';
			map->j++;
		}
		map->map[map->i][map->j] = '\0';
		map->i++;
	}
	map->map[map->i] = NULL;
}

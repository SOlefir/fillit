/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:13:47 by solefir           #+#    #+#             */
/*   Updated: 2019/04/20 15:21:11 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

int		main(int ac, char **av)
{
	t_tetris	figures;

	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (0);
	}
	figures.next = NULL;
	reading(open(av[1], O_RDONLY), &figures);
	//solve(&figures);
	return (0);
}
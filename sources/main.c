/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:53:01 by solefir           #+#    #+#             */
/*   Updated: 2019/04/18 01:33:37 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void 		error(char *input, char *c)
{
	free(input);
	ft_putstr(c);
	ft_putstr("error\n"); //вообще можно принимать флаги и описывать ошибку. но вроде как надо просто эрор по заданию
}

static int 		read_file(int filledesc, char *input) // чтение из буфера в структуру и валидация файла.
{
	int		len;
    int		count;
	
	len = read(filledesc, input, 546);
    if (filledesc <= 0 || len <= 0 || len > 545 || len < 19) // проверка файла и кол-во фигур
	{
		close(filledesc);
		return (-1);
	}
	close(filledesc);
	if ((count = (len - 20) % 21) != 0) //валид на кол-во символов
		return (-1);
	input[len] = '\0';
	return(len);
}


int				main(int argc, char **argv)
{
    // t_tetraminosec *tetris;
    char           *input;
    int             len;
	int				i;

	i = 0;
	input = (char*)malloc(sizeof(char) * 546); // 546 - макс валидное кол-во символов. 
	len = read_file(open(argv[1], O_RDONLY), input);//мб стоит потом обрезать строку если она будет меньше len (ft_strcut?)
	if (argc != 2 || len <= 0)
		error(input, "file\n");
	if ((i = valid_tetraminos(input, len)) < 0)
		error(input, "figure\n");
	// tetris = write_in_lists(input);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:53:01 by solefir           #+#    #+#             */
/*   Updated: 2019/04/18 00:52:55 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void static		error(char **input)
{
	free(input);
	ft_putstr("error\n");//вообще можно принимать флаги и описывать ошибку. но вроде как надо просто эрор по заданию
}

int static		read_file(int filledesc, char *input) // чтение из буфера в структуру и валидация файла.
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
	if ((count = (len - 19) % 21) != 0) //валид на кол-во символов
		return (-1);
	input[len] = '\0';
	return(len);
}


int				main(int argc, char **argv)
{
    t_tetraminosec *tetris;
    t_tetraminosec *head;
    char           *input;
    int             len;
	int				i;

	i = 0;
	input = (char*)malloc(sizeof(char) * 546); // 546 - макс валидное кол-во символов. 
	len = read_file(open(argv[1], O_RDONLY), input);//мб стоит потом обрезать строку если она будет меньше len (ft_strcut?)
	if (argc != 2 || len <= 0)
		error(&input);
    if (!(tetris = (t_tetraminosec*)ft_memalloc(sizeof(t_tetraminosec))))
		error(&input);
    head = tetris;
	if ((i = valid_tetraminos(input, len)) < 0)
		error(&input);
	return (0);
}

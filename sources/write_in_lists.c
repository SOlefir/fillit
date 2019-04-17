/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_in_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 01:00:05 by solefir           #+#    #+#             */
/*   Updated: 2019/04/18 01:55:03 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetraminosec		*create_list(char *input, char letter)
{
	t_tetraminosec	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->letter = letter;
	while(count <= 4)
	{
		if (input[i] == '.')
			list->tetraminos[i] = ' ';
		if (input[i] == '#')
			list->tetraminos[i] = letter;
		if (input[i] == '\n')
		{
			count++;
			list->tetraminos[i] = input[i];
		}
		i++
	}
}

t_tetraminosec		*write_in_lists(char *input)
{
	t_tetraminosec	*temp;
	t_tetraminosec	*head;
	int				i;
	int				count;
	char			letter;

	i = 0;
	count = 0;
	letter = '65';
	while (input[i] != '\0')
	{
		if (input[i] == '#')
		{
			if (letter == '65')
			{
				head = create_list(input, letter);
				temp = head;
			}
			else
			{
				temp->next = create_list(input, letter); //возвращает адрес на лист с фигуркой и литерой
				temp = temp->next;
			}
		}
		if (input[i] == '\n')
			count++;
		if (count => 4)
		{
			letter++;
			count = 0;
		}
		i++;
		
	}
	return (head);
}
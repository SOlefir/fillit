/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:05:44 by mzhelezn          #+#    #+#             */
/*   Updated: 2019/04/18 00:33:30 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "./libft.h"

typedef struct s_tetraminosec t_tetraminosec;

struct s_tetraminosec
{
    char            letter;
    char            *tetraminos;
    t_tetraminosec  *next;
};

int		valid_tetraminos(char *input, int len);
void	*ft_memalloc(size_t size);
void	ft_putstr(char const *s);
void	ft_putchar(char c);


#endif

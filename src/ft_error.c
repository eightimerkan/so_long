/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:31:55 by edolgun           #+#    #+#             */
/*   Updated: 2023/01/14 01:52:11 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error2(t_list *d, int num)
{
	d->moves++;
	d->moves--;
	if (num == 8)
		write(1, "►Map contains incorrect characters.\n", 39);
	if (num == 9)
		write(1, "►The map is not rectangular\n", 31);
}

void	ft_error(t_list *d, int num)
{
	write(1, "ERROR\n", 7);
	if (num > 7)
		ft_error2(d, num);
	if (num == 1)
		write(1, "►There is no wall in front of the queue.\n", 44);
	if (num == 2)
		write(1, "►There is no wall at the end of the line.\n", 45);
	if (num == 3)
		write(1, "►No wall in the first row\n", 29);
	if (num == 4)
		write(1, "►No wall in the last line\n", 29);
	if (d->consum < 1 && num == 5)
		write(1, "►No Bait!\n", 13);
	if (d->player != 1 && num == 5)
		write(1, "►There must be only one character on the map. \n", 50);
	if (d->ex < 1 && num == 5)
		write(1, "►The map must contain an output. \n", 37);
	if (num == 6)
		write(1, "►The file does not have the correct extension.\n", 50);
	if (num == 7)
		write(1, "►The map is not rectangular.\n", 32);
	ft_free(d);
}

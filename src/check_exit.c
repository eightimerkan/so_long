/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:31:47 by edolgun           #+#    #+#             */
/*   Updated: 2023/01/14 01:59:17 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_exit(t_list *d, char letter)
{
	if (letter == 'E' && d->consum == 0)
	{
		write(1, "Congratulations, you won!!! \n", 30);
		ft_free(d);
	}
	if (letter == 'E' && d->consum != 0)
	{
		write(1, "You need to collect all the bait\n", 34);
		return (1);
	}
	else
		return (0);
}

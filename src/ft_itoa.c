/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edolgun <edolgun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:38:26 by edolgun           #+#    #+#             */
/*   Updated: 2023/01/13 21:38:26 by edolgun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

long int	static	ft_baseexponente(long int base, size_t exp)
{
	long int	nbr;

	if (exp == 0)
		return (1);
	nbr = base;
	while (--exp)
		nbr *= base;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	digitos;

	digitos = 1;
	while (n / ft_baseexponente(10, digitos))
		digitos++;
	nbr = (char *)ft_calloc(digitos + 1, sizeof(char));
	if (!nbr)
		return (0);
	while (--digitos)
	{
		nbr[digitos] = (char)((n % 10) + '0');
		n /= 10;
	}
	nbr[digitos] = (char)((n % 10) + '0');
	return (nbr);
}

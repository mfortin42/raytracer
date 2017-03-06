/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:42:12 by bkabbas           #+#    #+#             */
/*   Updated: 2015/11/26 22:28:14 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	tab[10];
	int		lengthtab;
	char	digit;

	if (nb == 0)
		ft_putchar_fd('0', fd);
	if (nb < 0)
		ft_putchar_fd('-', fd);
	digit = 0;
	lengthtab = 0;
	while (nb != 0)
	{
		digit = (nb % 10);
		if (nb < 0)
			digit *= -1;
		tab[lengthtab] = digit + '0';
		lengthtab++;
		nb /= 10;
	}
	lengthtab--;
	while (lengthtab >= 0)
		ft_putchar_fd(tab[lengthtab--], fd);
}

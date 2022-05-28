/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vambassa <vambassa@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:59:15 by vambassa          #+#    #+#             */
/*   Updated: 2021/10/09 13:59:51 by vambassa         ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a *= -1;
	}
	if (a / 10)
		ft_putnbr_fd(a / 10, fd);
	ft_putchar_fd(a % 10 + '0', fd);
}

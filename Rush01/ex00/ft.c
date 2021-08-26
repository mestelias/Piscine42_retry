/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:47:39 by nle-bret          #+#    #+#             */
/*   Updated: 2021/08/17 10:40:24 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_print_error(void)
{
	ft_putstr("Error\n");
	return (0);
}

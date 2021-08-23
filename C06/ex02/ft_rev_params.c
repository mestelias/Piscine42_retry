/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:53:26 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/05 20:23:38 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;

	i = argc - 1;
	if (argc == 0)
		return (0);
	while (i >= 1)
	{
		ft_rev_params(argv[i]);
		i--;
	}
	return (0);
}

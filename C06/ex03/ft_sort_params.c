/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:14:52 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/05 20:24:24 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_params(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_sort_params(int argc, char **argv, int i, int c)
{
	char	*tmp;
	int		nb;

	nb = 0;
	while (nb <= argc)
	{
		while (argv[i])
		{
			while (argv[c])
			{
				if (ft_strcmp(argv[i], argv[c]) < 0)
				{
					tmp = argv[i];
					argv[i] = argv[c];
					argv[c] = tmp;
				}
				c++;
			}
			i++;
			c = 1;
		}
		nb++;
		i = 1;
	}
}

int	main(int argc, char **argv)
{
	int		j;
	int		i;
	int		c;

	i = 1;
	c = 2;
	j = 1;
	if (argc <= 1)
		return (0);
	ft_sort_params(argc, argv, i, c);
	while (argv[j])
	{
		ft_print_params(argv[j]);
		j++;
	}
	return (0);
}

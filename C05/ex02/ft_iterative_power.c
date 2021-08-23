/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 21:26:34 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/04 21:29:26 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int		nbr;

	nbr = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power != 1)
	{
		nb *= nbr;
		power--;
	}
	return (nb);
}

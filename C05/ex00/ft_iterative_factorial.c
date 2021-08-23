/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:40:18 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/04 21:17:31 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int		fact;
	int		i;

	i = 1;
	fact = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	while (i <= nb)
	{
		fact = fact * i;
		i++;
	}
	return (fact);
}

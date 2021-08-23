/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmestou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 14:28:24 by elmestou          #+#    #+#             */
/*   Updated: 2021/08/04 12:36:51 by elmestou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ln;

	i = 0;
	ln = 0;
	while (src[ln] != '\0')
		ln++;
	if (size == 0)
		return (ln);
	while ((i < ln) && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ln);
}

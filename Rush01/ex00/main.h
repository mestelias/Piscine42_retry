/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:47:12 by nle-bret          #+#    #+#             */
/*   Updated: 2021/08/15 18:54:51 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>

# define MAP_SIZE 4

# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_print_error(void);

int		is_digit(char c);
int		is_separator(char c);

int		check_doubles(int map[4][4], int size, int pos[2]);
int		check_up_views(int map[4][4], int views[4][4], int size, int pos[2]);
int		check_down_views(int map[4][4], int views[4][4], int size, int pos[2]);
int		check_left_views(int map[4][4], int views[4][4], int size, int pos[2]);
int		check_right_views(int map[4][4], int views[4][4], int size, int pos[2]);

void	initialize_map(int map[4][4], int size);
int		solve_map(int map[4][4], int views[4][4], int size, int pos[2]);
void	print_map(int tab[4][4]);

#endif

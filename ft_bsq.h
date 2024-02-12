/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:00:25 by librooke          #+#    #+#             */
/*   Updated: 2024/02/12 16:11:25 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_point.h"
/*
	-------------------HOW IT SHOULD BE DONE-------------------
	1. get the map.
	2. get the characters that represent 
At each scan do this:

    If the cell has 0 assign count=0
    If the cell has 1 and is an edge cell 
	(bottom or right edge only), assign count=1
    For all other cells, check the count of 
	the cell on its right, right-below, and 
	below. Take the min of them and add 1 and 
	assign that to the count. Keep a global 
	max_count variable to keep track of the 
	max count so far

*/

int	ft_atoi(char *str)
{
	int	neg;
	int	num;
	int	i;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	ft_min(int a, int b, int c)
{
	if (a > b)
	{
		if (b < c)
			return (b + 1);
		else
			return (c + 1);
	}
	else
	{
		if (a < c)
			return (a + 1);
		else
			return (c + 1);
	}
}

/* 	[0] = empty character, 		[1] = obstacle character,
	[2] = full character								*/
char	*get_chars(char *path)
{
	char	*chars;
	FILE	*map;

	map = fopen(path, "r");
	chars = (char *)malloc(sizeof(char) * 15);
	fgets(chars, 15, map);
	while (*chars >= '0' && *chars <= '9')
		chars++;
	return (chars);
}

int	get_map_size(char *path)
{
	char	*chars;
	FILE	*map;
	int		j;

	map = fopen(path, "r");
	chars = (char *)malloc(sizeof(char) * 15);
	fgets(chars, 15, map);
	j = ft_atoi(chars);
	free(chars);
	return (j);
}

FILE	*get_map_file(char *path)
{
	return (fopen(path, "r"));
}


char	**make_map_from_file(char **cmap, FILE *map, int size)
{
	int		i;

	i = 0;
	fgets(cmap[i], 15, map);
	while (fgets(cmap[i++], size+2, map) != NULL)
	{
	}
	return (cmap);
}

char	**make_nonfile_map(char *path)
{
	FILE	*map;
	char	*chars;
	char	**cmap;
	int		size;
	int		i;

	i =	0;
	chars = get_chars(path);
	size = get_map_size(path);
	map = get_map_file(path);
	cmap = (char **)malloc(sizeof((char *)NULL)*(size));
	while (i < size)
	{
		cmap[i++] = (char *)malloc(sizeof(char)*size);
	}
	return (make_map_from_file(cmap, map, size));
}

int	**make_2d_arr(int size)
{
	int	**cmap;
	int i;

	i = 0;
	cmap = (int **)malloc(sizeof((int *)NULL)*(size));
	while (i < size)
	{
		cmap[i++] = (int *)malloc(sizeof(int)*size+1);
	}
	return (cmap);
}






/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:05:16 by librooke          #+#    #+#             */
/*   Updated: 2024/02/12 16:11:52 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_bsq.h"
#include "ft_point.h"
/*At each scan do this:
    If the cell has 0 assign count=0
    If the cell has 1 and is an edge cell (bottom or right edge only), assign count=1
    For all other cells, check the count of the cell on its right, right-below, and 
	below. Take the min of them and add 1 and assign that to the count. Keep a global 
	max_count variable to keep track of the max count so far*/
void scan1(int **count_map, char **normal_map, char *chars, int size)
{
	int i;
	int j;

	printf("scan1 ran\n");
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (normal_map[i][j] == chars[1])
				count_map[i][j] = 0; 
			else if ((i == size - 1 || j == size - 1) && normal_map[i][j] == chars[0])
				count_map[i][j] = 1;
			else
			{
				*(&(count_map[i][j])) = 0;
			}
			j++;
		}
		i++;
	}
}

struct s_point scan2(int **count_map, char **normal_map,char *chars, int size)
{
	int	i;
	int	j;
	struct s_point max;

	printf("scan2 ran\n");
	i = size - 2;
	while (i >= 0)
	{
		j = size - 2;
		while (j >= 0)
		{
			if (normal_map[i][j] == chars[0])
				count_map[i][j] = ft_min(count_map[i + 1][j], count_map[i][j + 1], count_map[i + 1][j + 1]);
			if (max.val < count_map[i][j])
				{
					max.x = i; 
					max.y = j;
					max.val = count_map[i][j];
				}
			j--;
		}
		i--;
	}
	return (max);
}

int	**make_count_map(int size)
{
	int		**count_map;

	count_map = (int **)make_2d_arr(size);
	return (count_map);
}

struct s_point do_scans(int **count_map, char **normal_map, char *chars, int size)
{
	struct s_point max;

	scan1(count_map, normal_map, chars, size);
	max = scan2(count_map, normal_map, chars, size);
	return (max);
}
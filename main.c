/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: librooke <librooke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:02:01 by librooke          #+#    #+#             */
/*   Updated: 2024/02/12 16:14:49 by librooke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq2.h"

int	main(int argc, char **argv)
{
	int	**count_map;
	int	i;
	int j;

	count_map = make_count_map(get_map_size(argv[1]));
	if (argc == 2){
		do_scans(count_map,
			make_nonfile_map(argv[1]),
			get_chars(argv[1]),
			get_map_size(argv[1]));
		i = 0;
		printf("done!\n");
		while (i < get_map_size(argv[1]))
		{
			j = 0;
			while (j < get_map_size(argv[1]))
			{
				printf("%i ", count_map[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
}
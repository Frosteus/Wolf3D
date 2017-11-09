/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 19:00:30 by yskrypny          #+#    #+#             */
/*   Updated: 2017/08/26 19:00:31 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

double	ft_drand(double min, double max)
{
	double div;

	div = RAND_MAX / (max - min);
	return (min + (rand() / div));
}

int		**ft_create2d_int_array(size_t col, size_t row)
{
	int		**arr;
	size_t	i;

	i = 1;
	if ((arr = malloc(sizeof(int *) * row)) == NULL)
		ft_errors_general(ERR_MALLOC);
	if ((arr[0] = malloc(sizeof(int) * row * col)) == NULL)
		ft_errors_general(ERR_MALLOC);
	while (i != row)
	{
		arr[i] = arr[i - 1] + col;
		i++;
	}
	return (arr);
}

void	ft_free_2d_array(void **arr)
{
	free(arr[0]);
	free(arr);
}

int		ft_get_file_fd(const char *f_name)
{
	int fd;

	if ((fd = open(f_name, O_RDONLY)) < 0)
		ft_errors_general(ERR_NO_FILE);
	return (fd);
}

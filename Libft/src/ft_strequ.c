/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:41:26 by yskrypny          #+#    #+#             */
/*   Updated: 2016/12/08 19:42:43 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 == *s2)
		{
			s1++;
			s2++;
			if (*s1 == '\0' && *s2 == '\0')
				return (1);
		}
	}
	return (0);
}

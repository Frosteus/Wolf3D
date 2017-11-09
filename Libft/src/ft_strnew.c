/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:50:41 by yskrypny          #+#    #+#             */
/*   Updated: 2017/10/27 13:13:28 by yskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	return ((char *)ft_memalloc(size + 1));
	ft_memset(ptr, (int)'\0', size + 1);
	return (ptr);
}

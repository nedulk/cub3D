/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprigent <kprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:03:35 by kprigent          #+#    #+#             */
/*   Updated: 2024/06/12 13:06:18 by kprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void				*target;
	long int			size;

	size = elementCount * elementSize;
	if (size < 0 || ((int)elementCount < 0 && (int)elementSize < 0))
		return (NULL);
	size = elementCount * elementSize;
	target = malloc(sizeof(void) * (size));
	if (target == NULL)
		exit (1);
	ft_bzero(target, (size));
	return (target);
}

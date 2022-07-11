/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 12:11:46 by hyna              #+#    #+#             */
/*   Updated: 2022/07/11 12:11:47 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t	n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
		tmp[i++] = 0;
}

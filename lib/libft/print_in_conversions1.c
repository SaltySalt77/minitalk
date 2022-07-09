/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_conversions1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:30:04 by hyna              #+#    #+#             */
/*   Updated: 2022/06/24 14:47:29 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	conversion_c(va_list	ap)
{
	int		result;
	char	c;

	c = va_arg(ap, int); // va_arg 2nd param
	result = write(1, &c, 1);
	return (result);
}

int	conversion_s(va_list	ap)
{
	int		result;
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		return (write(1, "(null)", 6));
	result = write(STDOUT_FILENO, s, ft_strlen(s));
	return (result);
}

int	conversion_di(va_list	ap)
{
	int		result;
	int		num;
	char	*s;

	num = va_arg(ap, int);
	s = ft_itoa(num);
	if (!s)
		return (-1);
	result = write(1, s, ft_strlen(s));
	free(s);
	s = NULL;
	return (result);
}

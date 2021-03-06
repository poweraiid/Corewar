/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:40:01 by lmoreaux          #+#    #+#             */
/*   Updated: 2018/03/15 06:41:31 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putwstr(wchar_t *str)
{
	while (*str)
		ft_putwchar(*str++);
}

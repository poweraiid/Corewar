/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:37:17 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/08 17:45:22 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isprint(int c)
{
	if ((c >= 0 && c <= 31) || (c >= 127) || (c < 0))
		return (0);
	else
		return (1);
}

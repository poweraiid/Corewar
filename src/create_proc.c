/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:10:14 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/19 18:30:23 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	create_proc(t_env *p)
{
	int		j;
	t_proc	*ptr;

	j = 0;
	while (p->play[j])
		j++;
	j--;
	while (j >= 0)
	{
		ptr = pushproc(&p->begin, p->play[j]->adr);
		ptr->reg[1] = p->play[j]->nb;
		ptr->nbdef = p->play[j]->nbdef;
		j--;
	}
}

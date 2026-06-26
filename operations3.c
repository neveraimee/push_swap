/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:50:34 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/26 19:27:50 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench)
		bench->rrr++;
	if (a && a->size >= 2)
		op_rra(a, bench);
	if (b && b->size >= 2)
		op_rrb(b, bench);
	write(1, "rrr\n", 4);
}

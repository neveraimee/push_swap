/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:48:31 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 20:57:29 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *a, t_bench *bench)
{
	t_stack	*b;
	t_node	*tmp;
	int		i;

	b = stack_new();
	i = 0;
	while (i < a->size)
	{
		while (a->size > i + 1 && !stack_is_sorted(a))
		{
			tmp = a->top;
			if (tmp->value > tmp->next->value)
				op_sa(a, bench);
			if (!stack_is_sorted(a))
				op_pb(a, b, bench);
		}
		while (b->size > 0)
			op_pa(a, b, bench);
		i++;
	}
	stack_free(b);
	return ;
}

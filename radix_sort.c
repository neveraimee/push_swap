/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:38:28 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 20:23:36 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	bit_is_zero(int index, int mask)
{
	return (!(index & mask));
}

void	radix_sort(t_stack *a, t_bench *bench)
{
	int		mask;
	int		n;
	t_node	*node;
	t_stack	*b;

	mask = 1;
	b = stack_new();
	index_nodes(a);
	while (!stack_is_sorted(a))
	{
		n = a->size;
		while (n > 0)
		{
			node = a->top;
			if (bit_is_zero(node->index, mask))
				op_pb(a, b, bench);
			else
				op_ra(a, bench);
			n--;
		}
		while (stack_size(b) > 0)
			op_pa(a, b, bench);
		mask <<= 1;
	}
	stack_free(b);
}

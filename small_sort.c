/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:30:00 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/29 19:21:48 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_position(t_stack *a)
{
	t_node	*tmp;
	int		pos;
	int		min_pos;
	int		min_val;

	tmp = a->top;
	pos = 0;
	min_pos = 0;
	min_val = tmp->value;
	while (tmp)
	{
		if (tmp->value < min_val)
		{
			min_val = tmp->value;
			min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min_pos);
}

static void	push_min(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;

	pos = min_position(a);
	if (pos <= a->size / 2)
		while (pos-- > 0)
			op_ra(a, bench);
	else
		while (pos++ < a->size)
			op_rra(a, bench);
	op_pb(a, b, bench);
}

void	sort_three(t_stack *a, t_bench *bench)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->top->value;
	middle = a->top->next->value;
	bottom = a->top->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		op_sa(a, bench);
	else if (top > middle && middle > bottom)
	{
		op_sa(a, bench);
		op_rra(a, bench);
	}
	else if (top > middle && middle < bottom && top > bottom)
		op_ra(a, bench);
	else if (top < middle && middle > bottom && top < bottom)
	{
		op_sa(a, bench);
		op_ra(a, bench);
	}
	else if (top < middle && middle > bottom && top > bottom)
		op_rra(a, bench);
}

void	sort_five(t_stack *a, t_bench *bench)
{
	t_stack	*b;
	int		count;

	b = stack_new();
	count = a->size - 3;
	while (count-- > 0)
		push_min(a, b, bench);
	sort_three(a, bench);
	while (b->size > 0)
		op_pa(a, b, bench);
	stack_free(b);
}

void	small_sort(t_stack *a, t_bench *bench)
{
	if (stack_is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			op_sa(a, bench);
	}
	else if (a->size == 3)
		sort_three(a, bench);
	else
		sort_five(a, bench);
}

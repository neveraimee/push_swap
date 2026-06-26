/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 18:41:30 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/26 19:21:57 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_position(t_stack *b)
{
	t_node	*tmp;
	int		max;
	int		pos;
	int		max_pos;

	tmp = b->top;
	max = tmp->index;
	pos = 0;
	max_pos = 0;
	while (tmp)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

static int	find_max_index(t_stack *b)
{
	t_node	*tmp;
	int		max;

	tmp = b->top;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

static void	push_chunks(t_stack *a, t_stack *b, t_bench *bench)
{
	int	chunk_size;
	int	chunk_min;
	int	chunk_max;
	int	i;
	int	orignal_size;

	chunk_size = ft_sqrt(a->size);
	chunk_min = 0;
	chunk_max = chunk_size;
	while (stack_size(a))
	{
		orignal_size = a->size;
		i = 0;
		while (i < orignal_size)
		{
			if (a->top->index >= chunk_min && a->top->index < chunk_max)
				op_pb(a, b, bench);
			else
				op_ra(a, bench);
			i++;
		}
		chunk_min += chunk_size;
		chunk_max += chunk_size;
	}
}

static void	pull_chunks(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max;
	int	position;

	while (stack_size(b))
	{
		max = find_max_index(b);
		position = find_max_position(b);
		if (position <= b->size / 2)
		{
			while (b->top->index != max)
				op_rb(b, bench);
		}
		else
		{
			while (b->top->index != max)
				op_rrb(b, bench);
		}
		op_pa(a, b, bench);
	}
}

void	chunk_sort(t_stack *a, t_bench *bench)
{
	t_stack	*b;

	b = stack_new();
	push_chunks(a, b, bench);
	pull_chunks(a, b, bench);
	stack_free(b);
}

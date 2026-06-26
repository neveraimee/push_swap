/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:37:14 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 20:43:06 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_stack *a, t_bench *bench)
{
	t_node	*first;
	t_node	*second;

	if (bench)
		bench->sa++;
	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = a->top->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	write(1, "sa\n", 3);
}

void	op_sb(t_stack *b, t_bench *bench)
{
	t_node	*first;
	t_node	*second;

	if (bench)
		bench->sb++;
	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	write(1, "sb\n", 3);
}

void	op_ss(t_stack *a, t_stack *b, t_bench *bench)
{
	t_node	*first;
	t_node	*second;

	if (bench)
		bench->ss++;
	if (a && a->size >= 2)
	{
		first = a->top;
		second = a->top->next;
		first->next = second->next;
		second->next = first;
		a->top = second;
	}
	if (b && b->size >= 2)
	{
		first = b->top;
		second = b->top->next;
		first->next = second->next;
		second->next = first;
		b->top = second;
	}
	write(1, "ss\n", 3);
}

void	op_pa(t_stack *a, t_stack *b, t_bench *bench)
{
	int		val;
	int		idx;

	if (bench)
		bench->pa++;
	if (!b || stack_size(b) == 0)
		return ;
	val = stack_peek(b);
	idx = stack_peek_index(b);
	stack_pop(b);
	stack_push(a, val, idx);
	write(1, "pa\n", 3);
}

void	op_pb(t_stack *a, t_stack *b, t_bench *bench)
{
	int		val;
	int		idx;

	if (bench)
		bench->pb++;
	if (!a || stack_size(a) == 0)
		return ;
	val = stack_peek(a);
	idx = stack_peek_index(a);
	stack_pop(a);
	stack_push(b, val, idx);
	write(1, "pb\n", 3);
}

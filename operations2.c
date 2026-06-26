/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 20:42:22 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/26 19:27:24 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_stack *a, t_bench *bench)
{
	t_node	*temp;
	t_node	*index;

	if (bench)
		bench->ra++;
	if (!a || a->size < 2)
		return ;
	temp = a->top;
	index = a->top;
	while (index->next != NULL)
		index = index->next;
	index->next = temp;
	a->top = temp->next;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b, t_bench *bench)
{
	t_node	*temp;
	t_node	*index;

	if (bench)
		bench->rb++;
	if (!b || b->size < 2)
		return ;
	temp = b->top;
	index = b->top;
	while (index->next != NULL)
		index = index->next;
	index->next = temp;
	b->top = temp->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	op_rr(t_stack *a, t_stack *b, t_bench *bench)
{
	if (bench)
		bench->rr++;
	if (a && a->size >= 2)
		op_ra(a, bench);
	if (b && b->size >= 2)
		op_rb(b, bench);
	write(1, "rr\n", 3);
}

void	op_rra(t_stack *a, t_bench *bench)
{
	t_node	*current;
	t_node	*prev;
	t_node	*temp;

	if (bench)
		bench->rra++;
	if (!a || a->size < 2)
		return ;
	current = a->top;
	temp = a->top;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	a->top = current;
	current->next = temp;
	prev->next = NULL;
	write(1, "rra\n", 4);
}

void	op_rrb(t_stack *b, t_bench *bench)
{
	t_node	*current;
	t_node	*prev;
	t_node	*temp;

	if (bench)
		bench->rrb++;
	if (!b || b->size < 2)
		return ;
	current = b->top;
	temp = b->top;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	b->top = current;
	current->next = temp;
	prev->next = NULL;
	write(1, "rrb\n", 4);
}

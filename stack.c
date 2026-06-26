/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:36:38 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 23:36:39 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_stack	*stack_new(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	stack_push(t_stack *s, int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = value;
	node->index = index;
	node->next = s->top;
	s->top = node;
	s->size++;
}

t_node	stack_pop(t_stack *s)
{
	t_node	result;
	t_node	*temp;

	if (!s || !s->top)
	{
		result.value = 0;
		result.index = 0;
		result.next = NULL;
		return (result);
	}
	temp = s->top;
	result.value = temp->value;
	result.index = temp->index;
	s->top = temp->next;
	free(temp);
	s->size--;
	return (result);
}

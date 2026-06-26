/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 21:21:18 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 23:38:08 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_peek(t_stack *s)
{
	if (!s || !s->top)
		return (0);
	return (s->top->value);
}

int	stack_peek_index(t_stack *s)
{
	if (!s || !s->top)
		return (0);
	return (s->top->index);
}

int	stack_is_sorted(t_stack *s)
{
	t_node	*current;

	current = s->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	while (s->top)
		stack_pop(s);
	free (s);
}

int	stack_size(t_stack *s)
{
	return (s->size);
}

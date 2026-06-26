/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:37:23 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/25 20:57:10 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int			mistakes;
	int			total_pairs;
	t_node		*tmp;
	t_node		*tmp2;

	mistakes = 0;
	total_pairs = 0;
	tmp = a->top;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			total_pairs += 1;
			if (tmp->value > tmp2->value)
				mistakes += 1;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}

int	is_sorted(t_stack *a)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (disorder != 0)
		return (0);
	return (1);
}

void	index_nodes(t_stack *a)
{
	t_node	*top;
	t_node	*tmp;
	int		index;
	int		i;

	top = a->top;
	i = 0;
	while (i < a->size)
	{
		index = 0;
		tmp = a->top;
		while (tmp)
		{
			if (tmp->value < top->value)
				index++;
			tmp = tmp->next;
		}
		top->index = index;
		top = top->next;
		i++;
	}
}

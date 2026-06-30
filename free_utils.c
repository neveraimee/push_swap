/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:36:10 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/29 18:22:40 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(char **array, t_bench *bench, t_stack *a)
{
	if (array)
	{
		freeit(array);
	}
	stack_free(a);
	free(bench);
	write(2, "Error\n", 6);
	exit(1);
}

void	freeit(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	while (s->top)
		stack_pop(s);
	free (s);
}

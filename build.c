/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:40:31 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/29 17:41:34 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result * sign > INT_MAX)
			return ((long)INT_MAX + 1);
		if (result * sign < INT_MIN)
			return ((long)INT_MIN - 1);
		i++;
	}
	return (result * sign);
}

t_stack	*create_stack(char **array, t_bench *bench)
{
	long	num;
	int		i;
	t_node	*tmp;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = 0;
	stack->size = 0;
	stack->top = NULL;
	while (array[i])
	{
		num = ft_atol(array[i++]);
		if (num > INT_MAX || num < INT_MIN)
			exit_error(array, bench, stack);
		tmp = ps_lstnew(num);
		ft_lstadd_back(&stack->top, tmp);
		stack->size++;
	}
	check_duplicates(stack, array, bench);
	index_nodes(stack);
	return (stack);
}

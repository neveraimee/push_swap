/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 23:44:02 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/26 18:05:16 by aimdoyle         ###   ########.fr       */
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

t_node	*ps_lstnew(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	parse_flags(int ac, char **av, t_opts *opts, t_stack *a, t_bench *bench)
{
	int	i;

	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!ft_strcmp("--bench", av[i]))
			opts->bench = 1;
		if (!ft_strcmp("--adaptive", av[i]))
			opts->strategy = ADAPTIVE;
		else if (!ft_strcmp("--simple", av[i]))
			opts->strategy = SIMPLE;
		else if (!ft_strcmp("--medium", av[i]))
			opts->strategy = MEDIUM;
		else if (!ft_strcmp("--complex", av[i]))
			opts->strategy = COMPLEX;
		else
			exit_error(NULL, bench, a);
		i++;
		if ((i == 2 && opts->bench == 0) || i == 3)
			exit_error(NULL, bench, a);
	}
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
		{
			free(stack);
			exit_error(array, bench, NULL);
		}
		tmp = ps_lstnew(num);
		ft_lstadd_back(&stack->top, tmp);
		stack->size++;
	}
	index_nodes(stack);
	return (stack);
}

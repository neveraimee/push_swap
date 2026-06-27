/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:15:15 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/27 21:30:18 by aimdoyle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_opts
{
	t_strategy	strategy;
	int			bench;
}	t_opts;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

typedef struct s_clean
{
	t_stack	*a;
	t_bench	*bench;
}	t_clean;

t_stack	*stack_new(void);
void	stack_push(t_stack *s, int value, int index);
t_node	stack_pop(t_stack *s);
int		stack_peek(t_stack *s);
int		stack_peek_index(t_stack *s);
int		stack_is_sorted(t_stack *s);
void	stack_free(t_stack *s);
int		stack_size(t_stack *s);

void	op_sa(t_stack *a, t_bench *bench);
void	op_sb(t_stack *b, t_bench *bench);
void	op_ss(t_stack *a, t_stack *b, t_bench *bench);
void	op_pa(t_stack *a, t_stack *b, t_bench *bench);
void	op_pb(t_stack *a, t_stack *b, t_bench *bench);
void	op_ra(t_stack *a, t_bench *bench);
void	op_rb(t_stack *b, t_bench *bench);
void	op_rr(t_stack *a, t_stack *b, t_bench *bench);
void	op_rra(t_stack *a, t_bench *bench);
void	op_rrb(t_stack *b, t_bench *bench);
void	op_rrr(t_stack *a, t_stack *b, t_bench *bench);

char	**split(char const *s);
long	ft_atol(const char *nptr);
t_node	*ps_lstnew(int content);
char	**avtoarray(int ac, char **av);
t_stack	*parse_args(int ac, char **av, t_bench *bench);
void	exit_error(char **array, t_bench *bench, t_stack *a);
void	isvalid(char **array, t_bench *bench);
void	check_duplicates(t_stack *stack, char **array, t_bench *bench);
double	compute_disorder(t_stack *a);
int		is_sorted(t_stack *a);
t_stack	*create_stack(char **array, t_bench *bench);
void	parse_flags(int ac, char **av, t_opts *opts, t_clean *data);
int		ft_strcmp(char *s1, char *s2);
int		ft_sqrt(int n);
void	freeit(char **array);
void	index_nodes(t_stack *a);

void	bubble_sort(t_stack *a, t_bench *bench);
void	chunk_sort(t_stack *a, t_bench *bench);
void	radix_sort(t_stack *a, t_bench *bench);
void	adaptive_sort(t_stack *a, t_bench *bench);

void	write_bench(t_bench *bench, double disorder, t_opts *opts);

void	choosealg(t_opts opts, t_bench *bench, double disorder, t_stack *a);
void	assign_values(t_opts *opts, t_clean *data, t_stack *a, t_bench *bench);
int		init_data(t_bench **bench, t_clean **data);

#endif
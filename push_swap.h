/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimdoyle <aimdoyle@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:15:15 by aimdoyle          #+#    #+#             */
/*   Updated: 2026/06/29 19:22:01 by aimdoyle         ###   ########.fr       */
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

// stack
t_stack	*stack_new(void);
void	stack_push(t_stack *s, int value, int index);
t_node	stack_pop(t_stack *s);
int		stack_peek(t_stack *s);
int		stack_peek_index(t_stack *s);
int		stack_is_sorted(t_stack *s);
int		stack_size(t_stack *s);
t_node	*ps_lstnew(int content);

// operations
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

// algorthims
void	bubble_sort(t_stack *a, t_bench *bench);
void	chunk_sort(t_stack *a, t_bench *bench);
void	radix_sort(t_stack *a, t_bench *bench);
void	sort_three(t_stack *a, t_bench *bench);
void	sort_five(t_stack *a, t_bench *bench);
void	adaptive_sort(t_stack *a, t_bench *bench);
void	small_sort(t_stack *a, t_bench *bench);

//split
char	**split(char const *s);

// parse
char	**avtoarray(int ac, char **av);
void	isvalid(char **array, t_bench *bench);
void	check_duplicates(t_stack *stack, char **array, t_bench *bench);
t_stack	*parse_args(int ac, char **av, t_bench *bench);

// disorder
double	compute_disorder(t_stack *a);
void	index_nodes(t_stack *a);

// flags
void	parse_flags(int ac, char **av, t_opts *opts, t_clean *data);

// utils
int		ft_strcmp(char *s1, char *s2);
int		ft_sqrt(int n);

// main
void	choosealg(t_opts opts, t_bench *bench, double disorder, t_stack *a);
void	assign_values(t_opts *opts, t_clean *data, t_stack *a, t_bench *bench);

// build
long	ft_atol(const char *nptr);
t_stack	*create_stack(char **array, t_bench *bench);

// free utils
void	stack_free(t_stack *s);
void	exit_error(char **array, t_bench *bench, t_stack *a);
void	freeit(char **array);

void	write_bench(t_bench *bench, double disorder, t_opts *opts);

#endif
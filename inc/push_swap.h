/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damarry <damarry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:56:51 by damarry           #+#    #+#             */
/*   Updated: 2022/03/05 19:44:16 by damarry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//INCS
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft.h"

//DEFINES
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAL_ERR 1
# define ARG_ERR 2
# define RR_RA 1
# define RR_RB 2
# define RRR_RRA 3
# define RRR_RRB 4
# define RRA_RB 5
# define RRB_RA 6
# define FORWARD 1
# define BACKWARD 0

//STRUCT
typedef struct s_stack
{
	int				num;
	int				score_a;
	int				score_ra;
	int				score_b;
	int				score_rb;
	int				cheapest;
	int				rotate_option;
	struct s_stack	*next;
}				t_stack;

typedef struct s_data
{
	int		*num_arr;
	int		*srt_num_arr;

	int		len;
	int		min;
	int		max;
	int		med;
	int		len_a;
	int		len_b;
	int		num_to_push;

	t_stack	*stack_a;
	t_stack	*stack_b;

}				t_data;

//FUNCS
int		main(int as, char **av);

//parser
void	to_int(t_data *data, char **arr);
void	int_checker(t_data *data, long num, int last, char **arr);
void	char_checker(char **arr);
char	**divided_args(int ac, char **av);
void	reader(t_data *data, int ac, char **av);

//algorithm
void	fill_a(t_data *data);
void	fill_b(t_data *data);
void	five_sort(t_data *data);
void	main_alg(t_data *data);
void	distributor(t_stack *stack, t_data *data);

//stops
void	stop_1(char **arr, int flag);
void	stop_2(char **arr, t_data *data, int flag);
void	stop_3(t_data *data);
void	stop_4(t_data *data);
void	stop_5(t_data *data);

//push_swap funks
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b, int *len_a, int *len_b);
void	push_b(t_stack **stack_a, t_stack **stack_b, int *len_a, int *len_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate_a(t_stack **stack_a);
void	rev_rotate_b(t_stack **stack_b);
void	rev_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	rev_ab_b(t_stack **stack_b);
void	rev_ab_a(t_stack **stack_a);

//move
void	rr_ra_move(t_stack *stack, t_data *data);
void	rr_rb_move(t_stack *stack, t_data *data);
void	rrr_rrb_move(t_stack *stack, t_data *data);
void	rrr_rra_move(t_stack *stack, t_data *data);
void	rra_rb_move(t_stack *stack, t_data *data);
void	rrb_ra_move(t_stack *stack, t_data *data);

//scoring
void	scoring(t_data *data);
int		scoring_a(t_stack *stack_a, int num);
void	choose_opt(t_stack *tmp, int len_a, int len_b);
t_stack	*elem_to_push(t_stack *stack_b);

//scoring_opt
int		rr_ra_opt(t_stack *tmp, int len_a);
int		rr_rb_opt(t_stack *tmp, int len_b);
int		rrr_rrb_opt(t_stack *tmp, int len_b);
int		rrr_rra_opt(t_stack *tmp, int len_a);
int		rra_rb_opt(t_stack *tmp);
int		rrb_ra_opt(t_stack *tmp);

//lib_upgrade
int		up_putendl_fd(char *s, int fd);
long	up_atoi(const char *str);
int		arr_len(char **arr);

//quick sort
void	srt_arr(t_data *data);
void	qsort_recursive(int *mas, int size);

//list utils
t_stack	*upt_lstnew(t_data *data, int i);
void	up_lstadd_front(t_stack **lst, t_stack *new);
void	up_lstadd_back(t_stack **lst, t_stack *new);

//if sorted
void	triple_sort(t_data *data);
void	final_sort(t_data *data);
int		rotate_dir(t_data *data);
int		if_sorted(t_stack *stack);
int		if_sorted_inner(t_stack *stack, t_stack *tmp);

#endif

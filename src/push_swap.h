/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:35:55 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/24 18:55:57 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "ft_printf.h"

// Node structure for a doubly linked list
typedef struct s_stack_node
{
	int					value;
	bool				cheapest;
	int					index;
	int					push_price;
	bool				above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*fwd;
	struct s_stack_node	*bwd;
}	t_stack_node;

// Stack operations
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// Stack utilities
int				stack_length(t_stack_node *head);
bool			stack_ordered(t_stack_node *stack);
void			free_stack(t_stack_node **stack);
void			append_node(t_stack_node **a, t_stack_node *new_node);

// Error handling
bool			handle_errors(t_stack_node **a, char *argv, long n);
void			free_errors(t_stack_node **a, char **argv, int argc);
int				error_nondigit(char *str);
int				error_duplicated(t_stack_node *a, long n);

// Node creation
t_stack_node	*create_node(int value);

// Sorting algorithms
void			sort_three(t_stack_node **a);
int				process_values(t_stack_node **a, char **values, int i);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			push_r(t_stack_node **stack, t_stack_node *cheap, char st_na);
void			calibrate_nodes(t_stack_node *a, t_stack_node *b);
void			choose_stack(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
t_stack_node	*return_smallest(t_stack_node *stack);
void			set_target_node(t_stack_node *a, t_stack_node *b);
int				init_stack_no_split(t_stack_node **a, int argc, char **argv);

// Utility functions
char			**ft_split(char const *s, char c);
long			ft_atol(const char *str);
void			free_array(char **array);

#endif // PUSH_SWAP_H

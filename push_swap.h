/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:06:40 by pwojnaro          #+#    #+#             */
/*   Updated: 2024/07/21 21:12:56 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "../libtft/libft.h"

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

// Node creation and manipulation
t_stack_node	*create_node(int value);
void			ft_stack_add_back(t_stack_node **lst, t_stack_node *new);
void			append_node(t_stack_node **a, t_stack_node *new_node);

// Stack initialization and validation
int				initialize_stack_single(t_stack_node **a, char *input);
int				initialize_stack(t_stack_node **a, int argc, char **argv);
int				init_stack_no_split(t_stack_node **a, int argc, char **argv);
bool			validate_input(t_stack_node **stack, char *arg, long num);
bool			handle_errors(t_stack_node **stack, char *arg_array, long n);
int				process_values(t_stack_node **a, char **values, int i);

// Error handling and cleanup
void			release_stack(t_stack_node **stack_ptr);
void			free_errors(t_stack_node **a, char **argv, int argc);
void			free_array(char **array);

// Stack operations
void			rotate(t_stack_node **head);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			push_stack(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			swap(t_stack_node **head);
void			choose_stack(t_stack_node *stack);

// Stack utilities
int				stack_length(t_stack_node *head);
bool			ordered(t_stack_node *stack);
long			ft_atol(const char *str);

// Sorting and operations
void			sort_three(t_stack_node **a);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			split_stack(t_stack_node **a, t_stack_node **b);
void			transfer_nodes(t_stack_node **a, t_stack_node **b);
void			rotate_to_smallest(t_stack_node **a);
void			move_opt_node(t_stack_node **a, t_stack_node **b);

// Node pricing and target setting
void			set_cheapest(t_stack_node *b);
void			set_price(t_stack_node *a, t_stack_node *b);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			calculate_price_node(t_stack_node *node, int len_a, int len_b);
t_stack_node	*find_min_price_node(t_stack_node *head);
t_stack_node	*return_cheapest(t_stack_node *stack);

// Node retrieval
t_stack_node	*return_biggest(t_stack_node *stack);
t_stack_node	*find_smallest(t_stack_node *stack, t_stack_node *smallest);
t_stack_node	*return_smallest(t_stack_node *stack);

// Node calibration
void			calibrate_nodes(t_stack_node *a, t_stack_node *b);

#endif // PUSH_SWAP_H

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwojnaro <pwojnaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:35:55 by piotrwojnar       #+#    #+#             */
/*   Updated: 2024/05/20 14:40:54 by pwojnaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

// Node structure for a doubly linked list
typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*fwd;
	struct s_stack_node	*bwd;
}	t_stack_node;

// Constants to represent success and failure
# define TRUE 	1
# define FALSE 	0

// Function declarations
int				dll_swap(t_stack_node **current);
void			free_stack(t_stack_node **stack);
int				error_nondigit(char *str);
int error_duplicated(t_stack_node *a, long n);
t_stack_node	*create_node(int value);
void			sa(t_stack_node **head);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **head);
void			rra(t_stack_node **head);
int				stack_length(t_stack_node *head);
char			**ft_split(char const *s, char c);
void			free_array(char **array);
bool handle_errors(t_stack_node **a, char *argv, long n);
void free_errors(t_stack_node **a, char **argv, int argc);
void			quick_sort(t_stack_node **a, t_stack_node **b, int size);
int				find_median(t_stack_node *head, int size);
void rrr(t_stack_node **a, t_stack_node **b);
bool	stack_ordered(t_stack_node *stack);
void	sort_three(t_stack_node **a);
void sort_five(t_stack_node **a, t_stack_node **b);
int find_median(t_stack_node *head, int size);

#endif // PUSH_SWAP_H
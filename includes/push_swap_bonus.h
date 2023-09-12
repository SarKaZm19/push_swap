/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:06:54 by fvastena          #+#    #+#             */
/*   Updated: 2023/09/12 15:07:31 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <errno.h>

# include "../libft/include/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}				t_stack;

// checker_gnl_bonus.c
char	*get_next_line(int fd, int *read_error);

// error_bonus.c
void	prog_error(void);

// exec_bonus.c 
void	exec_op(char *line, t_stack **a, t_stack **b);

// get_datas_bonus.c
t_stack	*get_av(int ac, char **av);

//movesa_bonus.c
void	ft_pa(t_stack **a, t_stack **b);
void	ft_sa(t_stack **a);
void	ft_ra(t_stack **a);
void	ft_rra(t_stack **a);

// movesab_bonus.c
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

// movesb_bonus.c
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_sb(t_stack **b);
void	ft_rb(t_stack **b);
void	ft_rrb(t_stack **b);

// utils_bonus.c
int		ft_atoi2(char *str, int *error_flag);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stack_new(int content);

// ft_free_bonus.c
void	ft_free_stack(t_stack **a);
void	ft_free_operations(t_list **ops);

void	print_stack(t_stack *lst);

#endif
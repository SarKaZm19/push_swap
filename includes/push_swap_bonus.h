#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <errno.h>

# include "../libft/include/libft.h"

// Lists
typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}				t_stack;

// Parsing
t_stack	*get_av(int ac, char **av);
void	check_duplicates(t_stack *lst);
int ft_atoi2(char *str, int *error_flag);

// Checker
int	exec_line(char *line, t_stack **a, t_stack **b);

// Moves
void	ft_pa(t_stack **a, t_stack **b);
void	ft_sa(t_stack **a);
void	ft_ra(t_stack **a);
void	ft_rra(t_stack **a);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_sb(t_stack **b);
void	ft_rb(t_stack **b);
void	ft_rrb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

// Stacks
int	ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stack_new(int content);

//ft_free.c
void	ft_free_stack(t_stack **a);


#endif
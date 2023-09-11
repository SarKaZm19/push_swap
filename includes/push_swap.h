#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <errno.h>

# include "../libft/include/libft.h"

// Stack
typedef struct s_stack
{
	int				nbr;
	int				nb_rot_a;
	int				nb_rot_b;
	int				nb_rr;
	int				nb_rrr;
	int				rev_a;
	int				rev_b;
	int				total_moves;
	struct s_stack	*next;
}					t_stack;

typedef struct s_pile
{
	int		full_len;
	int		actual_len;
	int		*pre_sort;
	int		nb_chunks;
	int		*pivots;
	t_stack	*top;
}			t_pile;

//extern int COUNT_OPERATIONS;

// chunk_pivots.c
int		define_chunks(int size);
int		*set_pivots(int *arr, int nb_chunks, int size);

// errors.c
void	prog_error(void);

// find_place.c 
int		ft_find_index(t_stack *a, int nbr);
int		ft_find_place(t_stack *stack_a, int nbr_push);

// ft_free.c
void	ft_free_stack(t_stack **a);
void	ft_free_pile(t_pile *pile, int print_error);

// get_cheapest_rot.c
void	get_nb_rot_b(t_stack *tmp, int len, int index);
void	get_nb_rot_a(t_stack *tmp, t_stack *a, int len);
void	get_total_moves(t_stack *tmp);

// get_cheapest.c
int		get_cheapest(t_pile *a, t_pile *b);

// get_datas.c
t_stack	*get_av(int ac, char **av);
int		check_duplicates(int *datas, int len);

// init_piles.c
t_pile	*init_pile_b(t_pile *pile_a);
t_pile	*init_pile_a(int ac, char **av);

// int_tab.c
int		*get_tab(t_pile *pile_a);
void	ft_sort_int_tab(int *tab, int size);

// main.c
int	ft_issorted(t_stack *lst);

// min_max.c
int		ft_max(t_stack *a);
int		ft_min(t_stack *a);

// movesa.c
void	ft_pa(t_stack **a, t_stack **b, int j);
void	ft_sa(t_stack **a, int j);
void	ft_ra(t_stack **a, int j);
void	ft_rra(t_stack **a, int j);

// movesab.c
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);

// movesb.c
void	ft_pb(t_stack **a, t_stack **b, int j);
void	ft_sb(t_stack **b, int j);
void	ft_rb(t_stack **b, int j);
void	ft_rrb(t_stack **b, int j);


// push_all_b.c
void	push_one_chunk(t_pile *a, t_pile *b);
void	push_b(t_pile *a, t_pile *b);
void	push_first_two_chunks(t_pile *a, t_pile *b, int chunk_size);
void	push_chunk(t_pile *a, t_pile *b, int index, int chunk_size);

// push_swap.c
void	push_swap(t_pile *pile_a, t_pile *pile_b);

// push_to_a.c
void	push_a(t_pile *a, t_pile *b);

// push_three.c
void	ft_sort_three(t_stack **a);

// utils.c
int		ft_atoi2(char *data_set, int *error_flag);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_add_back(t_stack **stack, t_stack *stack_new);
t_stack	*ft_stack_new(int content);

//misc
void	print_stack(t_stack *a);

#endif
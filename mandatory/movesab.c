#include "push_swap.h"

void	ft_ss(t_pile *a, t_pile *b, int j)
{
	ft_sa(a, 1);
	ft_sb(b, 1);
	if (j == 0)
		write(1, "ss\n", 3);
}

void	ft_rr(t_pile *a, t_pile *b, int j)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}

void	ft_rrr(t_pile *a, t_pile *b, int j)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
	if (j == 0)
		write(1, "rrr\n", 4);
}
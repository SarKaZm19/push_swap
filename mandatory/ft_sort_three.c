#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	if (ft_min(*a) == (*a)->nbr)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ft_ra(a, 0);
		if (!ft_issorted(*a))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_find_index(*a, ft_max(*a)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}

#include "push_swap.h"

void	ft_pa(t_pile *a, t_pile *b, int j)
{
	t_stack	*tmp;

	if (!(b->top))
		return ;
	tmp = a->top;
	a->top = b->top;
	b->top = b->top->next;
	a->top->next = tmp;
	b->actual_len--;
	a->actual_len++;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	ft_sa(t_pile *a, int j)
{
	t_stack	*tmp;

	if (!(a->top) || !(a->top->next))
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = a->top->next;
	a->top->next = tmp;
	if (j == 0)//seulement pour le checker
		write(1, "sa\n", 3);
}

void	ft_ra(t_pile *a, int j)
{
	t_stack	*tmp;

	if (!(a->top) || !(a->top->next))
		return ;
	tmp = a->top;
	a->top = ft_lstlast(a->top);
	a->top->next = tmp;
	a->top = tmp->next;
	tmp->next = NULL;
	if (j == 0) //seulement pour le checker
		write(1, "ra\n", 3);
}

void	ft_rra(t_pile *a, int j)
{
	t_stack	*tmp;
	int		i;

	if (!(a->top) || !(a->top->next))
		return ;
	i = 0;
	tmp = a->top;
	while (a->top->next)
	{
		a->top = a->top->next;
		i++;
	}
	a->top->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)//seulement pour le checker
		write(1, "rra\n", 4);
}
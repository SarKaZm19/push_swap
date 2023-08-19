#include "push_swap.h"

/* void	ft_pb(t_pile *a, t_pile *b, int j)
{
	t_stack	*tmp;

	if (!(a->top))
		return ;
	tmp = b->top;
	b->top = a->top;
	a->top = a->top->next;
	b->top->next = tmp;
	a->actual_len--;
	b->actual_len++;
	if (j == 0)
		write(1, "pb\n", 3);
} */

void	ft_sb(t_pile *b, int j)
{
	t_stack	*tmp;

	if (!(b->top) || !(b->top->next))
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = b->top->next;
	b->top->next = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}

/* void	ft_rb(t_pile *b, int j)
{
	t_stack	*tmp;

	if (!(b->top) || !(b->top->next))
		return ;
	tmp = b->top;
	b->top = ft_lstlast(b->top);
	b->top->next = tmp;
	b->top = tmp->next;
	tmp->next = NULL;
	if (j == 0)
		write(1, "rb\n", 3);
} */

void	ft_rrb(t_pile *b, int j)
{
	t_stack	*tmp;
	int		i;

	if (!(b->top) || !(b->top->next))
		return ;
	i = 0;
	tmp = b->top;
	while (b->top->next)
	{
		i++;
		b->top = b->top->next;
	}
	b->top->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rrb\n", 4);
}
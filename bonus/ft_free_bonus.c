#include "push_swap_bonus.h"

void	ft_free_operations(t_list **ops)
{
	t_list	*tmp;

	if (!ops)
		return ;
	while (*ops)
	{
		tmp = (*ops)->next;
		free((*ops)->content);
		(*ops)->content = NULL;
		free(*ops);
		(*ops) = tmp;
	}
}

void	ft_free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		(*s)->nbr = 0;
		free(*s);
		(*s) = tmp;
	}
}
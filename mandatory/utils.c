#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stacklast(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_stacklast(*stack))->next = stack_new;
}

t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		return (NULL);
	new->nbr = content;
	new->nb_rot_a = 0;
	new->nb_rot_b = 0;
	new->total_moves = 0;
	new->nb_rr = 0;
	new->nb_rrr = 0;
	new->next = NULL;
	return (new);
}

int ft_atoi2(char *str, int *error_flag) 
{
	int sign = 1;
	long num = 0;
	int i = 0;

	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if ((str[i + 1] && !ft_isdigit(str[i + 1])) || !str[i + 1])
			return (*error_flag = -1);
		if (str[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(str[i]))
		num = (num * 10) + (str[i++] - '0');
	while (str[i] == ' ')
		i++;
	if (str[i])
		return (*error_flag = -1);
	if (num * sign > 2147483647 || num * sign < -2147483648)
		return (*error_flag = -1);
	return (sign * (int)num);
}

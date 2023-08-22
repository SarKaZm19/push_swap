#include "push_swap.h"

// args peut être 1 2 3 4 ou "1 2 3 4" ou "1 2" 3 "4 5"
// --> pour chaque av, split ?

// 1) --> récup tous les av dans un tab de char
// 2) --> check chaque elem du tab pour tab de int
// 3) --> verifier les doublons et autres

void	print_stack(t_stack *lst)
{
	printf("stack : \n");

	while (lst)
	{
		printf("lst->content = %d\n", lst->nbr);
		lst = lst->next;
	}
}

int	ft_issorted(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->next->nbr < lst->nbr)
			return (0);
		lst = lst->next;
	}
	return (1);
}

//int COUNT_OPERATIONS;

int main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	//COUNT_OPERATIONS = 0;
	pile_a = malloc(sizeof(t_pile));
	pile_b = malloc(sizeof(t_pile));
	if (!pile_a || !pile_b)
		return (prog_error(), 1);
	pile_a->top = get_av(ac, av);
	if (!pile_a->top)
		return (free(pile_a), prog_error(), 1);
	pile_b->top = NULL;
	pile_b->full_len = 0;
	pile_b->actual_len = pile_b->full_len;
	pile_a->full_len = ft_lstsize(pile_a->top);
	//fprintf(stderr, "pile_a->len = %d\n", pile_a->full_len);
	pile_a->actual_len = pile_a->full_len;
	//print_stack(pile_a->top);
	if (!ft_issorted(pile_a->top))
		push_swap(pile_a, pile_b);
	if (!ft_issorted(pile_a->top))
		print_stack(pile_a->top);
	//print_stack(pile_a->top);
	ft_free_stack(&(pile_a->top));
	free(pile_a);
	free(pile_b);
	//printf("%d\n", COUNT_OPERATIONS);
	return (0);
}

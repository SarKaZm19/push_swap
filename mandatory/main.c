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

void	print_info(t_pile *a)
{
	printf("a->actual_len = %d\n", a->actual_len);
	printf("a->full_len = %d\n", a->full_len);
	printf("a->nb_chunks = %d\n", a->nb_chunks);
	int i = -1;
	if (a->nb_chunks > 1)
	{
		while (++i < a->nb_chunks * 2 - 2)
			printf("pivots[%d] = %d\n", i, a->pivots[i]);
	}
	i = -1;
	while (++i < a->full_len)
		printf("arr[%d] = %d\n", i, a->pre_sort[i]);
	print_stack(a->top);
}

int main(int ac, char **av)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = init_pile_a(ac, av);
	//print_info(pile_a);
	pile_b = init_pile_b(pile_a);
	//print_info(pile_b);
	if (!ft_issorted(pile_a->top))
		push_swap(pile_a, pile_b);
	if (!ft_issorted(pile_a->top))
		print_stack(pile_a->top);
	//print_stack(pile_a->top);
	free(pile_a->pivots);
	free(pile_a->pre_sort);
	ft_free_stack(&(pile_a->top));
	free(pile_a);
	free(pile_b);
	//printf("%d\n", COUNT_OPERATIONS);
	return (0);
}

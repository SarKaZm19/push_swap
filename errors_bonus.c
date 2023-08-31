#include "push_swap.h"

int	usage_error(void)
{
	write(2, "Usage : 2 arguments required\n", 29);
	exit(EXIT_FAILURE);
}

void	ft_malloc_error(char *fct)
{
	write(2, fct, ft_strlen(fct));
	write(2, "malloc failed\n", 14);
	exit(EXIT_FAILURE);
}

void	prog_error(char **data_set)
{
	ft_free_tab(data_set);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
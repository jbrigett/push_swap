#include "push_swap.h"

t_stack		*parse(int argc, char **argv)
{
	t_stack	*stack;

	if (!(stack = init_stack()))
		terminate(ERR_MEMALLOC);
	if (argc == 2 && !ft_isnum(argv[1], 10))
		parse_str(stack, argv[1]);
	else
		parse_arr(stack, argc, argv);
	if (!stack->size)
		terminate(ERR_NO_NUMBERS);
	return (stack);
}

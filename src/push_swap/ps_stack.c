#include "push_swap.h"

t_stack			*init_stack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack *)ft_memalloc(sizeof(t_stack))))
		terminate(ERR_MEMALLOC);
	stack->head = NULL;
	stack->size = 0;
	stack->pairs = 0;
	stack->m_head = NULL;
	return (stack);
}

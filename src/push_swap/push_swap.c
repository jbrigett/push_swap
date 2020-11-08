#include "push_swap.h"

void	check_valid(t_stack *stack)
{
	size_t			i;
	t_plist			*cur;
	t_stack_elem	*cur_tmp;

	i = 0;
	cur = stack->head;
	while (i < stack->size)
	{
		cur_tmp = cur->next;
		while (cur_tmp != cur)
		{
			if (cur->number == cur_tmp->number)
				terminate(ERR_DUPLICATE);
			cur_tmp = cur_tmp->next;
		}
		i++;
		cur = cur->next;
	}
}

int		main(int argc, char **argv)
{
	t_stack				*stack_index;
	t_stack				*stack_gt;
	t_plist				*commands_index;
	t_plist				*commands_gt;

	if (argc >= 2)
	{
		check_valid((stack_index = parse(argc, argv)));
		index_stack(stack_index);
		opt_markup_stack(stack_index, &markup_stack_index);
		commands_index = solve(stack_index, &markup_stack_index);
		free_stack(stack_index);
		index_stack(stack_gt = parse(argc, argv));
		opt_markup_stack(stack_gt, &markup_stack_gt);
		commands_gt = solve(stack_gt, &markup_stack_gt);
		free_stack(stack_gt);
		print_commands((commands_index->size < commands_gt->size) ?
					   commands_index : commands_gt);
		free_command_list(commands_index);
		free_command_list(commands_gt);
	}
	else
		ft_putendl(ERR_PS_USAGE);
	return (0);
}


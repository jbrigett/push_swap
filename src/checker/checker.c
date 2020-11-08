void			exec_command(t_stack *a_stack,
							 t_stack *b_stack,
							 const char *operation,
							 t_bool verbose)
{
	ft_putstr((verbose) ? "> " : NULL);
	if (ft_strequ(operation, "sa"))
		sx(a_stack, (verbose) ? "sa" : NULL, NULL);
	else if (ft_strequ(operation, "sb"))
		sx(b_stack, (verbose) ? "sb" : NULL, NULL);
	else if (ft_strequ(operation, "ss"))
		ss(a_stack, b_stack, (verbose) ? "ss" : NULL, NULL);
	else if (ft_strequ(operation, "pa"))
		px(a_stack, b_stack, (verbose) ? "pa" : NULL, NULL);
	else if (ft_strequ(operation, "pb"))
		px(b_stack, a_stack, (verbose) ? "pb" : NULL, NULL);
	else if (ft_strequ(operation, "ra"))
		rx(a_stack, (verbose) ? "ra" : NULL, NULL);
	else if (ft_strequ(operation, "rb"))
		rx(b_stack, (verbose) ? "rb" : NULL, NULL);
	else if (ft_strequ(operation, "rr"))
		rr(a_stack, b_stack, (verbose) ? "rr" : NULL, NULL);
	else if (ft_strequ(operation, "rra"))
		rrx(a_stack, (verbose) ? "rra" : NULL, NULL);
	else if (ft_strequ(operation, "rrb"))
		rrx(b_stack, (verbose) ? "rrb" : NULL, NULL);
	else if (ft_strequ(operation, "rrr"))
		rrr(a_stack, b_stack, (verbose) ? "rrr" : NULL, NULL);
	else
		terminate(ERR_OPERATION);
}

static t_bool	is_sorted(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*current;
	int				previous_number;

	i = 1;
	current = stack->head->next;
	previous_number = stack->head->number;
	while (i < stack->size)
	{
		if (current->number < previous_number)
			return (false);
		previous_number = current->number;
		i++;
		current = current->next;
	}
	return (true);
}

int	checher(int argc, char **argv, t_bool verbose, t_bool color)
{
	t_stack *a_stack;
	t_stack *b_stack;
	char	*line;
	ssize_t	size;

	b_stack = init_stack();
	check_dups((a_stack = parse(argc, argv)));
	ft_putstr((verbose) ? "> init\n" : NULL);
	if (verbose)
		print_stacks(a_stack, b_stack, color);
	while ((size = get_next_line(0, &line)) > 0)
	{
		exec_command(a_stack, b_stack, line, verbose);
		if (verbose)
			print_stacks(a_stack, b_stack, color);
		free(line);
	}
	if (size == -1)
		terminate(ERR_GNL);
	if (b_stack->head == NULL && is_sorted(a_stack))
		ft_putendl((color) ? COLOR_OK : OK);
	else
		ft_putendl((color) ? COLOR_KO : KO);
	free_stack(a_stack);
	free_stack(b_stack);
}

int	main(int argc, char **argv)
{
	t_bool	verbose;
	t_bool	color;
	t_bool	help;

	verbose = false;
	color = false;
	help = false;
	while (argc >= 2 &&
		   (!ft_strcmp(argv[1], "-v") || !ft_strcmp(argv[1], "-c")
			|| !ft_strcmp(argv[1], "-h")))
	{
		if (!ft_strcmp(argv[1], "-v"))
			verbose = true;
		else if (!ft_strcmp(argv[1], "-c"))
			color = true;
		else if (!ft_strcmp(argv[1], "-h"))
			help = true;
		argv++;
		argc--;
	}
	if (argc >= 2 && !help)
		checker(argc, argv, verbose, color);
	else if (help)
		ft_putendl(CH_HELP);
	return (0);
}


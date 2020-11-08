#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>

typedef enum
{
	false,
	true
} 						bool;

typedef struct			s_plist
{
	int					number;
	ssize_t				index;
	t_bool				stay;
	struct s_plist		*previous;
	struct s_plist		*next;
}						t_plist;

typedef struct			s_stack
{
	t_plist				*head;
	size_t				size;
	size_t				pairs;
	t_plist				*m_head;
}						t_stack;


#endif

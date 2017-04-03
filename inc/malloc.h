#ifndef MALLOC_H
# define MALLOC_H

# include "libft.h"
# include <sys/mman.h>

# include <stdio.h> // TO REMOVE


# define TINY 1024
# define SMALL 4096
# define MAX_BLOCK 100
# define MAP_SIZE sizeof(t_map)
# define BLOCK_SIZE sizeof(t_block)

typedef struct		s_block
{
	size_t			content;
	void			*ptr;
	struct s_block	*next;
}					t_block;

typedef struct		s_map
{
	int 			_id;
	void			*ptr;
	size_t			total;
	size_t			type;
	int				available;
	t_block			*first_block;
	struct s_map	*next;
}					t_map;

void	*my_malloc(size_t size);
void 	*store_in_map(t_map *map, size_t size);

//map
void	*new_map(size_t size);
void 	*add_new_map(size_t size);
void	*get_first_map(size_t size);

//block
void	init_blocks_in_map(t_map *map);
t_block 	*get_empty_block(t_map *map);

//size
size_t 	get_map_size(size_t size);
size_t	sizetype(size_t size);




#endif
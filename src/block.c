#include "malloc.h"

void	init_blocks_in_map(t_map *map)
{
	t_block *tmp_block;
	t_block *prev_block;
	int i;
	
	prev_block = NULL;
	i = -1;
	while (++i < MAX_BLOCK)
	{
		tmp_block = (t_block*)(map->first_block + (BLOCK_SIZE * i)); // Maybe just +1 to jump + BLOCK_SIZE
		tmp_block->content = 0;
		tmp_block->ptr = map + (MAX_BLOCK * BLOCK_SIZE) + (i * map->type);
		if(prev_block)
			prev_block->next = tmp_block;
		prev_block = tmp_block;
	}
	tmp_block->next = NULL;
}

t_block 	*get_empty_block(t_map *map)
{
	t_block *tmp;

	tmp = map->first_block;
	while(tmp->content && tmp)
		tmp = tmp->next;
	return (tmp);
}
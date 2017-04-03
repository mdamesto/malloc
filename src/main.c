#include "malloc.h"

void 	*store_in_map(t_map *map, size_t size)
{
	t_block *block;

	block = get_empty_block(map);
	if (block)
	{
		if (map->type > SMALL)
			return ((void*)block);
		block->content = size;
		map->available--;
		printf("store_in_map -- stored a block of %zu Bytes in Map %d (%d available)\n", size, map->_id, map->available);
		return (block->ptr);
	}
	else
		return (NULL);
}

void	*my_malloc(size_t size)
{
	t_map *map;

	if(!(map = get_first_map(size)))
	{
		printf("my_malloc -- get_first_map failed\n");
		return (NULL);
	}
	while (map)
	{
		if (size < map->type && map->available > 0)
			return (store_in_map(map, size));
		map = map->next;
	}
	return (store_in_map(add_new_map(size), size));
}

void	show_alloc_mem(void)
{
	t_map *map;
	t_block *block;

	map = get_first_map(0);
	while (map)
	{
		if (map->type == TINY)
		{
			printf("TINY: %p\n", map->first_block->ptr);
			block = map->first_block;
			while(block)
			{
				if (block->content)
					printf("%p - %p : %zu octets\n", block->ptr, (block->ptr + block->content), block->content);
				block = block->next;
			}
		}
		map = map->next;
	}
	map = get_first_map(0);
	while (map)
	{
		if (map->type == SMALL)
		{
			printf("SMALL: %p\n", map->first_block->ptr);
			block = map->first_block;
			while(block)
			{
				if (block->content)
					printf("%p - %p : %zu octets\n", block->ptr, (block->ptr + block->content), block->content);
				block = block->next;
			}
		}
		map = map->next;
	}
	map = get_first_map(0);
	while (map)
	{
		if (map->type > SMALL)
		{
			printf("LARGE: %p\n", map->first_block);
			block = map->first_block;
			printf("%p - %p : %zu octets\n", block, (block- + map->type), map->type);
		}
		map = map->next;
	}

}

int main()
{
	char *str;
	int i;

	printf("\nMain -- Starting\n");
	i = 0;
	while (++i <= 7)
	{
		printf("\n***Main -- malloc: %d***\n", i);
		str = my_malloc(500);
	}
	i = 0;
	while (++i <= 4)
	{
		printf("\n***Main -- malloc: %d***\n", i);
		str = my_malloc(1500);
	}
	i = 0;
	while (++i <= 2)
	{
		printf("\n***Main -- malloc: %d***\n", i);
		str = my_malloc(5000);
	}
	if (str)
		printf("\nMain -- End: Everything seems to be OK\n\n");
	else
		printf("\nMain -- End: my_malloc failed\n\n");

	show_alloc_mem();
	return (0);
}

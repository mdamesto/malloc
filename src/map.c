#include "malloc.h"

void	*new_map(size_t size)
{
	static int _id = 1;
	void *tmp;
	t_map *map;


	if ((tmp = mmap(0, get_map_size(size),
	PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0))
	== MAP_FAILED)
	{
		printf("new_map -- mmap failed\n");
		return (NULL);
	}

	map = (t_map*)tmp;
	map->_id = _id++;
	map->type = sizetype(size);
	map->available = 1;
	if (map->type <= SMALL)
		map->available = MAX_BLOCK;
	map->next = NULL;
	map->first_block = (t_block*)(map + MAP_SIZE); // Maybe just +1 to jump + MAP_SIZE
	printf("-->new_map -- map created (id: %d, type: %zu, avalaible: %d)\n", map->_id, map->type, map->available);
	if (map->type <= SMALL)
		init_blocks_in_map(map);

	return (map);
}

void 	*add_new_map(size_t size)
{
	t_map *map;

	map = get_first_map(size);
	while (map->next)
		map = map->next;
	return (map->next = new_map(size));
}

void	*get_first_map(size_t size)
{
	static void *map = NULL;

	if (map == NULL)
	{
		map = new_map(size);
		if (!map)
			printf("ERROR: get_first_map -- first map creation failed!\n");
	}
	return (map);
}

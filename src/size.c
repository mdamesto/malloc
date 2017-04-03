#include "malloc.h"

size_t	sizetype(size_t size)
{
	if (size <= TINY)
		return (TINY);
	else if (size <= SMALL)
		return (SMALL);
	else
		return (size);
}

size_t 	get_map_size(size_t size)
{
	if (size <= TINY)
		return (MAP_SIZE + MAX_BLOCK * (BLOCK_SIZE + TINY));
	else if (size <= SMALL)
		return (MAP_SIZE + MAX_BLOCK * (BLOCK_SIZE + SMALL));
	else
		return (MAP_SIZE + size);
}

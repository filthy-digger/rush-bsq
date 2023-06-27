#include "lib.h"

t_specification	get_spec(char *map_string)
{
	t_char_vector	first_line;
	t_specification	specification;

	first_line.start = map_string;
	first_line.end = strchr(map_string, '\n');
	first_line.current = first_line.start;
	specification.full = first_line.end[-1];
	specification.obstacle = first_line.end[-2];
	specification.empty = first_line.end[-3];
	return (specification);
}

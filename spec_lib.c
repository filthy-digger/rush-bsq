#include "lib.h"

t_specification	make_specification(const char *map_string)
{
	unsigned int	e;
	t_specification	specification;
	t_char_vector	first_line;

	specification.valid = false;
	first_line.start = map_string;
	first_line.end = strchr(first_line.start, '\n');
	if ((first_line.end != NULL) && (first_line.end - first_line.start >= 4))
	{
		specification.full = first_line.end[-1];
		specification.obstacle = first_line.end[-2];
		specification.empty = first_line.end[-3];
		if (specification.full != specification.obstacle
			&& specification.obstacle != specification.empty
			&& specification.full != specification.empty)
		{
			first_line.current = first_line.end - 4;
			e = 0;
			specification.number_of_lines = 0;
			while (first_line.start <= first_line.current)
				specification.number_of_lines += ft_ctoi(*first_line.current--)
					* ft_power(10, e++);
			specification.valid = true;
		}
	}
	return (specification);
}

void	show_spec(t_specification specification)
{
	ft_putstr("\nempty = ");
	ft_putchar(specification.empty);
	ft_putstr("\nobstacle = ");
	ft_putchar(specification.obstacle);
	ft_putstr("\nfull = ");
	ft_putchar(specification.full);
	ft_putstr("\nnumber of lines = ");
	ft_putsize(specification.number_of_lines);
}


#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

void	open_read(char *filename);

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		printf("FILENAME: ++++++++ %s ++++++++\n", argv[i]);
		open_read(argv[i]);
		i++;
	}
}

void	open_read(char *filename)
{
	int		fd;
	char	*line;
	int		k;
    int     l;

	fd = 0;
	k = 1;
    l = 0;
	if ((fd = open(filename, O_RDONLY, 0)) == -1)
		printf("Error: Failed to open file: %s", filename);
	while (fd != -1 && k == 1)
	{
        k = get_next_line(fd, &line);
		if (k  == 1 && line != NULL)
            printf("Line %i: %s\n", l, line);
        else if (line == NULL && k == 1)
            printf("LINE %i: \n", l);
        else if (k == 0)
            printf("        ++++++++ FILE END ++++++++\n");
        else
            printf("++++++++ ERROR READING FILE ++++++++\n");
        l++;
	}
	if (fd != -1 && ((fd = close(fd)) == -1))
		printf("Error: Could not close file: %s", filename);	
}

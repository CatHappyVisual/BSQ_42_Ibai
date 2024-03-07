#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	printStr(char *str);

int	main(int argc, char **argv)
{
	char	*file;
	int		fd;
	char	buf[100];
	char	line[100][100];
	ssize_t	nr_bytes;
	int		c;
	int		cl;
	int		cc;

	c = 0;
	cl = 0;
	cc = 0;
	if (argc == 2)
	{
		file = argv[1];
		fd = open(file, O_RDONLY);
		if (fd == -1)
			printf("Error al abrir el archivo");
		else
		{
			nr_bytes = read(fd, buf, 81);
			close(fd);
			if (nr_bytes == 0)
			{
				printf("Archivo vacio \n");
			}
			else
			{
				while (buf[c] != '\0')
				{
					if (buf[c] == '\n')
					{
						line[cl][cc] = '\0'; 
						cl++;
						cc = -1;
					}
					else
						line[cl][cc] = buf[c];
				  	cc++;	
					c++;
				}
			}
		}
		cl = 0;
		while (line[cl][0] != 0 )
		{
			printStr(line[cl]);
			printf("\n");
			cl++;
		}
	}
	return (0);
}

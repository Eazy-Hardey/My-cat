#include <fcntl.h>	
#include <stdio.h>	 
#include <unistd.h>	

int main( int argc, char *argv[] )
{
    int i, lt, ch; 

    for (i = 1; i < argc; i++)
    {
        lt = open(argv[i], O_RDONLY);
        if (lt < 0)
        {
            perror(argv[i]);
            continue;
        }
        while (read(lt, &ch, 1) == 1) write(STDOUT_FILENO, &ch, 1);
        close(lt);
                }
}
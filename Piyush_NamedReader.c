#include <stdio.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#include <unistd.h> 
  
int main() 
{ 
	int fd,retval;
	char buffer[10];
while(1)
{
	fd=open("/temp/myfifo",O_RDONLY);
	retval=read(fd,buffer,sizeof(buffer));
	fflush(stdin);
	write(1,buffer,sizeof(buffer));
	close(fd);
}
	return 0;
}

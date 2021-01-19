#include <stdio.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fcntl.h> 
#include <unistd.h> 
  
int main() 
{ 
	int fd,retval;
	char buffer[10]="STUDENT ID";
while(1)
{
	fflush(stdin);
	retval=mkfifo("/temp/myfifo",0666);
	fd=open("/temp/myfifo",O_WRONLY);
	write(fd,buffer,sizeof(buffer));
	close(fd);
}
	return 0;
}

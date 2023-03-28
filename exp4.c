#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main()
{
    int fd;
    char wbuf[]="Hello, World!";
    char rbuf[225];

    char fileName[225];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    
    fd = open(fileName, O_RDWR);
    
    lseek(fd, 0, SEEK_END);
    write(fd, wbuf, strlen(wbuf));
    	
    lseek(fd, 0, SEEK_SET);
    read(fd, rbuf, 99);
    
    
    printf("Data read from file: %s\n", rbuf);

    close(fd);

    return 0;
}


/*
OUTPUT
Aswin Dev
Enter the file name: hello.txt
Data read from file: Hello, World!

*/

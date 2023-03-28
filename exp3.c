#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>	

int main(void)
{
    pid_t pid;
    int status;
    DIR *dirp;
    struct dirent *direntp;
    struct stat node;
    stat("exp3.c", &node);
    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed");
    }
    else if (pid == 0)
    {
        printf("Child process: PID = %d\n", getpid());

        execl("/bin/ls", "ls", "-l", NULL);
    }
    else
    {

        wait(NULL);

        printf("\nParent process: PID = %d\n", getpid());

        dirp = opendir("folder");

        while ((direntp = readdir(dirp)) != NULL)
        {
            printf("%s\t\n", direntp->d_name);
        }

        closedir(dirp);

        if (node.st_ino == 0)
        {
            printf("\nSuch a file does not exist!!");
        }
        else
        {
            printf("\nThe Inode/Serial number: %ld", node.st_ino);
            printf("\nThe Block size: %ld", node.st_blksize);
            printf("\nThe Access time: %ld", node.st_atime);
            printf("\nThe last modified time: %ld", node.st_mtime);
            printf("\nThe group id: %d", node.st_gid);
            printf("\nThe size of file: %ld", node.st_size);
            printf("\nThe permissions: %d", node.st_mode);
            printf("\nThe User ID: %d \n", node.st_uid);
        }

        
    }

    exit(0);
}


/*
OUTPUT:
Child process: PID = 5728
total 48
-rwxrwxr-x 1 ai17 ai17 17144 Mar 28 14:18 a.out
-rw-rw-r-- 1 ai17 ai17  1438 Mar 28 14:11 exp3.c
-rw-rw-r-- 1 ai17 ai17   537 Mar 28 14:16 exp4.c
-rw-rw-r-- 1 ai17 ai17    21 Mar 28 13:55 FCFS.c
drwxrwxr-x 2 ai17 ai17  4096 Mar  7 14:43 folder
-rw-rw-r-- 1 ai17 ai17    27 Mar 28 14:16 hello.txt
-rw-rw-r-- 1 ai17 ai17   325 Mar  7 15:24 systemCalls2.c
-rw-rw-r-- 1 ai17 ai17   359 Mar  7 15:33 systemCalls.c
-rw-rw-r-- 1 ai17 ai17     0 Mar  7 14:56 test.txt

Parent process: PID = 5727
hellworld.txt	
..	
.	
world.txt	

The Inode/Serial number: 9192136
The Block size: 4096
The Access time: 1679992920
The last modified time: 1679992917
The group id: 1002
The size of file: 1438
The permissions: 33204
The User ID: 1002 
*/




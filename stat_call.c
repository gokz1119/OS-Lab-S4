// Program to implrmrnt the stat system call
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s file_name\n", argv[0]);
        return 1;
    }

    struct stat fileStat;
    if (stat(argv[1], &fileStat) < 0)
        return 1;

    printf("Information about %s\n", argv[1]);
    printf("---------------------------\n");
    printf("File Size: \t\t%d bytes\n", (int)fileStat.st_size);
    printf("User ID of Owner: \t%d\n", (int)fileStat.st_uid);
    printf("Number of Links: \t%d\n", (int)fileStat.st_nlink);
    printf("File inode: \t\t%d\n", (int)fileStat.st_ino);
    return 0;
}
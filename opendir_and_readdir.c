// Program to implement the opendir and readdir system calls
#include <stdio.h>
#include <dirent.h>

int main()
{
    struct dirent *dentry;
    DIR *dr = opendir("test_dir"); //Opening test_dir
    if (dr == NULL)                //Failed to open directory
    {
        printf("Couldn't open the directory\n");
        return 1;
    }

    printf("test_dir directory was opened successfully\n");
    printf("------------------------------------------\n");
    //Directory has been opened successfully
    printf("Inode number\t\tName\n");
    while ((dentry = readdir(dr)) != NULL)
        printf("%d\t\t\t%s\n", (int)dentry->d_ino, dentry->d_name); //Prints the contents of the test_dir

    printf("------------------------------------------\n");
    printf("Closing test_dir directory\n");
    closedir(dr);
    return 0;
}
#include <stdio.h>
#include <windows.h>

int main (int argc, LPTSTR argv []){
    if (argc != 3){
        printf("usage : cpcf file1 file2\n");
        return 1; 
    }

    if (!CopyFile(argv[1], argv[2], FALSE)){
        printf("error copying file");
        return 2;
    }

    return 0;
}
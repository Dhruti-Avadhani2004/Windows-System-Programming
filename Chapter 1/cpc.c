#include <stdio.h>
#include <errno.h>
#define BUF_SIZE 256

int main (int argc, char * argv[]){
    FILE *inFile, *outFile;
    char arr[BUF_SIZE];
    size_t inBytes, outBytes;

    if (argc != 3){
        printf("usage : cpc file1 file2\n");
        return 1;
    }

    inFile = fopen(argv[1], "rb");
    if (inFile == NULL){
        perror(argv[1]);
        return 2;
    }

    outFile = fopen(argv[2], "wb");
    if (outFile == NULL){
        perror(argv[2]);
        return 3;
    }

    while ((inBytes = fread(arr, 1, BUF_SIZE, inFile)) > 0){
        outBytes = fwrite(arr, 1, inBytes, outFile);

        if (inBytes != outBytes){
            perror("fatal copy error.");
            fclose(inFile);
            fclose(outFile);
            return 4;
        }
    }

    return 0;

}
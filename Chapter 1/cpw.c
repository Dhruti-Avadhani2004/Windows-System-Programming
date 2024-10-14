#include <stdio.h>
#include <windows.h>

// #include <winnt.h>
// #include <winbase.h>

#define BUF_SIZE 256

int main (int argc, LPTSTR argv[]){
    HANDLE Hin, Hout;
    DWORD Nin, Nout;
    char arr[BUF_SIZE];

    if (argc != 3){
        printf("usage : cpw file1 file2\n");
        return 1;
    }

    Hin = CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (Hin == INVALID_HANDLE_VALUE){
        printf("cannot open input file");
        return 2;
    }

    Hout = CreateFile(argv[2], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (Hout == INVALID_HANDLE_VALUE){
        printf("cannot open output file");
        return 3;
    }

    while(ReadFile(Hin, arr, BUF_SIZE, &Nin, NULL) && Nin > 0){
        WriteFile(Hout, arr, Nin, &Nout, NULL);

        if (Nin != Nout){
            printf("fatal copy error.");
            return 4;
        }

    }

    CloseHandle(Hin);
    CloseHandle(Hout);

    printf("file copied successfully\n");

    return 0;

}

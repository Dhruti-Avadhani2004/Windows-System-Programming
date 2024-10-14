##Pre-defined Datatypes in Windows
1. BOOL (32-bit object for storing single logical value)
2. HANDLE (a handle for kernel object)
3. DWORD (ubiquitous 32-bit unsigned interger)
4. LPTSTR (a string pointer)
5. LPSECURITY_ATTRIBUTES

##Interesting Libraries to Look at
1. windows.h
2. winnt.h
3. winbase.h

##File Copying using the Standard C Library
###Libraries used :
1. stdio.h
2. errno.h
###Command-line : 
int argc, char * argv []
###Keywords and Functions used : 
1. FILE
2. size_t
3. fopen, perror, "rb"
4. fread(arr, 1, BUF_SIZE, inFile)
5. fwrite(arr, 1, inBytes, outFile)
6. fclose

##File Copying with Windows
###Libraries used : 
1. stdio.h
2. windows.h
###Command-line : 
int argc, LPTSTR argv []
###Keywords and Functions used : 
1. HANDLE
2. DWORD
3. CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL)
4. CreateFile(argv[2], GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)
5. ReadFile(Hin, arr, BUF_SIZE, &Nin, NULL)
6. WriteFile(Hout, arr, Nin, &Nout, NULL)
7. CloseHandle(Hin); CloseHandle(Hout);

##File Copying with a Windows Convenience Function
###Libraries Used : 
1. stdio.h
2. windows.h
###Command-line : 
int argc, LPTSTR argv []
###Keywords and Functions used : 
1. CopyFile(argv[1], argv[2], TRUE)

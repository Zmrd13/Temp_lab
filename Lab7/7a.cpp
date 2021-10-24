#include <iostream>
#include <windows.h>

using namespace std;

int main(){
	LPCSTR name = "psapi.dll";
	HINSTANCE hDllInstance = LoadLibrary(name);
	typedef DWORD(*functionDll)();
//	DWORD timeGetTime();
	functionDll myFunc = (functionDll)GetProcAddress(hDllInstance, "GetProcessMemoryInfo");
	cout << "func = " << myFunc << endl;
	cout<<"first"<<endl;
	Sleep(20000);
	FreeLibrary(hDllInstance);
	cout<<"second"<<endl;
	Sleep(20000);
}

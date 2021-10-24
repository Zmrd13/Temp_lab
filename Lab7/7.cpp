#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <psapi.h>
#include <TlHelp32.h>
#include <vector>
#include <imagehlp.h>
#include <iostream>
using namespace std;
 
int main( int argc, char *argv[] )
{
    DWORD aProcesses[1024]; 
    DWORD cbNeeded; 
    DWORD cProcesses;
    unsigned int i;


    if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) ) //��������� �� ������ ���������, ������ �������, ����� ������, ������������ � �������
        return 1;

    cProcesses = cbNeeded / sizeof(DWORD);
    
    vector<DWORD> pid;
    
    PROCESSENTRY32 entry;  //��������� ������ �� ������ ���������, ����������� � ��������� �������� ������������ ��� �������� ������������� ������.
    entry.dwSize = sizeof(PROCESSENTRY32);  //������ ���������
 
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //������ ������ ��������� ���������, � ����� ���, ������� � �������, ������������ ����� ����������.
	//(�������� ��� �������� � ������� � ������������ ������, ������������� ��������, ������� ����� ������� � ������������ ������. ���� �������� ����� ���� ����� ����, ����� ������� ������� �������)
 
    if(Process32First(snapshot, &entry)){ //��������� ���������� � ������ ��������, ������������ � ������������ ������ �������.
        while(Process32Next(snapshot, &entry)){ //��������� ���������� � ��������� ��������, ���������� � ������������ ������ �������.
            if(!stricmp(entry.szExeFile, argv[1])){ //��������� ��������� ����� ��� ����� ��������(������ 1 ��������� �� 2 �������
                pid.push_back(entry.th32ProcessID);
            }
		}
	}
                
                
    for(int i = 0; i < pid.size(); i++){
		HMODULE hMods[1024];
	    HANDLE hProcess;
	    DWORD cbNeeded;
	    unsigned int j;
		cout<<endl<<"Process ID: "<< pid[i] <<endl;
	   
	    hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,FALSE, (DWORD)pid[i] ); //��������� ������������ ������ ���������� ��������(����� �������, �������� �� ��������� ���� ����������, 
																									//������������� ���������� ��������, ������� ����� ������)
	    if (NULL == hProcess){
	    	cout << "hProcess = NULL" << endl;
	        return 1;
		}
		
	
	    if( EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)) //��������� ���������� ��� ������� ������ � ��������� ��������.
	    {
	    	
	        for ( j = 0; j < (cbNeeded / sizeof(HMODULE)); j++ )
	        {
	            TCHAR szModName[MAX_PATH];
				
	            if ( GetModuleFileNameEx( hProcess, hMods[j], szModName,sizeof(szModName) / sizeof(TCHAR))) //��������� ������ ���� � �����, ����������� ��������� ������(���������� ��������, ����������� ������, 
	            //A handle to the module, ��������� �� �����, ������� �������� ������ ���� � ������, ������ ������ lpFilename � ��������)
	            {
					cout<<szModName<<endl;
				}
	        }
	    }
	    
	    CloseHandle( hProcess );
	}
}

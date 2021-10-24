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


    if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) ) //указатель на массив процессов, размер массива, Число байтов, возвращаемых в массиве
        return 1;

    cProcesses = cbNeeded / sizeof(DWORD);
    
    vector<DWORD> pid;
    
    PROCESSENTRY32 entry;  //Описывает запись из списка процессов, находящихся в системном адресном пространстве при создании моментального снимка.
    entry.dwSize = sizeof(PROCESSENTRY32);  //размер структуры
 
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //Делает снимок указанных процессов, а также куч, модулей и потоков, используемых этими процессами.
	//(Включает все процессы в системе в моментальный снимок, Идентификатор процесса, который будет включен в моментальный снимок. Этот параметр может быть равен нулю, чтобы указать текущий процесс)
 
    if(Process32First(snapshot, &entry)){ //Извлекает информацию о первом процессе, обнаруженном в моментальном снимке системы.
        while(Process32Next(snapshot, &entry)){ //Извлекает информацию о следующем процессе, записанную в моментальном снимке системы.
            if(!stricmp(entry.szExeFile, argv[1])){ //Выполняет сравнение строк без учета регистра(строка 1 совпадает со 2 строкой
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
	   
	    hProcess = OpenProcess( PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,FALSE, (DWORD)pid[i] ); //Открывает существующий объект локального процесса(права доступа, процессы не наследуют этот дескриптор, 
																									//Идентификатор локального процесса, который будет открыт)
	    if (NULL == hProcess){
	    	cout << "hProcess = NULL" << endl;
	        return 1;
		}
		
	
	    if( EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)) //Извлекает дескриптор для каждого модуля в указанном процессе.
	    {
	    	
	        for ( j = 0; j < (cbNeeded / sizeof(HMODULE)); j++ )
	        {
	            TCHAR szModName[MAX_PATH];
				
	            if ( GetModuleFileNameEx( hProcess, hMods[j], szModName,sizeof(szModName) / sizeof(TCHAR))) //Извлекает полный путь к файлу, содержащему указанный модуль(Дескриптор процесса, содержащего модуль, 
	            //A handle to the module, Указатель на буфер, который получает полный путь к модулю, Размер буфера lpFilename в символах)
	            {
					cout<<szModName<<endl;
				}
	        }
	    }
	    
	    CloseHandle( hProcess );
	}
}

#include <windows.h>
#include <iostream>

using namespace std;

LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
#define ID_MYBUTTON 1    /* ������������� ��� �������� ������ �������� ���� */
#define ID_MYBUTTON2 2

HINSTANCE hInst;
string str = "";
LPCSTR buf;
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR,int ss) {
 	/* ������� � ������������ ����� �������� ���� */
 	WNDCLASS wc;
 	wc.style=0;
 	wc.lpfnWndProc=MainWinProc;
 	wc.cbClsExtra=wc.cbWndExtra=0;
 	wc.hInstance=hInst;
 	wc.hIcon=NULL;
 	wc.hCursor=NULL;
 	wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
 	wc.lpszMenuName=NULL;
 	wc.lpszClassName="Example";
 	if (!RegisterClass(&wc)) return FALSE;

 
 	HWND hMainWnd=CreateWindow("Example","EXAMPLE 4",WS_OVERLAPPEDWINDOW,
  	CW_USEDEFAULT,CW_USEDEFAULT,530,120,NULL,NULL,hInst,NULL);
 	if (!hMainWnd) return FALSE;
 	ShowWindow(hMainWnd,ss);
 	UpdateWindow(hMainWnd);

 	MSG msg; 
 	while (GetMessage(&msg,NULL,0,0)) {
  		TranslateMessage(&msg); 
  		DispatchMessage(&msg); 
 	} 
 	return msg.wParam; 
}


LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
	static HWND textBox;
 	switch (msg) {
  		case WM_CREATE:
   
   			CreateWindow("button","1",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
   	 		5,10,250,20,hw,(HMENU)ID_MYBUTTON,NULL,NULL);
   	 		CreateWindow("button","2",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
   	 		260,10,250,20,hw,(HMENU)ID_MYBUTTON2,NULL,NULL);
    
    		textBox = CreateWindow("static", "",
            	WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 5, 35, 500, 40,
            	hw, 0, hInst, NULL);
   
   			return 0;
  		case WM_COMMAND:
   
   			if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON)){
				COPYDATASTRUCT dataa;
					cout << str;
					HWND hPr;
					buf = (LPCSTR)(str.c_str());
					hPr = FindWindow("Example 4 MainWnd Class","CALC");
					dataa.cbData = strlen(buf);
					dataa.lpData = (PVOID)str.c_str();
					SendMessage(hPr,WM_COPYDATA,(WPARAM)GetFocus(),(LPARAM)&dataa);
					return 0;
				}
   			if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON2)){
			   	str += "returned ";
			   	buf = (LPCSTR)(str.c_str());
				SetWindowText(textBox, buf);
				return 0;
			}
   		case WM_COPYDATA:{
   			char mas[256] = {0};
			memcpy(mas,((COPYDATASTRUCT*)lp)->lpData,((COPYDATASTRUCT*)lp)->cbData);
 			LPCSTR result_port=(LPCSTR)(mas);
    		SetWindowText(textBox,result_port);
    		return 0;
   		}
  		case WM_DESTROY: 
   			PostQuitMessage(0);
   			return 0;
 	}
 	return DefWindowProc(hw,msg,wp,lp);
}

#include <windows.h>
#include <string>
#include <iostream>
using namespace std;

LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
#define ID_MYBUTTON1 1   
#define ID_MYBUTTON2 2
#define ID_MYBUTTON3 3
#define ID_MYBUTTON4 4
#define ID_MYBUTTON5 5
#define ID_MYBUTTON6 6
#define ID_MYBUTTON7 7
#define ID_MYBUTTON8 8
#define ID_MYBUTTON9 9
#define ID_MYBUTTON0 16
#define ID_MYBUTTON_PLUS 10
#define ID_MYBUTTON_MINUS 11
#define ID_MYBUTTON_UM 12
#define ID_MYBUTTON_DEL 13
#define ID_MYBUTTON_RAVNO 14
#define EDIT1 15
string str;
LPCSTR buf;
HINSTANCE hInst;
bool flagNull = 0, haveSign = 0;

string _to_string(double value)
    {
        char buffer[100] = {};
		sprintf(buffer, "%f", value);
		string s = buffer;
		return s;
    }

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR,int ss) {
 	
 	WNDCLASS wc;
 	wc.style=0;
 	wc.lpfnWndProc=MainWinProc;
 	wc.cbClsExtra=wc.cbWndExtra=0;
 	wc.hInstance=hInst;
 	wc.hIcon=NULL;
 	wc.hCursor=NULL;
 	wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+2);
 	wc.lpszMenuName=NULL;
 	wc.lpszClassName="Example 4 MainWnd Class";
 	if (!RegisterClass(&wc)) return FALSE;

 	HWND hMainWnd=CreateWindow("Example 4 MainWnd Class","CALC",WS_OVERLAPPEDWINDOW,
  	CW_USEDEFAULT,CW_USEDEFAULT,180,270,NULL,NULL,hInst,NULL);
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
	static HWND text;
 	switch (msg) {
  		case WM_CREATE:{
   	
   			CreateWindow("button","1",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		5,5,50,20,hw,(HMENU)ID_MYBUTTON1,NULL,NULL);
    
			CreateWindow("button","2",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		55,5,50,20,hw,(HMENU)ID_MYBUTTON2,NULL,NULL);
    
    		CreateWindow("button","3",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		105,5,50,20,hw,(HMENU)ID_MYBUTTON3,NULL,NULL);
    
    		CreateWindow("button","4",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		5,25,50,20,hw,(HMENU)ID_MYBUTTON4,NULL,NULL);
    
    		CreateWindow("button","5",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		55,25,50,20,hw,(HMENU)ID_MYBUTTON5,NULL,NULL);
    
    		CreateWindow("button","6",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		105,25,50,20,hw,(HMENU)ID_MYBUTTON6,NULL,NULL);
    
    		CreateWindow("button","7",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		5,45,50,20,hw,(HMENU)ID_MYBUTTON7,NULL,NULL);
    
    		CreateWindow("button","8",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		55,45,50,20,hw,(HMENU)ID_MYBUTTON8,NULL,NULL);
    
    		CreateWindow("button","9",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		105,45,50,20,hw,(HMENU)ID_MYBUTTON9,NULL,NULL);
    		
    		CreateWindow("button","0",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		55,65,50,20,hw,(HMENU)ID_MYBUTTON0,NULL,NULL);
    
    		CreateWindow("button","+",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		5,85,75,20,hw,(HMENU)ID_MYBUTTON_PLUS,NULL,NULL);
    
    		CreateWindow("button","-",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		80,85,75,20,hw,(HMENU)ID_MYBUTTON_MINUS,NULL,NULL);
    
    		CreateWindow("button","*",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		5,105,75,20,hw,(HMENU)ID_MYBUTTON_UM,NULL,NULL);
    
    		CreateWindow("button","/",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		80,105,75,20,hw,(HMENU)ID_MYBUTTON_DEL,NULL,NULL);
    
    		CreateWindow("button","=================",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    		5,135,150,20,hw,(HMENU)ID_MYBUTTON_RAVNO,NULL,NULL);
    
    		text = CreateWindow("static", "",
            	WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 5, 155, 150, 40,
            	hw, 0, hInst, NULL);
    
   			return 0;
}
  	case WM_COMMAND:
   		
   		
  if(HIWORD(wp) == 0){
			switch(LOWORD(wp)){
				case ID_MYBUTTON1:
					str += "1";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON2:
					str += "2";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON3:
					str += "3";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON4:
					str += "4";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON5:
					str += "5";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON6:
					str += "6";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON7:
					str += "7";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON8:
					str += "8";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON9:
					str += "9";
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					flagNull = 1;
					return 0;
				case ID_MYBUTTON0:
					if(flagNull){
						str += "0";
						buf = (LPCSTR)(str.c_str());
						SetWindowText(text, buf);
						return 0;
					}
					else{
						return 0;
					}
				case ID_MYBUTTON_PLUS:
					if(!haveSign){
						str += "+";
						buf = (LPCSTR)(str.c_str());
						SetWindowText(text, buf);
						flagNull = 0;
						haveSign = 1;
						return 0;
					}
					else{
						return 0;
					}	
				case ID_MYBUTTON_MINUS:
					if(!haveSign){
						str += "-";
						buf = (LPCSTR)(str.c_str());
						SetWindowText(text, buf);
						flagNull = 0;
						haveSign = 1;
						return 0;
					}
					else{
						return 0;
					}
				case ID_MYBUTTON_UM:
					if(!haveSign){
						str += "*";
						buf = (LPCSTR)(str.c_str());
						SetWindowText(text, buf);
						flagNull = 0;
						haveSign = 1;
						return 0;
					}
					else{
						return 0;
					}
				case ID_MYBUTTON_DEL:
					if(!haveSign){
						str += "/";
						buf = (LPCSTR)(str.c_str());
						SetWindowText(text, buf);
						flagNull = 0;
						haveSign = 1;
						return 0;
					}
					else{
						return 0;
					}
				case ID_MYBUTTON_RAVNO:{
					bool firstFlag = 0, secondFlag = 0, signFlag = 0;
					double a, b, rez;
					char sign;
					for(int i = 0; i < str.length(); ++i){
						if(signFlag == 0){
							if(str[i] == '1'){
								if(!firstFlag == 0){
									a = 1;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 1;
								}
							}
							if(str[i] == '2'){
								if(!firstFlag == 0){
									a = 2;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 2;
								}
							}
							if(str[i] == '3'){
								if(!firstFlag == 0){
									a = 3;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 3;
								}
							}
							if(str[i] == '4'){
								if(!firstFlag == 0){
									a = 4;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 4;
								}
							}
							if(str[i] == '5'){
								if(!firstFlag == 0){
									a = 5;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 5;
								}
							}
							if(str[i] == '6'){
								if(!firstFlag == 0){
									a = 6;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 6;
								}
							}
							if(str[i] == '7'){
								if(!firstFlag == 0){
									a = 7;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 7;
								}
							}
							if(str[i] == '8'){
								if(!firstFlag == 0){
									a = 8;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 8;
								}
							}
							if(str[i] == '9'){
								if(!firstFlag == 0){
									a = 9;
									firstFlag = 1;
								}
								else{
									a = a * 10 + 9;
								}
							}
							if(str[i] == '0'){
									a = a * 10;
							}
							
							if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
								sign = str[i];
								signFlag = 1;
							}
						}
						else{
							
							if(str[i] == '1'){
								if(!secondFlag == 0){
									b = 1;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 1;
								}
							}
							if(str[i] == '2'){
								if(!secondFlag == 0){
									b = 2;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 2;
								}
							}
							if(str[i] == '3'){
								if(!secondFlag == 0){
									b = 3;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 3;
								}
							}
							if(str[i] == '4'){
								if(!secondFlag == 0){
									b = 4;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 4;
								}
							}
							if(str[i] == '5'){
								if(!secondFlag == 0){
									b = 5;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 5;
								}
							}
							if(str[i] == '6'){
								if(!secondFlag == 0){
									b = 6;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 6;
								}
							}
							if(str[i] == '7'){
								if(!secondFlag == 0){
									b = 7;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 7;
								}
							}
							if(str[i] == '8'){
								if(!secondFlag == 0){
									b = 8;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 8;
								}
							}
							if(str[i] == '9'){
								if(!secondFlag == 0){
									b = 9;
									secondFlag = 1;
								}
								else{
									b = b * 10 + 9;
								}
							}
							if(str[i] == '0'){
									b = b * 10;
							}
						}
					}
					if(sign == '+')
						rez = a + b;
					else if(sign == '-')
							rez = a - b;
						else if(sign == '*')
								rez = a * b;
							else if(sign == '/')
									rez = a / b;
					
					str = _to_string(rez);
					buf = (LPCSTR)(str.c_str());
					SetWindowText(text, buf);
					COPYDATASTRUCT data;
					HWND hPr;
					hPr = FindWindow("Example","EXAMPLE 4");
					data.cbData = strlen(buf);
					data.lpData = (PVOID)str.c_str();
					SendMessage(hPr,WM_COPYDATA,(WPARAM)GetFocus(),(LPARAM)&data);



					str = "";
					haveSign = 0;
					flagNull = 0;
					return 0;		
			}
		}
	}
	case WM_COPYDATA:{
   			char mas[256] = {0};
			memcpy(mas,((COPYDATASTRUCT*)lp)->lpData,((COPYDATASTRUCT*)lp)->cbData);
 			LPCSTR result_port=(LPCSTR)(mas);
    		SetWindowText(text,result_port);
    		return 0;
   		}
  	case WM_DESTROY:
   /* ������������ ������ ����, ��������� ����� ����������� */
   		PostQuitMessage(0);
   		return 0;
 	}
 	
	return DefWindowProc(hw,msg,wp,lp);
}

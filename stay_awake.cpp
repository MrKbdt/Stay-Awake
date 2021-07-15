#include <windows.h>
#include <time.h>

//#include <iostream>
//#include <conio.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>

/*
The following sample program turns the NUM LOCK light on if it is off.
The SetNumLock function defined here simulates pressing the NUM LOCK key,
using keybd_event() with a virtual key of VK_NUMLOCK. It takes a boolean
value that indicates whether the light should be turned off (FALSE) or on (TRUE).

The same technique can be used for the CAPS LOCK key (VK_CAPITAL) and the
SCROLL LOCK key (VK_SCROLL).
*/

// using namespace std;

void delay(int number_of_seconds)
{
   int milli_seconds = 1000 * number_of_seconds;
   clock_t start_time = clock();
   while (clock() < start_time + milli_seconds)
      ;
}

void SetNumLock(BOOL bState)
{
   BYTE keyState[256];

   GetKeyboardState((LPBYTE)&keyState);
   if ((bState && !(keyState[VK_NUMLOCK] & 1)) ||
       (!bState && (keyState[VK_NUMLOCK] & 1)))
   {
      // Simulate a key press
      keybd_event(VK_NUMLOCK,
                  0x45,
                  KEYEVENTF_EXTENDEDKEY | 0,
                  0);

      // Simulate a key release
      keybd_event(VK_NUMLOCK,
                  0x45,
                  KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                  0);
   }
}

int main()
{

int toggle = 0;
   
   while (1)
   {
      if (toggle == 0)
      {
         toggle = 1;
         SetNumLock(TRUE);
      }
      else
      {
         toggle = 0;
         SetNumLock(FALSE);
      }

      delay(2);
   }
}

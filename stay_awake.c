/*

# Stay_Awake
Windows 10 Utility: Stops screen saver and inactivity timeout from kicking in with virtual keyboard activity.

The following program toggles the NUM LOCK key light.
The SetNumLock function defined here simulates pressing the NUM LOCK key
using keybd_event() with a virtual key of VK_NUMLOCK. It takes a boolean
value that indicates whether the light should be turned off (FALSE) or on (TRUE).
The same technique can be used for the CAPS LOCK key (VK_CAPITAL) and the
SCROLL LOCK key (VK_SCROLL).

keybd_event function (winuser.h)
https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-keybd_event

Virtual-Key Codes
https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

Also creates a visual in the command shell which emulates a waiting command prompt.

*/

#include <windows.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_CHARS 10

void SetNumLock(BOOL bState)
{
   BYTE keyState[256];
   GetKeyboardState((LPBYTE)&keyState);
   if ((bState && !(keyState[VK_NUMLOCK] & 1)) || (!bState && (keyState[VK_NUMLOCK] & 1)))
   {
      keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
      keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
   }
}

int main()
{
   char userID[MAX_CHARS];
   int toggle = 0;
   
   printf("Enter your Windows user ID: ");
   fgets(userID, MAX_CHARS, stdin);
   userID[strcspn(userID, "\n")] = 0;

   system("title Command Prompt");
   system("cls");
   printf("Microsoft Windows [Version 10.0.18363.1646]\n"
          "(c) Microsoft Corporation. All rights reserved.\n\n"
          "C:\\Users\\%s>",
          userID);

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
      // usleep(300000000); // 300 seconds / 5 mins
      // usleep(60000000); // 60 seconds
      usleep(3000000); // 3 seconds for testing
   }
}

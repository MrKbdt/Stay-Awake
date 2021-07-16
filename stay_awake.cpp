#include <windows.h>
#include <time.h>
#include <unistd.h>

void SetNumLock(BOOL bState) {
   BYTE keyState[256];
   GetKeyboardState((LPBYTE)&keyState);
   if ((bState && !(keyState[VK_NUMLOCK] & 1)) || (!bState && (keyState[VK_NUMLOCK] & 1))) {
      keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
      keybd_event(VK_NUMLOCK, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
   }
}

int main(){
   int toggle = 0;
   
   while (1) {
      if (toggle == 0) {
         toggle = 1;
         SetNumLock(TRUE);
      }
      else {
         toggle = 0;
         SetNumLock(FALSE);
      }
      usleep(60000000);
   } 
}
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <unistd.h>

using namespace std;

int main(){

   int x = 1, y = 1;
   POINT xypos;

   while (1) {
      SetCursorPos(x, y);
      usleep(30000000);
      if (x == 1) {
         x = 2;
         y = 2;
      } else {
         x = 1;
         y = 1;
      }
   }
}
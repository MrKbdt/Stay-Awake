#include <windows.h>
#include <time.h>

//#include <iostream>
//#include <conio.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>


using namespace std;

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main(){

   int x = 1, y = 400;
   POINT xypos;

   while (1) {
      SetCursorPos(x, y);
      //usleep(10000000);
      
      if (x == 1) {
         x = 400;
         y = 1;
      } else { 
         x = 1;
         y = 400;
      }
      // //printf("\n");
      // printf("C:\\Users\\c1121002>");
      // delay(5);
      // printf("ping 8.8.8.8\n");
      // delay(1);
      // printf("Reply from 8.8.8.8: bytes=32 time=7ms TTL=53\n");
      // delay(1);
      // printf("Reply from 8.8.8.8: bytes=32 time=7ms TTL=58\n");
      // delay(1);
      // printf("Reply from 8.8.8.8: bytes=32 time=7ms TTL=47\n");
      // delay(1);
      // printf("Reply from 8.8.8.8: bytes=32 time=7ms TTL=55\n");
      // printf("C:\\Users\\c1121002>");
      delay(10);
      // system("CLS");
      // //return 0;
   }
}
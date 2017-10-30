#include <windows.h>
#include <stdio.h>

int main(int argc,char **argv) {
   char shortBuffer[MAX_PATH];
   char cmdBuff[MAX_PATH + 64];
   GetShortPathName(argv[1],shortBuffer,sizeof(shortBuffer));
   mciSendString("Close All",NULL,0,0);
   sprintf(cmdBuff,"Open %s Type MPEGVideo Alias theMP3",shortBuffer);
   mciSendString(cmdBuff,NULL,0,0);
   mciSendString("Play theMP3 Wait",NULL,0,0);
   return 0;
}

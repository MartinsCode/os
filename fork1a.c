#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include  <unistd.h>

#define   MAX_COUNT  200
#define   BUF_SIZE   100

// Comment out to not use color:
#define COLOR "Ja, biddeschoen!"

#ifdef COLOR
#define C_CHILD "\x1b[31m"   // some red
#define C_PARENT "\x1b[34m"  // some blue - use ANSI as you like
#endif

#ifndef COLOR
#define C_CHILD ""
#define C_PARENT ""
#endif

void main(void)
{
     pid_t  pid;
     int    i;
     char   buf[BUF_SIZE];

     int f = fork();
     pid = getpid();
     for (i = 1; i <= MAX_COUNT; i++) {
          int no = 0;
          if (f == 0) {
              // we are the child
              no = sprintf(buf, C_CHILD);
          } else {
              no = sprintf(buf, C_PARENT);
          }
          sprintf(buf + no, "This line is from pid %d, value = %d\n", pid, i);
          write(1, buf, strlen(buf));
     } 
}

/*

init.h

function for init and deinit

*/


#ifndef _INIT_H_
#define _INIT_H_

#define PLAYGROUND_X 35
#define PLAYGROUND_Y 20
#define LENGTH 5



#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
    #define KEYBOARDHIT kbhit()
    #define GETCHAR getch()
/*#elif defined(__linux__)*/
#endif

void quit(int type);

#endif
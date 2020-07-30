#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MODE_1 "   Start the GAME    "
#define MODE_2 "  Show the RANKING   "
#define MODE_3 "   How to operate    "

char mainMenu(void);

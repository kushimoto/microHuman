#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define N 256
#define MAP_BASE 33
#define RANK_LIMIT 5

extern int rCourseNum;

char** rankingMakeCourseList(char**);
char* rankingDrawMenu(char**);
void rankingGetData(char*, int*);
int rankingSelectCourse(int*, char**); 
void rankingDraw(int*);
void rankingError(void);

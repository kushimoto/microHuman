#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define N 256
#define MAP_BASE 33
#define RANK_LIMIT 5

extern int courseNum;

typedef struct courseData {
	char name[N];
	int map[MAP_BASE][MAP_BASE];
	int rankingData[RANK_LIMIT];
}COURSE_DATA;

void game(void);
char** gameMakeCourseList(char**);
COURSE_DATA* gameSelectCourse(COURSE_DATA*); 
char* gameDrawMenu(char**); 
COURSE_DATA* gameGetData(char*, COURSE_DATA*); 
void gameOperator(COURSE_DATA*);
void gameCursorMovement(COURSE_DATA*, int*, int*, int);
void gameDrawMap(COURSE_DATA*, int, time_t, int);
void gameError(void);
int gameIsGoal(COURSE_DATA*);
int gameRankingManager(time_t, COURSE_DATA*);

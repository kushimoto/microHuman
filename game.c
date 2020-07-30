#include "game.h"

int courseNum = 0;

void game(void) {

	COURSE_DATA courseData;

	for (int i = 0; i < 5; i++)
		courseData.rankingData[i] = 2147483647;

	if (gameSelectCourse(&courseData) == NULL)
		gameError();
	else
		gameOperator(&courseData);

	return ;
}

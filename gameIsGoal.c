#include "game.h"

int gameIsGoal(COURSE_DATA* courseData) {

	if (
			courseData->map[15][15] +
			courseData->map[15][17] +
			courseData->map[17][15] +
			courseData->map[17][17] > 0
	   )
		return 1;

	return 0;
}

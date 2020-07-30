#include "ranking.h"

int rCourseNum = 0;

void rankingShow() {

	char** courseList;
	int rankingData[] = {0, 0, 0, 0, 0};

	if (rankingSelectCourse(rankingData, courseList) == 1) {
		rankingError();
		return ;
	}

	rankingDraw(rankingData);

	return;
}

#include "ranking.h"

int rankingSelectCourse(int *r, char** courseList) {

	char* name;

	courseList = rankingMakeCourseList(courseList);

	if (rCourseNum <= 0)
		return 1;

	name = rankingDrawMenu(courseList);

	if (name != NULL)
		rankingGetData(name, r);

	if (r[0] == 0)
		return 1;

	return 0;
}

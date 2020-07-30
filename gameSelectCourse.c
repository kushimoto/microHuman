#include "game.h"

COURSE_DATA* gameSelectCourse(COURSE_DATA* courseData) {

	/* 存在するコースファイル名の一覧を持つ */
	char** courseList;
	/* コースファイルの名前を格納する */
	char* name;

	/* コースリストを取得 */
	courseList = gameMakeCourseList(courseList);
	/* コース名を取得 */
	name = gameDrawMenu(courseList);

	/* コースリストは用済みのため解放 */
	free(courseList);

	if (name != NULL)
		/* コースデータをセットして返却 */
		return gameGetData(name, courseData);

	return NULL;

}

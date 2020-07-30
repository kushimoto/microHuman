#include "ranking.h"

char** rankingMakeCourseList(char** courseList) {

	/* ファイル名取得用 */
	DIR *dir;
	struct dirent *dp;

	/* コース数カウント用 */
	int cnt = 0;

	/* str系関数の戻り値格納用ポインタ */
	char *c;

	/* ループ用 */
	int i = 0;

	/* カレントディレクトリのファイルリストを取得 */
	if ((dir = opendir(".")) == NULL) {
		perror("opendir");
		return NULL;
	}

	/* ファイル名を順番に読み込む */
	for (dp = readdir(dir); dp != NULL; dp = readdir(dir)) {
		/* コースファイルならカウントアップ */
		c = strstr(dp->d_name, ".mhr");
		if (c != NULL)
			cnt++;
	}

	/* カレントディレクトリのファイルリストを再取得 */
	dir = opendir(".");

	/* コース名リストを格納する配列を動的確保 */
	courseList = (char **)malloc(sizeof(char *) * cnt);
	for (i = 0; i < cnt; i++)
		courseList[i] = malloc(sizeof(char) * N);

	i = 0;

	/* ファイル名を順番に読み込む */
	for (dp = readdir(dir); dp != NULL; dp = readdir(dir)) {
		/* コースファイルならカウントアップ */
		c = strstr(dp->d_name, ".mhr");
		if (c != NULL) {
			/* あらかじめナル文字で埋める */
			memset(courseList[i], '\0', sizeof(char) * N);
			/* コース名のみ抜き取る */
			c = strtok(dp->d_name, ".");
			/* コース名を配列にコピー */
			strcpy(courseList[i], c);
			/* カウントアップ */
			i++;
		}

		/* 全コース名をコピーした時点で抜ける */
		if (i >= cnt)
			break;
	}

	/* コース数をグローバル変数へ代入 */
	rCourseNum = cnt;

	return courseList;
}

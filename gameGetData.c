#include "game.h"

COURSE_DATA* gameGetData(char* name, COURSE_DATA* courseData) {

	FILE *fp;
	char courseFile[N] = "./";
	char rankingFile[N] = "./";

	/* コース名からコースファイル名を作成 */
	strncat(courseFile, name, N - 7);
	strncat(courseFile, ".mhc\0", 5);

	/* 読み込み専用で開く */
	fp = fopen(courseFile, "r");

	/* エラー処理 */
	if (fp == NULL) {
		perror("fopen");
		return NULL;
	}

	/* 先頭1行はファイル名 */
	if (fscanf(fp, "%s\n", courseData->name) == EOF)
		return NULL;

	/* 縦のループ */
	for (int x = 0; x < MAP_BASE; x++) {
		/* 横のループ */
		for (int y = 0; y < MAP_BASE; y++) {
			/* 行の最後だけ改行があるため分岐 */
			if (y < MAP_BASE - 1) {
				if (fscanf(fp, "%d, ", &courseData->map[x][y]) == EOF)
					return NULL;
			} else {
				if (fscanf(fp, "%d\n", &courseData->map[x][y]) == EOF)
					return NULL;
			}

		}
	}


	/* コース名からランキングファイル名を作成 */
	strncat(rankingFile, name, N - 7);
	strncat(rankingFile, ".mhr\0", 4);

	/* 読み込み専用で開く */
	fp = fopen(rankingFile, "r");

	/* エラー処理 */
	if (fp == NULL) {
		perror("fopen");
		return courseData;
	}
	/* ランキングデータ取得用ループ */
	for (int i = 0; i < RANK_LIMIT; i++) {
		if (fscanf(fp, "%d\n", &courseData->rankingData[i]) == EOF)
			break;
	}

	fclose(fp);

	return courseData;
}

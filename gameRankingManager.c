#include "game.h"

int gameRankingManager(time_t t, COURSE_DATA* courseData) {

	FILE *fp;
	char rankingFile[N] = "./";
	int rank = 1;

	for (int i = 0; i < RANK_LIMIT; i++) {

		if (courseData->rankingData[i] > t) {

			if ( ( i > 0) && (t != courseData->rankingData[i - 1]) )
				rank = i + 1;

			if (courseData->rankingData[i] == 2147483647) {
				courseData->rankingData[i] = t;
				break;
			}

			for (int j = 3; j >= i; j--)
				courseData->rankingData[j + 1] = courseData->rankingData[j];

			courseData->rankingData[i] = t;

			break;

		} else if ( ( i > 0) && (courseData->rankingData[i] != courseData->rankingData[i - 1]) )
			rank = i + 1;
 

		if (i >= ( RANK_LIMIT - 1) )
			rank++;
	}

	/* コース名からコースファイル名を作成 */
	strncat(rankingFile, courseData->name, N - 7);
	strncat(rankingFile, ".mhr\0", 5);

	/* 書込み専用で開く */
	fp = fopen(rankingFile, "w");

	/* エラー処理 */
	if (fp == NULL) {
		gameError();
	}

	for (int i = 0; i < RANK_LIMIT; i++) {
		if (courseData->rankingData[i] < 2147483647)
			fprintf(fp, "%d\n", courseData->rankingData[i]);
	}

	fclose(fp);

	return rank;

}

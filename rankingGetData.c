#include "ranking.h"

void rankingGetData(char* name, int* r) {

	FILE *fp;
	char rankingFile[N] = "./";

	/* コース名からランキングファイル名を作成 */
	strncat(rankingFile, name, N - 7);
	strncat(rankingFile, ".mhr\0", 4);

	/* 読み込み専用で開く */
	fp = fopen(rankingFile, "r");

	/* エラー処理 */
	if (fp == NULL) {
		perror("fopen");
		return ;
	}
	/* ランキングデータ取得用ループ */
	for (int i = 0; i < RANK_LIMIT; i++) {
		if (fscanf(fp, "%d\n", &r[i]) == EOF)
			break;
	}

	fclose(fp);

	return ;
}

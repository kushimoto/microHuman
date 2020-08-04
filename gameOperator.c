#include "game.h"

void gameOperator(COURSE_DATA* courseData) {

	/* 入力用 */
	int ch;

	int pY = 1;
	int pX = 1;

	/* drawMenu()モード用 */
	int mode = 1;

	/* 順位 */
	int rank = 0;

	/* 開始時間(エポックタイム) */
	time_t st;
	time_t result;

	/* 初期位置セット */
	gameCursorMovement(courseData, &pY, &pX, 0);

	clear();

	/* 描画 */
	gameDrawMap(courseData, mode, 0, 0);

	while (1) {
		switch (ch = getch()) {
			case 'j':
				gameCursorMovement(courseData, &pY, &pX, ch);
				break;
			case 'k':
				gameCursorMovement(courseData, &pY, &pX, ch);
				break;
			case 'l':
				gameCursorMovement(courseData, &pY, &pX, ch);
				break;
			case 'h':
				gameCursorMovement(courseData, &pY, &pX, ch);
				break;
			case '\n':
				/* 位置をリセット */
				gameCursorMovement(courseData, &pY, &pX, ch);

				/* 開始時刻設定 */
				if (mode == 1)
					st = time(NULL);

				/* モードをタイムアタックに変更 */
				mode = 2;

				clear();

				break;
			case 'q':
				return ;
			default:
				clear();
				break;
				
		}

		/* ゴールの確認 */
		if (mode == 2 && gameIsGoal(courseData))
			break;

		/* 描画 */
		gameDrawMap(courseData, mode, 0, 0);
	}

	/* モードを終了に変更 */
	mode = 3;

	clear();

	/* タイムを計算する */
	result = time(NULL) - st;

	rank = gameRankingManager(result, courseData);

	/* タイムとコースをを描画 */
	while (ch != 'q' && ch != '\n') {
		gameDrawMap(courseData, mode, result, rank);
		ch = getch();
	}
}

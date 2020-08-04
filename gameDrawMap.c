#include "game.h"

void gameDrawMap(COURSE_DATA* courseData, int mode, time_t t, int rank) {

	/* X座標、Y座標 */
	int pointX, pointY;

	/* 変化前の画面サイズを格納 */
	int beforeWidth, beforeHeight;

	/* 変化後の画面サイズを格納 */ 
	int afterWidth, afterHeight;

	/* メインメニュー横幅 */
	int menuMaxWidth; 
	/* メインメニュー縦幅 */
	int menuMaxHeight = 43;

	/* 画面サイズ取得 */
	getmaxyx(stdscr, beforeHeight, beforeWidth);

	/* キー入力用 */
	int ch;

	/* 画面更新 */
	refresh();		

	/* カーソルを表示しない */
	curs_set(0);

	if (mode == 1)
		menuMaxWidth = 31;
	else if (mode == 2)
		menuMaxWidth = 24;
	else if (mode == 3)
		menuMaxWidth = 35;

	/* X座標設定 */
	pointX = (beforeWidth - menuMaxWidth) / 2;
	/* Y座標設定 */
	pointY = (beforeHeight - menuMaxHeight) / 2;

	if (mode == 1) { 
		mvprintw(pointY++, pointX, "It's now maze exploration time.");
		pointY++;
		mvprintw(pointY++, pointX, " Press Enter when you are done.");
	} else if (mode == 2) {
		mvprintw(pointY++, pointX, "Time attack in progress.");
		pointY++;
		mvprintw(pointY++, pointX, "  Let's go to the goal. ");
	} else if (mode == 3) {
		mvprintw(pointY++, pointX, "              Finish !             ");
		pointY++;
		mvprintw(pointY++, pointX, "Press Enter to return to the title.");
	}

	/* 縦の感覚をとる */
	pointY += 5;

	/* X座標設定 */
	menuMaxWidth = 65;
	pointX = (beforeWidth - menuMaxWidth) / 2;

	for (int i = 0; i < MAP_BASE; i++) {
		for (int j = 0; j < MAP_BASE; j++) {

			if ((courseData->map[i][j] > 4) && (j % 2 == 1)) {
				mvprintw(pointY, pointX, " p ");
				pointX += 3;
				continue;
			} else if ((courseData->map[i][j] > 4) && (j % 2 == 0)) {
				mvprintw(pointY, pointX++, "p");
				continue;
			} else if ((courseData->map[i][j] < 0) && (j % 2 == 1)) {
				mvprintw(pointY, pointX, " m ");
				pointX += 3;
				continue;
			} else if ((courseData->map[i][j] < 0) && (j % 2 == 0)) {
				mvprintw(pointY, pointX++, "m");
				continue;
			} 


			if (courseData->map[i][j] == 4) {
				/* 描画 */
				mvprintw(pointY, pointX++, "+");
			} else if (courseData->map[i][j] == 3) {
				/* 描画 */
				mvprintw(pointY, pointX, "---");
				pointX += 3;
			} else if (courseData->map[i][j] == 2) {
				/* 描画 */
				mvprintw(pointY, pointX++, "|");
			} else if ((courseData->map[i][j] == 1) && (j % 2 == 1)) {
				/* 描画 */
				mvprintw(pointY, pointX, " o ");
				pointX += 3;
			} else if ((courseData->map[i][j] == 0) && (j % 2 == 1)) {
				/* 描画 */
				mvprintw(pointY, pointX, "   ");
				pointX += 3;
			} else if ((courseData->map[i][j] == 0) && (j % 2 == 0)) {
				/* 描画 */
				mvprintw(pointY, pointX, " ");
				pointX++;
			}

		}
		/* X座標設定 */
		pointX = (beforeWidth - menuMaxWidth) / 2;
		pointY++;
		/* 画面更新 */
		refresh();		
	}

	/* 縦の感覚をとる */
	pointY += 3;

	if (mode == 3) {
		menuMaxWidth = 30;
		/* X座標設定 */
		pointX = (beforeWidth - menuMaxWidth) / 2;
		mvprintw(pointY++, pointX, "     Time : %ld s    Rank : %d     ", t, rank);
	}

	/* 負荷軽減 */
	sleep(0.001);

	/* 画面更新 */
	refresh();		

	/* 画面サイズ取得 */
	getmaxyx(stdscr, afterHeight, afterWidth);

	/* 横幅が変化したとき */
	if (afterWidth != beforeWidth) {
		/* 横幅更新 */
		beforeWidth = afterWidth;
		/* 画面消去 */
		clear();
	}

	/* 縦幅が変化したとき */
	if (afterHeight != beforeHeight) {
		/* 縦幅更新 */
		beforeHeight = afterHeight;
		/* 画面消去 */
		clear();
	}

	return;

}

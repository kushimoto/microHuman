#include "game.h"

void gameError(void) {

	/* X座標、Y座標 */
	int pointX, pointY;

	/* 画面サイズ */
	int width, height;

	/* 画面サイズ取得 */
	getmaxyx(stdscr, height, width);

	/* 画面消去 */
	clear();

	/* カーソルを表示しない */
	curs_set(0);

	/* X座標設定 */
	pointX = (width - 28) / 2;
	/* Y座標設定 */
	pointY = (height - 7) / 2;
	mvprintw(pointY++, pointX, "Course selecting was failed.");

	/* X座標設定 */
	pointX = (width - 48) / 2;
	mvprintw(pointY++, pointX, "The error may have been caused by the following.");
	pointY += 2;

	/* X座標設定 */
	pointX = (width - 35) / 2;
	mvprintw(pointY++, pointX, "> Cancellation of Course Selection.");
	mvprintw(pointY++, pointX, "> The course file does not exist.");
	mvprintw(pointY++, pointX, "> The course file is corrupted.");

	/* 画面更新 */
	refresh();		

	getch();

	return ;

}

#include "ranking.h"

void rankingError(void) {

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
	pointX = (width - 22) / 2;
	/* Y座標設定 */
	pointY = (height - 6) / 2;
	/* エラー */
	mvprintw(pointY++, pointX, "An error has occurred.");
	/* X座標設定 */
	pointX = (width - 48) / 2;
	/* エラー */
	mvprintw(pointY++, pointX, "The error may have been caused by the following.");

	pointY += 2;

	/* X座標設定 */
	pointX = (width - 42) / 2;
	/* エラー */
	mvprintw(pointY++, pointX, "> The ranking file does not exist.");
	/* エラー */
	mvprintw(pointY++, pointX, "> The ranking file is empty.");
	/* エラー */
	mvprintw(pointY++, pointX, "> The file is corrupt.");

	/* 画面更新 */
	refresh();		

	getch();

	return ;

}

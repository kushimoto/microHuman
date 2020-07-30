#include <ncurses.h>

void usage(void) {

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
	pointX = (width - 16) / 2;
	/* Y座標設定 */
	pointY = (height - 6) / 2;
	/* メッセージ */
	mvprintw(pointY, pointX, "How to Operate ?");

	pointY += 2;

	/* メッセージ */
	mvprintw(pointY++, pointX, "h :     left    ");
	/* メッセージ */
	mvprintw(pointY++, pointX, "j :     down    ");
	/* メッセージ */
	mvprintw(pointY++, pointX, "k :      up     ");
	/* メッセージ */
	mvprintw(pointY++, pointX, "l :    right    ");

	/* 画面更新 */
	refresh();		

	getch();

	return ;

}

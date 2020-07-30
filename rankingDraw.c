#include "ranking.h"

void rankingDraw(int *r) {
	
	/* X座標、Y座標 */
	int pointX, pointY;

	int height, width;

	int i;

	int rankNum = 1;

	/* 画面サイズ取得 */
	getmaxyx(stdscr, height, width);

	/* 画面消去 */
	clear();

	/* カーソルを表示しない */
	curs_set(0);

	for (i = 0; i < RANK_LIMIT; i++)
		if (r[i] == 0)
			break;

	/* X座標設定 */
	pointX = (width - 9) / 2;
	/* Y座標設定 */
	pointY = (height - (2 + i)) / 2;
	mvprintw(pointY, pointX, "RANK TIME");
	pointY += 2;

	for (int j = 0; j < i; j++)
		if ( ( j < (i - 1) ) && (r[j] == r[j + 1]) )
			mvprintw(pointY++, pointX, " %d.   %ds", rankNum, r[j]);
		else
			mvprintw(pointY++, pointX, " %d.   %ds", rankNum++, r[j]);

	/* 画面更新 */
	refresh();		
	
	getch();

	return ;
}

#include "mainMenu.h"

char mainMenu(void) {

	/* X座標、Y座標 */
	int pointX, pointY;

	/* 変化前の画面サイズを格納 */
	int beforeWidth, beforeHeight;

	/* 変化後の画面サイズを格納 */ 
	int afterWidth, afterHeight;

	/* メインメニュー横幅 */
	int menuMaxWidth = 21;
	/* メインメニュー縦幅 */
	int menuMaxHeight = 23;

	/* 画面サイズ取得 */
	getmaxyx(stdscr, beforeHeight, beforeWidth);

	/* キー入力用 */
	int ch;

	/* カーソルキーを利用 */
	keypad(stdscr, TRUE);

	/* 選択モード記録用 */
	char modeFlag = '0';

	/* 文字色使用開始 */
	start_color();

	/* 色の定義 */
	init_pair(1, COLOR_BLACK, COLOR_WHITE);

	while (1) {

		/* カーソルを表示しない */
		curs_set(0);

		/* X座標設定 */
		pointX = (beforeWidth - menuMaxWidth) / 2;
		/* Y座標設定 */
		pointY = (beforeHeight - menuMaxHeight) / 2;

		/* メインメニュー出力群 */
		mvprintw(pointY++, pointX, "  -   -   -   -   -");
		mvprintw(pointY++, pointX, " / \\ / \\ / \\ / \\ / \\");
		mvprintw(pointY++, pointX, "( M | i | c | r | o )");
		mvprintw(pointY++, pointX, " \\_/ \\_/ \\_/ \\_/ \\_/");

		/* 縦の感覚をとる */
		pointY += 3;

		mvprintw(pointY++, pointX, "  -   -   -   -   -");
		mvprintw(pointY++, pointX, " / \\ / \\ / \\ / \\ / \\");
		mvprintw(pointY++, pointX, "( H | u | m | a | n )");
		mvprintw(pointY++, pointX, " \\_/ \\_/ \\_/ \\_/ \\_/");

		/* 縦の感覚をとる */
		pointY += 5;

		switch (modeFlag) {
			case '1':
				attrset(COLOR_PAIR(1));
				mvprintw(pointY++, pointX, MODE_1);
				attrset(COLOR_PAIR(1) | A_REVERSE);
				mvprintw(pointY++, pointX, MODE_2);
				mvprintw(pointY++, pointX, MODE_3);
				break;

			case '2':
				mvprintw(pointY++, pointX, MODE_1);
				attrset(COLOR_PAIR(1));
				mvprintw(pointY++, pointX, MODE_2);
				attrset(COLOR_PAIR(1) | A_REVERSE);
				mvprintw(pointY++, pointX, MODE_3);
				break;

			case '3':
				mvprintw(pointY++, pointX, MODE_1);
				mvprintw(pointY++, pointX, MODE_2);
				attrset(COLOR_PAIR(1));
				mvprintw(pointY++, pointX, MODE_3);
				attrset(COLOR_PAIR(1) | A_REVERSE);
				break;

			default:
				mvprintw(pointY++, pointX, MODE_1);
				mvprintw(pointY++, pointX, MODE_2);
				mvprintw(pointY++, pointX, MODE_3);
		}

		/* 縦の感覚をとる */
		pointY += 3;

		mvprintw(pointY++, pointX, "Please select a mode.");

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

		switch (ch = getch()) {
			case 'j':
			case KEY_DOWN:
				modeFlag += 1;
				break;

			case 'k':
			case KEY_UP:
				modeFlag -= 1;
				break;

			case '\n':
				if (modeFlag == 0)
					continue;
				goto ENTER;

			case 'q':
				modeFlag = 'q';
				goto ENTER;

		}
		if (modeFlag < '1') {
			modeFlag = '1';
		} else if (modeFlag > '3') {
			modeFlag = '3';
		}

	}

ENTER:

	return modeFlag;
}

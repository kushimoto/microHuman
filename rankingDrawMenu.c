#include "ranking.h"

char* rankingDrawMenu(char** name) {

	/* X座標、Y座標 */
	int pointX, pointY;

	/* 変化前の画面サイズを格納 */
	int beforeWidth, beforeHeight;

	/* 変化後の画面サイズを格納 */ 
	int afterWidth, afterHeight;

	/* メインメニュー横幅 */
	int menuMaxWidth = 23;
	/* メインメニュー縦幅 */
	int menuMaxHeight = 10;

	/* 画面サイズ取得 */
	getmaxyx(stdscr, beforeHeight, beforeWidth);

	/* キー入力用 */
	int ch;

	/* カーソルキーを利用 */
	keypad(stdscr, TRUE);

	char selectedNumber = '0';

	/* ファイル名文字数　*/
	int cnt = 0;

	/* 文字色使用開始 */
	start_color();

	/* 色の定義 */
	init_pair(1, COLOR_BLACK, COLOR_WHITE);

	/* 画面消去 */
	clear();

	while (1) {

		/* カーソルを表示しない */
		curs_set(0);

		/* X座標設定 */
		pointX = (beforeWidth - menuMaxWidth) / 2;
		/* Y座標設定 */
		pointY = (beforeHeight - menuMaxHeight) / 2;

		mvprintw(pointY++, pointX, "Please select a course.");

		/* 縦の感覚をとる */
		pointY += 5;

		for (int i = 0; i <= rCourseNum; i++) {

			/* 表示の都合上iを一つずらす */
			if (i == 0)
				continue;

			for (int j = 0; name[i - 1][j] != '\0'; j++)
				cnt++;

			/* 選択中の番号と一致した場合色を設定 */
			if (('0' + i) == selectedNumber)
				attrset(COLOR_PAIR(1));

			/* X座標設定 */
			pointX = (beforeWidth - cnt) / 2;
			/* 描画 */
			mvprintw(pointY++, pointX, name[i - 1]);
			/* 文字の長さリセット */
			cnt = 0;

			/* 選択中の番号と一致した場合色を反転 */
			if (('0' + i) == selectedNumber)
				attrset(COLOR_PAIR(1) | A_REVERSE);
		}

		/* 縦の感覚をとる */
		pointY += 3;

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
				selectedNumber += 1;
				break;

			case 'k':
			case KEY_UP:
				selectedNumber -= 1;
				break;

			case '\n':
				goto ENTER;

			case 'q':
				return NULL;

		}

		if (selectedNumber < '1') {
			selectedNumber = '1';
		} else if (selectedNumber > ('0' + rCourseNum)) {
			selectedNumber = ('0' + rCourseNum);
		}

	}

ENTER:

	return name[(selectedNumber - '0') - 1];
}

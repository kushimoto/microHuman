#include <ncurses.h>
#include <stdlib.h>
#include "microHuman.h"

int main(void) {

	/* 初期化 */
	initscr();
	/* 文字をバッファーにためない */
	crmode();
	/* 入力文字を出力しない */
	noecho();

	while (1) {

		clear();
		refresh();

		switch (mainMenu()) {
			case '1':
				game();
				break;

			case '2':
				rankingShow();
				break;

			case '3':
				usage();
				break;

			case 'q':
				goto END;
				break;
		}
	}

END:

	/* 終了 */
	endwin();

	exit(EXIT_SUCCESS);
}

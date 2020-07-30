#include "game.h"

void gameCursorMovement(COURSE_DATA* courseData, int* pY, int* pX, int num) {

	/* 初期位置セット */
	courseData->map[*pY][*pX] = 1;

	switch (num) {
		case 'j':
			if ( (courseData->map[*pY + 1][*pX] < 1) && (*pY + 2 < MAP_BASE) ) {
				courseData->map[*pY][*pX] = 0;
				*pY += 2;
				courseData->map[*pY][*pX] = 1;
			}
			break;
		case 'k':
			if ( (courseData->map[*pY - 1][*pX] < 1) && (*pY - 2 > 0) ) {
				courseData->map[*pY][*pX] = 0;
				*pY -= 2;
				courseData->map[*pY][*pX] = 1;
			}
			break;
		case 'l':
			if ( (courseData->map[*pY][*pX + 1] < 1) && (*pX + 2 < MAP_BASE) ) {
				courseData->map[*pY][*pX] = 0;
				*pX += 2;
				courseData->map[*pY][*pX] = 1;
			}
			break;
		case 'h':
			if ( (courseData->map[*pY][*pX - 1] < 1) && (*pX - 2 > 0) ) {
				courseData->map[*pY][*pX] = 0;
				*pX -= 2;
				courseData->map[*pY][*pX] = 1;
			}
			break;
		case '\n':
			/* 位置をリセット */
			courseData->map[*pY][*pX] = 0;
			*pY = 1;
			*pX = 1;
			courseData->map[*pY][*pX] = 1;

			break;

		default:
			break;
	}
	return ;
}

# makefile of microHuman
gameObjects = game.o gameCursorMovement.o gameDrawMap.o gameDrawMenu.o gameError.o gameGetData.o gameIsGoal.o gameMakeCourseList.o gameOperator.o gameRankingManager.o gameSelectCourse.o
rankingObjects = rankingShow.o rankingSelectCourse.o rankingMakeCourseList.o rankingDrawMenu.o rankingGetData.o rankingDraw.o rankingError.o
microHuman: main.o mainMenu.o usage.o $(gameObjects) $(rankingObjects)
	gcc -o microHuman main.o mainMenu.o usage.o $(gameObjects) $(rankingObjects) -lncurses
.c.o:
	gcc -c $<
# main module 
main.o: main.c
# main menu module
mainMenu.o: mainMenu.c
# game module
game.o: game.c
gameCursorMovement.o: gameCursorMovement.c
gameDrawMap.o: gameDrawMap.c
gameDrawMenu.o: gameDrawMenu.c
gameError.o: gameError.c
gameGetData.o: gameGetData.c
gameIsGoal.o: gameIsGoal.c
gameMakeCourseList.o: gameMakeCourseList.c
gameOperator.o: gameOperator.c
gameRankingManager.o: gameRankingManager.c
gameSelectCourse.o: gameSelectCourse.c
# ranking module
rankingShow.o: rankingShow.c
rankingSelectCourse.o: rankingSelectCourse.c 
rankingMakeCourseList.o: rankingMakeCourseList.c
rankingDrawMenu.o: rankingDrawMenu.c
rankingGetData.o: rankingGetData.c
rankingDraw.o: rankingDraw.c
rankingError.o: rankingError.c
# usage
usage.o: usage.c

clean:
	rm *.o
	rm *.mhr

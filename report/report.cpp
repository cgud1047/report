//計算ゲーム

#include <windows.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#define BUFFSIZE 1024

int main(void) {


	int key; //キー
	int num = 1; //問題番号numを1に設定
	double cnt=0; //正答数
	double correct;//正答率

	// 初期化
	if (initscr() == NULL) {
		return 1;
	}

	mvaddstr(5, 15, "-----Calculation Game-----");
	mvaddstr(7, 15, "START Enter BUTTON...");

	while (1) {

		key = getch();


		switch (num) {
			/* 問題番号1のとき */
		case 1:
			erase();

			/* 問題の表示 */
			mvaddstr(8, 10, "11 + 32 = ? ");

			mvaddstr(10, 15, "A : 43");
			mvaddstr(12, 15, "B : 42");
			mvaddstr(14, 15, "R : 47");
			mvaddstr(16, 15, "L : 45");

			/* 正誤判定 */
			if (key == 'a') { //正解のとき
				mvaddstr(13, 30, "Correct!!");
				mvaddstr(15, 30, "Next Enter");

				cnt++;
				num = 2; //問題2へ進む
			}
			else if (key == 'b' || key == 'l' || key == 'r') {
				mvaddstr(13, 30, "Wrong!!");
				mvaddstr(15, 30, "Next Enter");

				num = 2; //問題2へ進む
			}


			break;

			/* 問題番号2のとき */
		case 2:
			erase();

			/* 問題の表示 */
			mvaddstr(8, 10, "76 - 49 = ?");

			mvaddstr(10, 15, "A : 27");
			mvaddstr(12, 15, "B : 28");
			mvaddstr(14, 15, "R : 24");
			mvaddstr(16, 15, "L : 25");

			/* 正誤判定 */
			if (key == 'a') { //正解のとき
				mvaddstr(13, 30, "Correct!!");
				mvaddstr(15, 30, "Next Enter");

				cnt++;
				num = 3; //問題3へ進む
			}
			else if (key == 'b' || key == 'l' || key == 'r') {
				mvaddstr(13, 30, "Wrong!!");
				mvaddstr(15, 30, "Next Enter");

				num = 3; //問題3へ進む
			}

			break;

			/* 問題番号3のとき */
		case 3:
			erase();

			/* 問題の表示 */
			mvaddstr(8, 10, "54 - 19 = ?");

			mvaddstr(10, 15, "A : 35");
			mvaddstr(12, 15, "B : 37");
			mvaddstr(14, 15, "R : 38");
			mvaddstr(16, 15, "L : 39");

			/* 正誤判定 */
			if (key == 'a') { //正解のとき
				mvaddstr(13, 30, "Correct!!");
				mvaddstr(15, 30, "Next Enter");

				cnt++;
				num = 4; //問題4へ進む
			}
			else if (key == 'b' || key == 'l' || key == 'r') {
				mvaddstr(13, 30, "Wrong!!");
				mvaddstr(15, 30, "Next Enter");

				num = 4; //問題4へ進む
			}


			break;

			/* 問題番号4のとき */
		case 4:
			erase();

			/* 問題の表示 */
			mvaddstr(8, 10, "19 + 74 = ?");

			mvaddstr(10, 15, "A : 93");
			mvaddstr(12, 15, "B : 83");
			mvaddstr(14, 15, "R : 96");
			mvaddstr(16, 15, "L : 94");

			/* 正誤判定 */
			if (key == 'a') { //正解のとき
				/* 緑の丸を表示し、その真ん中にNICE！と表示 */

				mvaddstr(13, 30, "Correct!!");
				mvaddstr(15, 30, "Next Enter");

				cnt++;
				num = 5; //問題5へ進む
			}
			else if (key == 'b' || key == 'l' || key == 'r') {
				mvaddstr(13, 30, "Wrong!!");
				mvaddstr(15, 30, "Next Enter");

				num = 5; //問題5へ進む
			}


			break;

			/* 問題番号5のとき */
		case 5:
			erase();

			/* 問題の表示 */
			mvaddstr(8, 10, "45 - 22 = ?");

			mvaddstr(10, 15, "A : 23");
			mvaddstr(12, 15, "B : 22");
			mvaddstr(14, 15, "R : 21");
			mvaddstr(16, 15, "L : 25");

			/* 正誤判定 */
			if (key == 'a') { //正解のとき
				mvaddstr(13, 30, "Correct!!");
				mvaddstr(15, 30, "Next Enter");

				cnt++;
				num = 6; //終了
			}
			else if (key == 'b' || key == 'l' || key == 'r') {
				mvaddstr(13, 30, "Wrong!!");
				mvaddstr(15, 30, "Next Enter");

				num = 6; //終了
			}

			break;

		case 6:

			erase();
			mvaddstr(8, 10, "Finish!!");
			mvaddstr(10, 10, "Check your Score by Enter!!");

			num = 10;

			break;

		default:
			erase();

			correct = cnt/5*100;
			mvprintw(10, 10, "%s", "Your Score is...");
			mvprintw(10, 26, "%f", correct);
			mvprintw(10, 35, "%s", "%");

			//成績出力
			FILE* fp;
			char s[BUFFSIZE];
			errno_t error;

			error = fopen_s(&fp, "output.txt", "w");
			if (error != 0)
				fprintf_s(stderr, "failed to open");
			else {
				fprintf_s(fp, "%s", "Your Score is...");
				fprintf_s(fp, "%f", correct);
				fprintf_s(fp, "%s", "%");
				fclose(fp);
			}

			break;
		}

	}


	endwin();
	return 0;

}







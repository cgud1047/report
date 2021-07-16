//計算ゲーム

#include <windows.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "gba1.h"

int main(void) {


    int key;
	int num = 1; //問題番号numを1に設定
	int cnt=0;//正解回数

	// 初期化
	if (initscr() == NULL) {
		return 1;
	}

    mvaddstr(5, 15, "-----Calculation Game-----");
	

	while (1) {


		key=getch();

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
			if (key == KEY_A) { //正解のとき
				mvaddstr(13, 30, "Correct!!");

				cnt++;
				num = 2; //問題2へ進む
			}else{
				mvaddstr(13, 30, "Wrong!!");

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
			if (key == KEY_A) { //正解のとき
				mvaddstr(13, 30, "Correct!!");

				cnt++;
				num = 3; //問題3へ進む
			}
			else {
				mvaddstr(13, 30, "Wrong!!");

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
			if (key == KEY_A) { //正解のとき
				mvaddstr(13, 30, "Correct!!");

				cnt++;
				num = 4; //問題4へ進む
			}
			else {
				mvaddstr(13, 30, "Wrong!!");

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
			if (key == KEY_A) { //正解のとき
				/* 緑の丸を表示し、その真ん中にNICE！と表示 */
				
				mvaddstr(13, 30, "Correct!!");

				cnt++;
				num = 5; //問題5へ進む
			}
			else {
				mvaddstr(13, 30, "Wrong!!");

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
			if (key == KEY_A) { //正解のとき
				mvaddstr(13, 30, "Correct!!");

				cnt++;
				num = 6; //終了
			}
			else {
				mvaddstr(13, 30, "Wrong!!");

				num = 6; //終了
			}

			break;

		default:

			erase();
			mvaddstr(8, 10, "Finish!!");
			break;
		}

	}

	endwin();
	return 0;

}



	



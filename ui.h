#ifndef UI_H
#define UI_H

/*
*ui.h
*暗記フラッシュカードの画面表示および、入力受付を作ります。
*ここでは、データの保存やカードの管理の処理はしないので注意
*/

/*タイトル画面の表示*/
void show_title(void);

/*メインメニューの表示*/
void show_main_menu(void);
/*
メインメニューの構想は、
1.暗記フラッシュカード開始
2.暗記カードを追加
3.暗記カード一覧
4.終了
メインメニューで番号を入力してもらう
*/

int input_menu_choice(void);

/*問題文の表示*/
void show_question(const char question[]);

/*答えを表示*/
void show_answer(const char answer[]);

/*メッセージを表示*/
void show_message(const char message[]);

/*Enterキーが押されるまで待つ*/
void wait_enter(void);

#endif
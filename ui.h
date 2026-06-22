#ifndef UI_H
#define UI_H

/*
*ui.h

*/

/*タイトル画面表示*/
void show_title(void);

/*メインメニュー表示*/
void show_main_menu(void);

/*番号を選択*/
int input_menu_choice(void);

/*問題文表示*/
void show_question(const char question[]);

/*答えを表示*/
void show_answer(const char answer[]);

/*ユーザーが回答を入力*/
void input_answer(char answer[], int size);

void show_result(int is_correct);

/*メッセージを表示*/
void show_message(const char message[]);

/*エンターが押されるまで待つ*/
void wait_enter(void);

#endif
#include <stdio.h>
#include <string.h>
#include "ui.h"

/*
*仮main.c
*暗記フラッシュカードの全体の流れを作ります
*UIの表示や入力の受け付けはui.cの仕事なのでここではしない
*カード管理や保存処理は、ほかの関数と接続する
*/

int check_answer_temp(const char user_answer[], const char correct_answer[]){
    if(strcmp(user_answer, correct_answer) == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    char user_answer[100];
    int is_correct;

    int choice;
    int is_running = 1;

    show_title();

    while(is_running){
        show_main_menu();
        choice = input_menu_choice();

        switch(choice){
            case 1:
            /*本当はここでロジック担当の「暗記フラッシュカード開始処理」を呼び出す。*/
            show_message("暗記を開始します。");
            show_question("日本の首都は？");
            input_answer(user_answer, sizeof(user_answer));
            is_correct = check_answer_temp(user_answer, "東京");/*この部分はロジック担当の関数を入れる。*/
            show_result(is_correct);
            if(!is_correct){
                show_answer("東京");
            }
            wait_enter();

            break;

            case 2:
            /*ここでは、暗記カードの追加と接続します。*/
            show_message("暗記カード追加は未実装です。");
            wait_enter();
            break;

            case 3:
            /*ここでは、暗記カード一覧を表示する関数と接続します。*/
            show_message("カード一覧昨日は未実装です。");
            wait_enter();
            break;

            case 4:
            show_message("終了します。");
            is_running = 0;
            break;

            default:
            show_message("不正な入力です。");
            break;
        }
    }

    return 0;
}
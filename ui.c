#include <stdio.h>
#include <string.h>
#include "ui.h"

/*
*ui.c
*暗記フラッシュカードのUI処理をまとめています
*printfで画面表示と、scanf/getcharによる入力受付をします。
*/

/*タイトルを表示*/
void show_title(void){

    printf("=======================================\n");
    printf("           暗記フラッシュカード          \n");
    printf("=======================================\n");

}

/*メインメニューの表示*/
void show_main_menu(void){
    printf("\n");
    printf("===== メインメニュー =====\n");
    printf("1. 暗記フラッシュカード開始\n");
    printf("2. 暗記カードを追加\n");
    printf("3. 暗記カード一覧\n");
    printf("4. 終了する\n");
    printf("番号を入力してください: ");
}

/*入力された数字が有効か否かを判定*/
int input_menu_choice(void){
    int choice;

    while(1){
        if(scanf("%d", &choice) == 1){
            while(getchar() != '\n');
            if(choice >= 1 && choice <=4){
                return choice;
            }
        }else{
            while(getchar() != '\n');
        }
        printf("1から4の番号を入力してください: ");
    }
}


/*問題文を表示*/
void show_question(const char question[]){
    printf("\n");
    printf("===== 問題 =====\n");
    printf("%s\n",question);
}


/*答えを表示*/
void show_answer(const char answer[]){
    printf("\n");
    printf("===== 答え =====\n");
    printf("%s\n", answer);
}

/*メッセージを表示*/
void show_message(const char message[]){
    printf("%s\n", message);
}

/*Enterキーが押されるまで待機*/
void wait_enter(void){
    printf("\nEnterキーを押してください…");
    getchar();
}

void input_answer(char answer[], int size){
    printf("答えを入力: ");
    fgets(answer, size, stdin);

    answer[strcspn(answer, "\n")] = '\0';
}

void show_result(int is_correct){
    if(is_correct){
        printf("正解！\n");
    }else{
        printf("不正解…\n");
    }
}
#include <stdio.h>
#include "ui.h"

int showMainMenu() {

    int choice;

    printf("\n====================\n");
    printf("  暗記学習アプリ\n");
    printf("====================\n");
    printf("1. 学習する\n");
    printf("2. 問題を追加する\n");
    printf("3. 問題一覧を見る\n");
    printf("4. 終了\n");
    printf("選択 : ");

    scanf("%d", &choice);
    getchar();

    return choice;
}

int selectSubject() {

    int subject;

    printf("\n科目選択\n");
    printf("1. 英単語\n");
    printf("2. 社会\n");
    printf("選択 : ");

    scanf("%d", &subject);
    getchar();

    return subject;
}

void showResult(int score, int count) {

    printf("\n===== 結果 =====\n");

    printf("%d / %d 正解\n",
           score,
           count);

    printf("正答率 %.1f%%\n",
           (double)score / count * 100);
}
#include <stdio.h>
 
int selectSubject() {
    int subject;
    printf("=== 科目選択 ===\n");
    printf("1. 英単語\n");
    printf("2. 社会\n");
    printf("選択: ");
    scanf("%d", &subject);
    getchar();
    return subject;
}
 
void showRegisterMode() {
    printf("\n=== 登録モード ===\n");
    printf("終了するには end と入力\n\n");
}
 
void showStudyMode() {
    printf("\n=== 学習モード ===\n");
}
 
void showResult(int score, int count) {
    printf("\n=== 結果 ===\n");
    printf("%d問中%d問正解！\n", count, score);
 
    if (count > 0) {
        double rate = (double)score / count * 100;
        printf("正答率 %.1f%%\n", rate);
 
        if (score == count) {
            printf("満点！すごい！\n");
        } else if (rate >= 80) {
            printf("よくできました！\n");
        } else if (rate >= 50) {
            printf("もう少し！\n");
        } else {
            printf("復習しよう！\n");
        }
    }
 
    printf("\n学習終了！\n");
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

int main() {
    char question[MAX_WORDS][MAX_LENGTH];
    char answer[MAX_WORDS][MAX_LENGTH];
    char userAnswer[MAX_LENGTH];

    int count = 0;
    int score = 0;
    int subject;

    srand(time(NULL));

    printf("=== 科目選択 ===\n");
    printf("1. 英単語\n");
    printf("2. 社会\n");
    printf("選択: ");
    scanf("%d", &subject);
    getchar();

    printf("\n=== 登録モード ===\n");
    printf("終了するには end と入力\n\n");

    while (count < MAX_WORDS) {

        if (subject == 1) {
            printf("日本語: ");
        } else {
            printf("問題: ");
        }

        fgets(question[count], MAX_LENGTH, stdin);
        question[count][strcspn(question[count], "\n")] = '\0';

        if (strcmp(question[count], "end") == 0) {
            break;
        }

        if (subject == 1) {
            printf("英語: ");
        } else {
            printf("答え: ");
        }

        fgets(answer[count], MAX_LENGTH, stdin);
        answer[count][strcspn(answer[count], "\n")] = '\0';

        count++;
        printf("\n");
    }

    // 問題のランダムシャッフル 
    for (int i = 0; i < count; i++) {
        int r = rand() % count;

        char temp[MAX_LENGTH];

        strcpy(temp, question[i]);
        strcpy(question[i], question[r]);
        strcpy(question[r], temp);

        strcpy(temp, answer[i]);
        strcpy(answer[i], answer[r]);
        strcpy(answer[r], temp);
    }

    printf("\n=== 学習モード ===\n");

    for (int i = 0; i < count; i++) {

        printf("\n問題 %d\n", i + 1);
        printf("%s\n", question[i]);
        printf("答え: ");

        fgets(userAnswer, MAX_LENGTH, stdin);
        userAnswer[strcspn(userAnswer, "\n")] = '\0';

        if (strcmp(userAnswer, answer[i]) == 0) {
            printf("正解\n");
            score++;
        } else {
            printf("不正解\n");
            printf("正解: %s\n", answer[i]);
        }
    }

    printf("\n=== 結果 ===\n");
    printf("%d問中%d問正解\n", count, score);

    if (count > 0) {
        printf("正答率 %.1f%%\n",
               (double)score / count * 100);
    }

    if (count > 0) {
        if (score == count) {
            printf("満点！すごい！\n");
        } else if ((double)score / count >= 0.8) {
            printf("よくできました！\n");
        } else if ((double)score / count >= 0.5) {
            printf("もう少し！\n");
        } else {
            printf("復習しよう！\n");
        }
    }

    printf("\n学習終了！\n");

    return 0;
}
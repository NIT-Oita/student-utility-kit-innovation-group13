#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

int main() {
    char japanese[MAX_WORDS][MAX_LENGTH];
    char english[MAX_WORDS][MAX_LENGTH];
    char answer[MAX_LENGTH];
    int count = 0;

    printf("=== 単語登録モード ===\n");
    printf("終了するには日本語に end と入力\n\n");

    while (count < MAX_WORDS) {

        printf("日本語: ");
        fgets(japanese[count], MAX_LENGTH, stdin);
        japanese[count][strcspn(japanese[count], "\n")] = '\0';

        if (strcmp(japanese[count], "end") == 0) {
            break;
        }

        printf("英語: ");
        fgets(english[count], MAX_LENGTH, stdin);
        english[count][strcspn(english[count], "\n")] = '\0';

        count++;
        printf("\n");
    }

 
    int score = 0;

printf("\n=== 学習モード ===\n");

for (int i = 0; i < count; i++) {

    printf("\n問題: %s\n", japanese[i]);
    printf("答え: ");

    fgets(answer, MAX_LENGTH, stdin);
    answer[strcspn(answer, "\n")] = '\0';

    if (strcmp(answer, english[i]) == 0) {
        printf("○ 正解！\n");
        score++;
    } else {
        printf("× 不正解！ 正解は %s\n", english[i]);
    }
}
    printf("\n=== 結果 ===\n");
printf("%d問中%d問正解！\n", count, score);
printf("正答率 %.1f%%\n", (double)score / count * 100);

    printf("\n学習終了！\n");

    return 0;
}
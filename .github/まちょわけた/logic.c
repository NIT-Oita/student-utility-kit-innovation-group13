#include <stdio.h>

#include <string.h>
 
int startQuiz(int count, char question[][100], char answer[][100]) {

    char userAnswer[100];

    int score = 0;
 
    for (int i = 0; i < count; i++) {

        printf("\n問題 %d\n", i + 1);

        printf("%s\n", question[i]);

        printf("答え: ");
 
        fgets(userAnswer, 100, stdin);

        userAnswer[strcspn(userAnswer, "\n")] = '\0';
 
        if (strcmp(userAnswer, answer[i]) == 0) {

            printf("○ 正解！\n");

            score++;

        } else {

            printf("× 不正解！\n");

            printf("正解: %s\n", answer[i]);

        }

    }
 
    return score;

}

 
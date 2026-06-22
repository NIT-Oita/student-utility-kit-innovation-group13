#include <stdio.h>

#include <string.h>
 
int startQuiz(int count, char question[][100], char answer[][100]) {

    char userAnswer[100];

    int score = 0;
 
    for (int i = 0; i < count; i++) {

        printf("\n–â‘è %d\n", i + 1);

        printf("%s\n", question[i]);

        printf("“š‚¦: ");
 
        fgets(userAnswer, 100, stdin);

        userAnswer[strcspn(userAnswer, "\n")] = '\0';
 
        if (strcmp(userAnswer, answer[i]) == 0) {

            printf("› ³‰ðI\n");

            score++;

        } else {

            printf("~ •s³‰ðI\n");

            printf("³‰ð: %s\n", answer[i]);

        }

    }
 
    return score;

}

 
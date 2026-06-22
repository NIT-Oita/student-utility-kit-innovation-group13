#include <stdio.h>
#include <string.h>

#include "logic.h"

int startQuiz(Quiz *quizList,
              int count) {

    int score = 0;

    char answer[100];

    for(int i=0;i<count;i++) {

        printf("\n問題%d\n",
               i + 1);

        printf("%s\n",
               quizList[i].question);

        printf("答え : ");

        fgets(answer,100,stdin);

        answer[strcspn(answer,"\n")] = '\0';

        if(strcmp(answer,
                  quizList[i].answer)==0) {

            printf("正解！\n");
            score++;
        }

        else {

            printf("不正解\n");
            printf("正解 : %s\n",
                   quizList[i].answer);
        }
    }

    return score;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "storage.h"

char *getFileName(int subject) {

    if(subject == 1)
        return "english.txt";

    return "social.txt";
}

void addQuestions(int subject) {

    FILE *fp =
        fopen(getFileName(subject), "a");

    char question[100];
    char answer[100];

    printf("終了は end\n\n");

    while(1) {

        printf("問題 : ");
        fgets(question,100,stdin);

        question[strcspn(question,"\n")] = '\0';

        if(strcmp(question,"end")==0)
            break;

        printf("答え : ");
        fgets(answer,100,stdin);

        answer[strcspn(answer,"\n")] = '\0';

        fprintf(fp,
                "%s,%s\n",
                question,
                answer);
    }

    fclose(fp);
}

int loadQuestions(int subject,
                  Quiz *quizList) {

    FILE *fp =
        fopen(getFileName(subject),"r");

    if(fp == NULL)
        return 0;

    int count = 0;

    char line[250];

    while(fgets(line,250,fp)) {

        sscanf(line,
               "%99[^,],%99[^\n]",
               quizList[count].question,
               quizList[count].answer);

        count++;
    }

    fclose(fp);

    return count;
}

void showQuestions(int subject) {

    FILE *fp =
        fopen(getFileName(subject),"r");

    char line[250];

    if(fp == NULL) {

        printf("データなし\n");
        return;
    }

    while(fgets(line,250,fp)) {

        printf("%s", line);
    }

    fclose(fp);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int loadQuestions(int subject, char question[][100], char answer[][100]) {
    int count = 0;
 
    while (count < 100) {
        if (subject == 1)
            printf("“ú–{Œê: ");
        else
            printf("–â‘è: ");
 
        fgets(question[count], 100, stdin);
        question[count][strcspn(question[count], "\n")] = '\0';
 
        if (strcmp(question[count], "end") == 0)
            break;
 
        if (subject == 1)
            printf("‰pŒê: ");
        else
            printf("“š‚¦: ");
 
        fgets(answer[count], 100, stdin);
        answer[count][strcspn(answer[count], "\n")] = '\0';
 
        count++;
        printf("\n");
    }
 
    return count;
}
 
void shuffleQuestions(int count, char question[][100], char answer[][100]) {
    for (int i = 0; i < count; i++) {
        int r = rand() % count;
 
        char temp[100];
 
        strcpy(temp, question[i]);
        strcpy(question[i], question[r]);
        strcpy(question[r], temp);
 
        strcpy(temp, answer[i]);
        strcpy(answer[i], answer[r]);
        strcpy(answer[r], temp);
    }
}
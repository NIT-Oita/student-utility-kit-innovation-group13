#ifndef LOGIC_H
#define LOGIC_H

typedef struct {
    char question[100];
    char answer[100];
} Quiz;

int startQuiz(Quiz *quizList, int count);

#endif
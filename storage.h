#ifndef STORAGE_H
#define STORAGE_H

#include "logic.h"

void addQuestions(int subject);
int loadQuestions(int subject, Quiz *quizList);
void showQuestions(int subject);

#endif
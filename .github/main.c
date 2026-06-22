#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
/* UI関数 */
int selectSubject();
void showRegisterMode();
void showStudyMode();
void showResult(int score, int count);
 
/* データ管理（B） */
int loadQuestions(int subject, char question[][100], char answer[][100]);
void shuffleQuestions(int count, char question[][100], char answer[][100]);
 
/* ロジック（A） */
int startQuiz(int count, char question[][100], char answer[][100]);
 
int main() {
    srand(time(NULL));
 
    char question[100][100];
    char answer[100][100];
 
    int subject = selectSubject();
    showRegisterMode();
 
    int count = loadQuestions(subject, question, answer);
    shuffleQuestions(count, question, answer);
 
    showStudyMode();
    int score = startQuiz(count, question, answer);
 
    showResult(score, count);
 
    return 0;
}
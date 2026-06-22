#include <stdio.h>
#include <stdlib.h>

#include "ui.h"
#include "logic.h"
#include "storage.h"

int main() {

    Quiz *quizList;

    quizList =
        malloc(sizeof(Quiz) * 100);

    if(quizList == NULL)
        return 1;

    while(1) {

        int menu =
            showMainMenu();

        if(menu == 1) {

            int subject =
                selectSubject();

            int count =
                loadQuestions(subject,
                              quizList);

            if(count == 0) {

                printf("–â‘è‚ª‚ ‚è‚Ü‚¹‚ñ\n");
                continue;
            }

            int score =
                startQuiz(quizList,
                          count);

            showResult(score,
                       count);
        }

        else if(menu == 2) {

            addQuestions(
                selectSubject());
        }

        else if(menu == 3) {

            showQuestions(
                selectSubject());
        }

        else if(menu == 4) {
            printf("•×‹­‚¨‚Â‚©‚ê‚³‚Ü‚Å‚µ‚½");

            break;
        }
    }

    free(quizList);

    return 0;
}
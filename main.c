#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "storage.h"
#include<string.h>

void addWordMenu() {
    char word[MAX_LEN];
    char meaning[MAX_LEN];

    printf("�P��: ");
    scanf("%s", word);

    printf("�Ӗ�: ");
    scanf("%s", meaning);

    if (addWord(word, meaning)) {
        printf("�o�^��\n");
    } else {
        printf("�o�^����ł\n");
    }
}

void quiz() {
    Word *w = getRandomWord();
    if (!w) {
        printf("�P�ꂪ����܂���\n");
        return;
    }

    char answer[MAX_LEN];
    printf("�Ӗ��𓚂��Ă�������: %s �� ", w->word);
    scanf("%s", answer);

    if (strcmp(answer, w->meaning) == 0) {
        printf("�����I\n");
    } else {
        printf("�s�����c ������ %s\n", w->meaning);
    }
}

int main() {
    srand(time(NULL));
    loadWords();

    int choice;
    while (1) {
        printf("\n--- �P��L���A�v�� ---\n");
        printf("1. �P���o�^\n");
        printf("2. �N�C�Y������\n");
        printf("3. �I��\n");
        printf("�I��: ");
        scanf("%d", &choice);

        if (choice == 1) addWordMenu();
        else if (choice == 2) quiz();
        else if (choice == 3) break;
        else printf("�����ȓ��͂ł�\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "storage.h"
#include<string.h>

void addWordMenu() {
    char word[MAX_LEN];
    char meaning[MAX_LEN];

    printf("単語: ");
    scanf("%s", word);

    printf("意味: ");
    scanf("%s", meaning);

    if (addWord(word, meaning)) {
        printf("登録しました\n");
    } else {
        printf("登録上限です\n");
    }
}

void quiz() {
    Word *w = getRandomWord();
    if (!w) {
        printf("単語がありません\n");
        return;
    }

    char answer[MAX_LEN];
    printf("意味を答えてください: %s → ", w->word);
    scanf("%s", answer);

    if (strcmp(answer, w->meaning) == 0) {
        printf("正解！\n");
    } else {
        printf("不正解… 正解は %s\n", w->meaning);
    }
}

int main() {
    srand(time(NULL));
    loadWords();

    int choice;
    while (1) {
        printf("\n--- 単語記憶アプリ ---\n");
        printf("1. 単語を登録\n");
        printf("2. クイズをする\n");
        printf("3. 終了\n");
        printf("選択: ");
        scanf("%d", &choice);

        if (choice == 1) addWordMenu();
        else if (choice == 2) quiz();
        else if (choice == 3) break;
        else printf("無効な入力です\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_LEN 50

typedef struct {
    char word[MAX_LEN];
    char meaning[MAX_LEN];
} Word;

Word words[MAX_WORDS];
int wordCount = 0;

void loadWords() {
    FILE *fp = fopen("words.txt", "r");
    if (!fp) return;

    while (fscanf(fp, "%s %s", words[wordCount].word, words[wordCount].meaning) != EOF) {
        wordCount++;
    }
    fclose(fp);
}

void saveWords() {
    FILE *fp = fopen("words.txt", "w");
    for (int i = 0; i < wordCount; i++) {
        fprintf(fp, "%s %s\n", words[i].word, words[i].meaning);
    }
    fclose(fp);
}

void addWord() {
    if (wordCount >= MAX_WORDS) {
        printf("登録上限です\n");
        return;
    }

    printf("単語: ");
    scanf("%s", words[wordCount].word);

    printf("意味: ");
    scanf("%s", words[wordCount].meaning);

    wordCount++;
    saveWords();
    printf("登録しました\n");
}

void quiz() {
    if (wordCount == 0) {
        printf("単語がありません\n");
        return;
    }

    srand(time(NULL));
    int i = rand() % wordCount;

    char answer[MAX_LEN];
    printf("意味を答えてください: %s → ", words[i].word);
    scanf("%s", answer);

    if (strcmp(answer, words[i].meaning) == 0) {
        printf("正解！\n");
    } else {
        printf("不正解… 正解は %s\n", words[i].meaning);
    }
}

int main() {
    loadWords();

    int choice;
    while (1) {
        printf("\n--- 単語記憶アプリ ---\n");
        printf("1. 単語を登録\n");
        printf("2. クイズをする\n");
        printf("3. 終了\n");
        printf("選択: ");
        scanf("%d", &choice);

        if (choice == 1) addWord();
        else if (choice == 2) quiz();
        else if (choice == 3) break;
        else printf("無効な入力です\n");
    }

    return 0;
}

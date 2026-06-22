#include <stdio.h>
#include <string.h>
#include "storage.h"
#include<time.h>
#include<stdlib.h>

Word words[MAX_WORDS];
int wordCount = 0;

void loadWords() {
    FILE *fp = fopen("words.txt", "r");
    if (!fp) return;

    while (fscanf(fp, "%s %s", words[wordCount].word, words[wordCount].meaning) != EOF) {
        wordCount++;
        if (wordCount >= MAX_WORDS) break;
    }
    fclose(fp);
}

void saveWords() {
    FILE *fp = fopen("words.txt", "w");
    if (!fp) return;

    for (int i = 0; i < wordCount; i++) {
        fprintf(fp, "%s %s\n", words[i].word, words[i].meaning);
    }
    fclose(fp);
}

int addWord(const char *word, const char *meaning) {
    if (wordCount >= MAX_WORDS) return 0;

    strcpy(words[wordCount].word, word);
    strcpy(words[wordCount].meaning, meaning);
    wordCount++;

    saveWords();
    return 1;
}

Word* getRandomWord() {
    if (wordCount == 0) return NULL;

    int i = rand() % wordCount;
    return &words[i];
}

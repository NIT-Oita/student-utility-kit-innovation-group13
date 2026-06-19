#ifndef STORAGE_H
#define STORAGE_H

#define MAX_WORDS 100
#define MAX_LEN 50

typedef struct {
    char word[MAX_LEN];
    char meaning[MAX_LEN];
} Word;

extern Word words[MAX_WORDS];
extern int wordCount;

void loadWords();
void saveWords();
int addWord(const char *word, const char *meaning);
Word* getRandomWord();

#endif

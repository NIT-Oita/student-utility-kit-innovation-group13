#ifndef STORAGE_H
#define STORAGE_H

#define MAX_WORDS 100
#define MAX_LEN 50

typedef struct {
    char word[MAX_LEN];
    char meaning[MAX_LEN];
    int level;
    int correct;
    int wrong;
} Word;

extern Word words[MAX_WORDS];
extern int wordCount;

void loadWords();
void saveWords();

int addWord(const char *word, const char *meaning);
int deleteWord(const char *word);
int editWord(const char *word);
void searchWord(const char *word);
void listWords();

Word* getRandomWord();
Word* getReviewWord();

#endif
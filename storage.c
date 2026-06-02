#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "storage.h"

Word words[MAX_WORDS];
int wordCount = 0;

void loadWords()
{
    FILE *fp = fopen("words.txt", "r");

    if (fp == NULL)
        return;

    while (wordCount < MAX_WORDS &&
           fscanf(fp,
                  "%49s %49s",
                  words[wordCount].word,
                  words[wordCount].meaning) == 2)
    {
        wordCount++;
    }

    fclose(fp);
}

void saveWords()
{
    FILE *fp = fopen("words.txt", "w");

    if (fp == NULL)
        return;

    for (int i = 0; i < wordCount; i++)
    {
        fprintf(fp,
                "%s %s\n",
                words[i].word,
                words[i].meaning);
    }

    fclose(fp);
}

int addWord(const char *word,
            const char *meaning)
{
    if (wordCount >= MAX_WORDS)
        return 0;

    strcpy(words[wordCount].word, word);
    strcpy(words[wordCount].meaning, meaning);

    wordCount++;

    saveWords();

    return 1;
}

Word* getRandomWord()
{
    if (wordCount == 0)
        return NULL;

    int index = rand() % wordCount;

    return &words[index];
}

void listWords()
{
    printf("\n====================\n");
    printf("      単語一覧\n");
    printf("====================\n");

    if (wordCount == 0)
    {
        printf("単語がありません\n");
        return;
    }

    for (int i = 0; i < wordCount; i++)
    {
        printf("%d. %s = %s\n",
               i + 1,
               words[i].word,
               words[i].meaning);
    }
}

void searchWord(const char *word)
{
    for (int i = 0; i < wordCount; i++)
    {
        if (strcmp(words[i].word, word) == 0)
        {
            printf("\n見つかりました！\n");
            printf("%s = %s\n",
                   words[i].word,
                   words[i].meaning);
            return;
        }
    }

    printf("見つかりませんでした\n");
}

int deleteWord(const char *word)
{
    for (int i = 0; i < wordCount; i++)
    {
        if (strcmp(words[i].word, word) == 0)
        {
            for (int j = i; j < wordCount - 1; j++)
            {
                words[j] = words[j + 1];
            }

            wordCount--;

            saveWords();

            return 1;
        }
    }

    return 0;
}
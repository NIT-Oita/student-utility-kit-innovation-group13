#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "storage.h"

void addWordMenu()
{
    char word[MAX_LEN];
    char meaning[MAX_LEN];

    printf("単語: ");
    scanf("%49s", word);

    printf("意味: ");
    scanf("%49s", meaning);

    if (addWord(word, meaning))
        printf("登録しました\n");
    else
        printf("登録上限です\n");
}

void normalQuiz()
{
    Word *w = getRandomWord();

    if (w == NULL)
    {
        printf("単語がありません\n");
        return;
    }

    char answer[MAX_LEN];

    printf("\n%s の意味は？\n", w->word);
    printf("回答: ");

    scanf("%49s", answer);

    if (strcmp(answer, w->meaning) == 0)
        printf("正解！\n");
    else
        printf("不正解...\n正解: %s\n", w->meaning);
}

void fourChoiceQuiz()
{
    if (wordCount < 4)
    {
        printf("4択クイズには単語が4個以上必要です\n");
        return;
    }

    int answerIndex = rand() % wordCount;

    int choices[4];
    choices[0] = answerIndex;

    int count = 1;

    while (count < 4)
    {
        int r = rand() % wordCount;

        int duplicate = 0;

        for (int i = 0; i < count; i++)
        {
            if (choices[i] == r)
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            choices[count] = r;
            count++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int j = rand() % 4;

        int temp = choices[i];
        choices[i] = choices[j];
        choices[j] = temp;
    }

    printf("\n%s の意味は？\n\n",
           words[answerIndex].word);

    for (int i = 0; i < 4; i++)
    {
        printf("%d. %s\n",
               i + 1,
               words[choices[i]].meaning);
    }

    int user;

    printf("\n番号を選択: ");
    scanf("%d", &user);

    if (user < 1 || user > 4)
    {
        printf("無効な入力です\n");
        return;
    }

    if (strcmp(words[choices[user - 1]].meaning,
               words[answerIndex].meaning) == 0)
    {
        printf("正解！\n");
    }
    else
    {
        printf("不正解...\n");
        printf("正解は %s\n",
               words[answerIndex].meaning);
    }
}

void searchMenu()
{
    char word[MAX_LEN];

    printf("検索する単語: ");
    scanf("%49s", word);

    searchWord(word);
}

void deleteMenu()
{
    char word[MAX_LEN];

    printf("削除する単語: ");
    scanf("%49s", word);

    if (deleteWord(word))
        printf("削除しました\n");
    else
        printf("見つかりませんでした\n");
}

int main()
{
    srand((unsigned)time(NULL));

    loadWords();

    int choice;

    while (1)
    {
        printf("\n");
        printf("=================================\n");
        printf("      単語暗記アプリ\n");
        printf("=================================\n");
        printf("1. 単語登録\n");
        printf("2. 通常クイズ\n");
        printf("3. 4択クイズ\n");
        printf("4. 単語一覧\n");
        printf("5. 単語検索\n");
        printf("6. 単語削除\n");
        printf("7. 終了\n");
        printf("=================================\n");
        printf("選択: ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addWordMenu();
            break;

        case 2:
            normalQuiz();
            break;

        case 3:
            fourChoiceQuiz();
            break;

        case 4:
            listWords();
            break;

        case 5:
            searchMenu();
            break;

        case 6:
            deleteMenu();
            break;

        case 7:
            printf("終了します\n");
            return 0;

        default:
            printf("無効な入力です\n");
        }
    }

    return 0;
}
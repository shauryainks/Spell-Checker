#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <strings.h>

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int totalwords = 0;

const unsigned int N = 2600;
node *table[N];

bool check(const char *word)
{
    char wordtemp[LENGTH + 1];
    int lengthcurrent = strlen(word);
    for (int i = 0; i < lengthcurrent + 1; i++)
    {
        wordtemp[i] = tolower(word[i]);
    }

    int h = hash(wordtemp);
    for (node *tmp = table[h]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, wordtemp) == 0)
        {
            return true;
        }
    }

    return false;
}

unsigned int hash(const char *word)
{
    int total = 0;
    int lengthcurrent = strlen(word);
    for (int i = 0; i < lengthcurrent; i++)
    {
        total = total + word[i];
    }
    total = total % N;
    return total;
}

bool load(const char *dictionary)
{
    FILE *dictionary_pointer = fopen(dictionary, "r");
    if (dictionary_pointer == NULL)
    {
        return false;
    }

    for (int p = 0; p < N; p++)
    {
        table[p] = NULL;
    }

    char *readword = malloc(LENGTH + 1);
    if (readword == NULL)
    {
        return false;
    }

    int h;
    while (fscanf(dictionary_pointer, "%s", readword) != EOF)
    {
        totalwords++;
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return false;
        }

        strcpy(temp->word, readword);
        h = hash(readword);

        if (table[h] != NULL)
        {
            temp->next = table[h];
            table[h]  = temp;
        }
        else
        {
            temp->next = NULL;
            table[h] = temp;
        }
    }

    fclose(dictionary_pointer);
    free(readword);

    return true;
}

unsigned int size(void)
{
    return totalwords;
}

bool unload(void)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            while (table[i] != NULL)
            {
                node *tmp = table[i]->next;
                free(table[i]);
                table[i] = tmp;
            }
        }
    }
    return true;
}

/*
 * Trie树（字典树）
 * liuyang1 2014.06.25
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHARSETSIZE    ('z'-'a' + 1)

typedef struct TrieNode{
    char c;
    int counter;
    struct TrieNode* nextMap[CHARSETSIZE];
}TrieNode;

void initTrieNode(TrieNode* p, char c)
{
    p->c = c;
    p->counter = 0;
    for(int i = 0; i < CHARSETSIZE; i++)
        p->nextMap[i] = NULL;
}

void incTrieNode(TrieNode* p)
{
    p->counter = p->counter + 1;
}

int compTrieNode(TrieNode* p, char c)
{
    if(p->c == c)
        return 0;
    else if(p->c > c)
        return 1;
    else
        return -1;
}

int Char2Index(char c)
{
    return c - 'a';
}

TrieNode* getNextChar(TrieNode* t, char c)
{
    return t->nextMap[Char2Index(c)];
}

void setNextChar(TrieNode* t, char c, TrieNode* new)
{
    TrieNode* ptr = getNextChar(t, c);
    if(ptr != NULL)
        printf("warnning: already set next char %p %c %p\n", t, c, new);
    t->nextMap[Char2Index(c)] = new;
}

void updateWord(TrieNode* t, char* word)
{

    TrieNode* ot = t;
    int len = strlen(word);
    int tail = len - 1;
    for(int i = 0; i < len; i++)
    {
        char c = word[i];
        TrieNode* ptr = getNextChar(t, c);
        if(ptr != NULL)
        {
            t = ptr;
            if(i == tail)
                incTrieNode(t);
        }else
        {
            TrieNode* new = (TrieNode*)malloc(sizeof(TrieNode));
            initTrieNode(new, c);
            if(i == tail)
                incTrieNode(new);
            setNextChar(t, c, new);
            t = new;
        }
    }
}

int getWord(TrieNode* t, char* word)
{
    int len = strlen(word);
    int tail = len - 1;
    for(int i = 0; i < len; i++)
    {
        char c = word[i];
        TrieNode* ptr = getNextChar(t, c);
        if(ptr != NULL)
        {
            t = ptr;
            if(i == tail)
                return t->counter;
        }else
            return 0;
    }
    return 0;
}
void dispTrieNodeI(TrieNode* t, int level)
{
    if(t == NULL)
        return;
    for(int i = 0; i < level; i++)
        putchar('\t');
    printf("%c %d\n", t->c, t->counter);
    int nextLevel = level + 1;
    for(int i = 0; i < CHARSETSIZE; i++)
    {
        dispTrieNodeI(t->nextMap[i], nextLevel);
    }
}

void dispTrieNode(TrieNode* t)
{
    dispTrieNodeI(t, 0);
}


int main()
{
    TrieNode* root = (TrieNode*)malloc(sizeof(TrieNode));
    initTrieNode(root, ' ');
    char words[][8] = {"inn", "int", "at", "age", "adv",
        "ant", "in", "in"};
    for(int i = 0; i < 8; i++)
        updateWord(root, words[i]);
    dispTrieNode(root);
    char se[] = "in";
    printf("search %s %d\n", se, getWord(root, se));
    return 0;
}

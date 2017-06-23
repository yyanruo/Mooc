/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

#define HASH_SIZE 5555

typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

node* hashtable[HASH_SIZE];

int counter =0;

// hash the word to some number
int hash(const char* word){

    int index = 0;

    for (int i=0; word[i]!= '\0';i++)
    {
         index += word[i];
    }
    return index %HASH_SIZE;  
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    //hash the number of the word
    node* check_word = hashtable[hash(word)];

    //loop the nodes while the point isn't NULL.
    while(check_word!=NULL){

        if (strcmp(check_word->word, word) == 0)
        {
            return true;
        }
        check_word = check_word->next;
    }

    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //open file
    FILE* fp = fopen(dictionary, "r");

    if(fp == NULL)
    {
        return false;
    }

    while(!feof(fp)){

        //make new node to save word
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            fclose(fp);
            return false;
        }
        
        //input the word 
        if(fscanf(fp, "%s", new_node->word)!=1){
            free(new_node);
            break;
        }

        //calculate the hash number of the word
        int hashed = hash(new_node->word);

        //insert the new_node into the hash table
            //insert the word to the place has not existed hashed word
        if (hashtable[hashed]==NULL)
        {
            hashtable[hashed] = new_node;
            new_node->next = NULL;
        }
            //insert the word to the place has existed hashed word
        else
        {
            new_node->next = hashtable[hashed];
            hashtable[hashed] = new_node;
        }
        //conuter the number which has been inserted into the hashtable.
        counter++;
    }

    // close dictionnary
    fclose(fp);

    // that's all folks!
    return true;

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for (int i = 0; i < HASH_SIZE; ++i)
    {
        node* cursor = hashtable[i];

        //free the linkedlist node in the hashtable[i]
        while(cursor != NULL){
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}

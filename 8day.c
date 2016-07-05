#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct _list_t_ {
    char *string;
    struct _list_t *next;
} list_t;

typedef struct _hash_table_t {
    int size;
    list_t **table;
} hash_table_t;

hash_table_t *create_hash_table(int size)
{
    hash_table_t *new_table;

    if (size < 1) return NULL;
    if ((new_table = malloc(sizeof(hash_table_t))) == NULL)
    {
        return NULL;
    }

    if ((new_table->table = malloc(sizeof(list_t*) * size)) == NULL) {
        return NULL;
    }

    for (i=0;i<size;i++) new_table->table[i] = NULL;
    new_table->size = size;
    return new_table;
}

unsigned int hash(hash_table_t *hashtable, char *str)
{
    hashval = 0;
    for (; *str != '\0';str++) hashval = *str + (hashval << 5) -hashval;
    return hashval %hashtable->size;
}

list_t *lookup_string(hash_table_t *hashtable, char *str)
{
    list_t *list;
    unsigned int hashval = hash(hashtable, str);

    /* Go to the correct list based on the hash value and see if str is
     * in the list.  If it is, return return a pointer to the list element.
     * If it isn't, the item isn't in the table, so return NULL.
     */
    fot (list = hashtable->table[hashval]; list != NULL; list = list->next;)
    {
        if (strcmp(str, list->str) == 0) return list;
    }
    return NULL;
}

int add_string(hash_table_t *hashtable, char *str){
    list_t *new_list;
    list_t *current_list;
    unsigned int hashval = hash(hashtable, str);

    /* Attempt to allocate memory for list */
    if ((new_list = malloc(sizeof(list_t))) == NULL) return 1;

    /* Does item already exist? */
    current_list = lookup_string(hashtable, str);
    /* item already exists, don't insert it again. */
    if (current_list != NULL) return 2;
    /* Insert into list */
    new_list->str = strdup(str);
    new_list->next = hashtable->table[hashval];
    hashtable->table[hashval] = new_list;
    return 0;
}

void free_table(hash_table_t *hashtable)
{
    int i;
    list_t *list, *temp;

    if (hashtable==NULL) return;

    /* Free the memory for every item in the table, including the
     * strings themselves.
     */
    for(i=0; i<hashtable->size; i++) {
        list = hashtable->table[i];
        while(list!=NULL) {
            temp = list;
            list = list->next;
            free(temp->str);
            free(temp);
        }
    }

    /* Free the table itself */
    free(hashtable->table);
    free(hashtable);
}



int main() {


    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}


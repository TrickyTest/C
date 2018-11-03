#include <search.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
      int key;
      char* value;
} intStrMap;

int compar(const void *l, const void *r)
{
    const intStrMap *lm = l;
    const intStrMap *lr = r;
	printf("Comparing %d with %d.\n",lm->key,lr->key);
    return lm->key - lr->key;
}

int main(int argc, char **argv)
{
    void *root = 0;

    intStrMap *a = malloc(sizeof(intStrMap));
    a->key = 2;
    a->value = strdup("two");
    tsearch(a, &root, compar); /* insert */

    a = malloc(sizeof(intStrMap));
    a->key = 2;
    a->value = strdup("two!");
    tsearch(a, &root, compar); /* insert */

    a = malloc(sizeof(intStrMap));
    a->key = 3;
    a->value = strdup("three");
    tsearch(a, &root, compar); /* insert */


    intStrMap *find_a = malloc(sizeof(intStrMap));
    find_a->key = 3;


    void *r = tfind(find_a, &root, compar); /* read */
    printf("%s\n\n", (*(intStrMap**)r)->value);

    find_a = malloc(sizeof(intStrMap));
    find_a->key = 2;


    r = tfind(find_a, &root, compar); /* read */
    printf("%s\n\n", (*(intStrMap**)r)->value);

    return 0;
}

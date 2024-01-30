#include <stdio.h>
#include <stdlib.h>
#include "link-list.h"

void List_print(List *list);

int main()
{
    List *list = newList();
    Long *x = (Long *) calloc(sizeof(Long), 1);
    *x = 19;
    List_add(list, x);
    Long *y = (Long *) calloc(sizeof(Long), 1);
    *y = 119;
    List_add(list, y);

    List_print(list);
}

void List_print(List *list)
{
    for(Long i = 0; i < list->length; i++)
    {
        Long x = *((Long*) List_at(list, i));
        printf("%lld/%lld %lld\n", i, list->length - 1, x);
    }
}

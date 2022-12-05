#include <stdio.h>
#include "linked_list.h"

int main()
{
    int cinq = 5;
    linked_list list = linked_list_push(NULL,&cinq);
    linked_test(&list);
    printf("%d valeur\n",*(int*)list->value);
    printf("%d valeur de l'ancien premier\n",*(int*)list->next->value);
    return 0;
}
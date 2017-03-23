#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char *argv[])
{
    SO_List *list = (SO_List*)malloc(sizeof(SO_List));
    initialize(list);
    insert(list, "TestA");
    print_list(list);
    insert(list, "TestB");
    print_list(list);
    insert(list, "TestC");
    print_list(list);
    insert(list, "TestC");
    print_list(list);

    return 0;
}
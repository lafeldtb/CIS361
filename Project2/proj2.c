/*************************************************
Implementation of A Self-organizing list
Reads in passed file and outputs the complete self-organizing list

Author: Benjamin LaFeldt
Grand Valley State University
CIS 361
*************************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    SO_List *list = (SO_List*)malloc(sizeof(SO_List));
    initialize(list);
    FILE *fp;
    fp = fopen(argv[1],"r");
    if(fp < 0)
        return 1;

    enum STATE{IDENTIFIER, SPACE};
    enum STATE State  = SPACE;
    char *identifier = "";
    identifier = (char*)malloc(sizeof(char)*100);
    int len;
    bool comment = false;
    bool literal = false;

    while(!feof(fp))
    {
        char ch = fgetc(fp);
        if(ch == '/')
        {
            comment = !comment;
        }
        if(ch == '\"')
        {
            literal = !literal;
        }
        if(ch == '\n')
        {
            comment = false;
            literal = false;
        }
        switch (State) {
            case SPACE:
                if(isalpha(ch) != 0 && !comment && !literal)
                {
                    len = strlen(identifier);
                    identifier[len] = ch;
                    identifier[len+1] = '\0';
                    State = IDENTIFIER;
                }
                break;
            case IDENTIFIER:
                if(isalnum(ch) != 0 || ch == '_')
                {
                    len = strlen(identifier);
                    identifier[len] = ch;
                } else {
                    insert(list, identifier);
                    State = SPACE;
                    len = 0;
                    identifier = malloc(100*sizeof(char));
                }
                break;
        }
    }
    fclose(fp);

    print_list(list);
    return 0;
}
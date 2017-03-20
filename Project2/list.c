#include "list.h"

void initialize(SO_List *list)
{
    list->count = 0;
    list->head = NULL;
}

bool is_empty(SO_List *list)
{
    if(list->count > 0)
        return false;
    
    return true;
}

//returns and removes target node from list
//TODO: check that head works
Node* traverse(Node *head, char *identifier)
{
    if(strcmp(identifier, head->identifier) == 0)
    {
        return head;
    }
    else
    {
        if(head->next != NULL)
        {
            Node *targetnode;
            targetnode = traverse(head->next, identifier);
            if(targetnode != NULL)
            {
                if(targetnode == head->next)
                {
                    head->next = head->next->next;
                }
                return targetnode;
            }
        }
        return NULL;
    }
}

Node* find_id(SO-List *list, char *identifier)
{
    if(!is_empty(list))
    {
        Node *temp;
        temp = traverse(list, identifier);
    }
}
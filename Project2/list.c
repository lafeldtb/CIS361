/*************************************************
A Self-organizing list

Author: Benjamin LaFeldt
Grand Valley State University
CIS 361
*************************************************/
#include "list.h"

void insert_node(Node *head, char *identifier);
Node* traverse(Node *head, char *identifier);
void print_nodes(Node *head);

void initialize(SO_List *list)
{
    list->count = 0;
    list->head = (Node*)malloc(sizeof(Node));
    list->head = NULL;
}

bool is_empty(SO_List *list)
{
    if(list->count > 0)
        return false;
    
    return true;
}

//returns target and brings it to front of the list
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
            Node *targetnode = (Node*)malloc(sizeof(Node));
            targetnode = traverse(head->next, identifier);
            if(targetnode != NULL)
            {
                head->next = targetnode->next;
                targetnode->next = head;
            }
            return targetnode;
        }
        return NULL;
    }
}

Node* find_id(SO_List *list, char *identifier)
{
    if(!is_empty(list))
    {
        Node *temp = (Node*)malloc(sizeof(Node));
        temp = traverse(list->head, identifier);
        if(temp != NULL)
            list->head = temp;
        return temp;
    }
    return NULL;
}

void print_list(SO_List *list)
{
    if(list->count == 0)
    {
        printf("List is empty\n");
    }
    printf("[Identifier]:\t[Occurrences]\n");
    printf("-------------\t-------------\n");
    print_nodes(list->head);
}

void print_nodes(Node *head)
{
    if(head != NULL)
    {
        printf("%s:\t%d\n",head->identifier,head->occurrences);
        print_nodes(head->next);
    } else {
        printf("Null\n\n");
    }
}

void insert(SO_List *list, char *identifier)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n = find_id(list, identifier);
    if(n != NULL)
    {
        n->occurrences++;
    }
    else
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->identifier = (char*)malloc(strlen(identifier)*sizeof(char));
        memcpy(newnode->identifier, identifier, strlen(identifier));
        newnode->identifier = identifier;
        newnode->occurrences = 1;
        newnode->next = (Node*)malloc(sizeof(Node));
        newnode->next = list->head;
        list->head = newnode;
    }
    list->count++;

}

int length(SO_List *list)
{
    return list->count;
}
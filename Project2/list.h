#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;

struct Node {
	char* identifier;
	int occurrences;
	struct Node *next;
};

typedef struct Node Node;

struct SO_List {
	int count;
	Node *head;
};

typedef struct SO_List SO_List;

void initialize(SO_List *list);
bool is_empty(SO_List *list);
bool insert(SO_List *list, char *identifier);
Node find_id(SO_List *list, char *identifier);
Node traverse(Node *head, char *identifier);
char* to_string(SO_List *list);

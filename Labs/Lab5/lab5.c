#define TRUE 1
#define FALSE 0
#define MAX 25

typedef int EType;		// type of elements in stack
typedef int BOOLEAN;

typedef struct {
	EType data[MAX];
	int top;
} STACK;

void initialize(STACK *pS) 	// initialze the stack	
{
	int index;
	for(index = 0; index < MAX; index++)
	{
		pS->data[index] = 0;
	}
	pS->top = -1;
}

BOOLEAN isEmpty(STACK *pS) 	// returns true if the stack is empty
{
	return pS->top < 0 ? TRUE : FALSE;
}

BOOLEAN isFull(STACK *pS)  	// returns true if the stack is full
{
	return pS->top == MAX-1 ? TRUE : FALSE;
}

BOOLEAN pop(STACK *pS, EType *px)	// removes the top element from the stack 
{					// has px point to the removed element   
       					// returns true if done successfully       
	if(isEmpty(pS) == FALSE)
	{
		*px = pS->data[pS->top];
		pS->top--;
		return TRUE;
	} else {
		return FALSE;
	}

}

BOOLEAN push(EType x, STACK *pS)	// puts an element on the top of the stack  
{					// returns true if done successfully       
	if(isFull(pS) == FALSE)
	{
		pS->top++;
		pS->data[pS->top] = x;
		return TRUE;
	} else {
		return FALSE;
	}

}

int main ()
{
	STACK s;
	int i;
	
	initialize (&s);
	// write code below to test functions defined above
	// TEST initialize
	printf("---Initialize test---\n");
	/**
	for(i = 0; i < MAX; i++)
	{
		printf("Stack element %d:\t%d\n", i, s.data[i]);
	}
	*/
	printf("Top of stack: %d\n", s.top);
	printf("Address of stack[0]: %d\n", s.data);

	printf("\n---test empty true---\n");
	printf("Test if empty (It should be): %d\n", isEmpty(&s));

	printf("\n---test full false---\n");
	printf("Test if full (It should not be): %d\n", isFull(&s));

	printf("\n---Test push true---\n");
	EType t = 4;
	printf("Push %d: %d\n",t, push(t, &s));

	printf("\n---test empty false---\n");
	printf("Empty?\t%d\n", isEmpty(&s));
	printf("Top of stack: data[%d]: %d\n", s.top, s.data[s.top]);
	t = 7;
	printf("Push?:\t%d\tReturned:\t%d\n",t, push(t, &s));
	printf("Empty?\t%d\n", isEmpty(&s));
	printf("Top of stack: data[%d]: %d\n", s.top, s.data[s.top]);
	printf("\n---Test pop true---\n");
	printf("Pop?:\t%d\tReturned:\t%d\n", pop(&s, &t), t);
	/**
	for(i = 0; i < MAX; i++)
	{
		printf("Stack element %d:\t%d\n", i, s.data[i]);
	}
	**/
	printf("\n---Test pop false---\n");
	printf("Pop?:\t%d\tReturned:\t%d\n", pop(&s, &t), t);
	printf("Pop?:\t%d\tReturned:\t%d\n", pop(&s, &t), t);
	printf("Top of stack: data[%d]: %d\n", s.top, s.data[s.top]);

	printf("\n---Test push false---\n");
	for(i=0; i<MAX+3; i++)
	{
		t = i*2;
		printf("Push?:\t%d\tReturned:\t%d\n",t, push(t, &s));
	}

	printf("\n---test full true---\n");
	printf("Full? %d", isFull(&s));
	printf("Top of stack: data[%d]: %d\n", s.top, s.data[s.top]);

 
	return 0;
}

#include <stdio.h>
#include <ctype.h>

int main() {
	char ch;
	int wc = 0;
	int sc = 0;
	enum STATE {SPACE, WORD, SYMB} state;
	state = SPACE;

	printf("Enter text (Ctrl-D to quit).\n");
	while(ch = getchar(), ch != EOF) {
		switch(state)
		{
			case SPACE:
				if(isalnum(ch) || ch == '_')
				{
					state = WORD;
					wc+=1;
					break;
				} else if(isspace(ch)){
					break;
				} else {
					state = SYMB;
					sc+=1;
					break;
				}
			case WORD:
				if(isalnum(ch) || ch == '_'){
					break;
				} else if(isspace(ch))
				{
					state = SPACE;
					break;
				} else {
					state = SYMB;
					sc+=1;
					break;
				}
			case SYMB:
				if(isalnum(ch) || ch == '_'){
					state = WORD;
					wc+=1;
					break;
				} else if(isspace(ch)) {
					state = SPACE;
					break;
				}
		}
	}
	//putchar(ch);
	printf("Word count:%d\n",wc);
	printf("Sequence count: %d\n",sc);

	return 0;
}

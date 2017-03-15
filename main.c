#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int string_is_valid(void);
void buffclear(void);

int main(int argc, char* argv[]) 
{
	int i, x;

	scanf("%d", &x);
	buffclear();

	for (i = 0; i < x; i++) {
		if (string_is_valid()) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}

	return 0;
}

int string_is_valid(void) 
{
	int c, result, i;
	STACK hStack;
	hStack = stack_init_default();
	result = 1;
	i = 0;
	
	c = getc(stdin);

	while (c != '\n' && c != EOF) {
		
		if (c == '(' || c == '[' || c == '{') {
			stack_push(hStack, c);
		}
		else if (c == ')') {
			if (stack_top(hStack, NULL) != '(') {
				result = 0;
			}
			stack_pop(hStack);
		}
		else if (c == ']') {
			if (stack_top(hStack, NULL) != '[') {
				result = 0;
			}
			stack_pop(hStack);
		}
		else if (c == '}') {
			if (stack_top(hStack, NULL) != '{') {
				result = 0;
			}
			stack_pop(hStack);
		}
		else {
			result = 0;
		}

		c = getc(stdin);
		i++;
	}

	if (!stack_empty(hStack) && i != 0) {
		result = 0;
	}

	return result;
	
	stack_destroy(hStack);
}

void buffclear(void) 
{
	char z;

	scanf("%c", &z);
	while (z != '\n') {
		scanf("%c", &z);
	}

	return;
}
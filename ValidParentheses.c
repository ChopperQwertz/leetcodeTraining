#define STACK_MAX 256
typedef struct Stack {
    char    data[STACK_MAX];
    int     size;
} Stack;
int myPush(Stack *S, char ch) {
	if (S->size == STACK_MAX) {
		printf("stack size not enough!\n");
		return -1;
	}
	S->data[S->size++] = ch;	
	return 0;
}
int myPop(Stack *S, char ch) {
	switch(ch) {
		case '}' :
			if (S->data[S->size-1] != '{') {
				return -1;
			} else 
				S->size--;
			break;
		case ']' :
			if (S->data[S->size-1] != '[') {
				return -1;
			} else 
				S->size--;
			break;
		case ')' :
			if (S->data[S->size-1] != '(') {
				return -1;
			} else 
				S->size--;
			break;
		default:
			break;
	}
	return 0;
}
bool isValid(char* s) {
	int i=0;
	Stack stack;
	stack.size = 0;
	if (s == (char *)0)
		return true;
	while (s[i]!='\0') {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			if (myPush(&stack, s[i]))
				return false;
		} else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			if (myPop(&stack, s[i]))
				return false;
		} else {
			return false;
		}
		i++;
	}
	if (stack.size != 0)
		return false;
	else 
		return true;
}


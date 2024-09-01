#include<stdio.h>
#include<ctype.h>
#define MAX 20
#include<string.h>
typedef struct{
	char arr[MAX];
	int top;
}Stack;
typedef enum {rparen, lparen, mul, div, mod, add, sub}precedence;
int isFull(Stack *s){
	if(s->top==MAX-1){
		//printf("Stack is full!\n");
		return 1;
	}
	else return 0;
}
int isEmpty(Stack *s){
	if(s->top==-1){
		//printf("Stack is empty!\n");
		return 1;
	}
	else return 0;
}
void push(Stack *s, char item){
	if(isFull(s)==1)return;
	else{
		s->arr[++(s->top)]=item;
	}
}
char pop(Stack *s){
	if(isEmpty(s)==1)return '!';
	else return s->arr[(s->top)--];
}
precedence get(char c){
	switch(c){
		case '-':return sub;
		case '+':return add;
		case '%':return mod;
		case '/':return div;
		case '*':return mul;
		case '(':return lparen;
		case ')':return rparen;
	}
}
int main(){
	Stack s, pre;
	s.top=-1;
	pre.top=-1;
	char c[20];
	printf("Enter any infix expression: \n");
	scanf("%s", c);
	for(int i=strlen(c)-1; i>=0; i--){
		if(isdigit(c[i]))push(&pre, c[i]);
		else{
			char ch = pop(&s);
			if(ch=='!'){
				push(&s, c[i]);
			}
			else{
				if(get(c[i])<get(ch) && get(c[i])!=1){
					//printf("%d##%d\n", get(c[i]), get(ch));
					push(&s, ch);
					push(&s, c[i]);		
				}
				else if(get(c[i])==1){
                                        while(get(ch)!=0){
                                                push(&pre, ch);
						ch = pop(&s);
                                        }
				}
				else{
					while(get(c[i])>get(ch) && ch!='!'){
						//printf("%d##%d\n", get(c[i]), get(ch));
						push(&pre, ch);
						ch = pop(&s);
					}
					//printf("%c\n", ch);
					if(ch!='!') push(&s, ch);
					push(&s, c[i]);
				}
			}
		}
	}
	int t = s.top;
	//printf("%d\n", t);
	for(int i=0; i<=t; i++) push(&pre, pop(&s));
	t = pre.top;
	printf("Required prefix expression is:\n");
	for(int i=0; i<=t; i++) printf("%c", pop(&pre));
	printf("\n");
	return 0;
}

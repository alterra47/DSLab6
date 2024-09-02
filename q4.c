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
typedef struct{
	char* arr[MAX];
	int top;
}Stack1;
void push1(Stack1 *s, char *str){
	s->arr[++(s->top)]=str;
}
char* pop1(Stack1 *s){
	return s->arr[(s->top)--];
}
int main(){
	Stack1 s1;
	s1.top=-1;
	char c[20][20];
	printf("Enter length of expression:\n");
	int n;
	scanf("%d",&n);
	printf("Enter prefix expression:\n");
	for(int i=0; i<n; i++)scanf("%s", c[i]);
	for(int i=n-1; i>=0; i--){
		if(isdigit(c[i][0]))push1(&s1, c[i]);
		else if(c[i][0]=='+'){
			char *a=pop1(&s1);
			char *b=pop1(&s1);
			strcat(a,"+");
			strcat(a,b);
			push1(&s1, a);
		}
		else if(c[i][0]=='-'){                                                                                                                                                 char *a=pop1(&s1);
                        char *b=pop1(&s1);
			strcat(a,"-");
                        strcat(a,b);
                        push1(&s1, a);
		}
		else if(c[i][0]=='*'){                                                                                                                                                 char *a=pop1(&s1);
                        char *b=pop1(&s1);
			strcat(a,"*");
                        strcat(a,b);
                        push1(&s1, a);
                }
		else if(c[i][0]=='/'){                                                                                                                                                 char *a=pop1(&s1);
                        char *b=pop1(&s1);
			strcat(a,"/");
                        strcat(a,b);
                        push1(&s1, a);
                }
		else if(c[i][0]=='%'){                                                                                                                                                 char *a=pop1(&s1);
                        char *b=pop1(&s1);
                        strcat(a,"%");
                        strcat(a,b);
                        push1(&s1, a);
		}			
		else continue;
	}
	printf("Required infix is:\n");
	char *c1;
	c1=pop1(&s1);
	printf("%s\n", c1);
	Stack s, pre;
	s.top=-1;
	pre.top=-1;
	for(int i=0; i<strlen(c1); i++){
		if(isdigit(c1[i]))push(&pre, c1[i]);
		else{
			char ch = pop(&s);
			if(ch=='!'){
				push(&s, c1[i]);
			}
			else{
				if(get(c1[i])<get(ch) && get(c1[i])!=1){
					//printf("%d##%d\n", get(c[i]), get(ch));
					push(&s, ch);
					push(&s, c1[i]);		
				}
				else if(get(c1[i])==0){
                                        while(get(ch)!=1){
                                                push(&pre, ch);
						ch = pop(&s);
                                        }
				}
				else{
					while(get(c1[i])>get(ch) && ch!='!'){
						//printf("%d##%d\n", get(c[i]), get(ch));
						push(&pre, ch);
						ch = pop(&s);
					}
					//printf("%c\n", ch);
					if(ch!='!') push(&s, ch);
					push(&s, c1[i]);
				}
			}
		}
	}
	int t = s.top;
	//printf("%d\n", t);
	for(int i=0; i<=t; i++) push(&pre, pop(&s));
	t = pre.top;
	printf("Required postfix expression is:\n");
	for(int i=0; i<=t; i++) push(&s, pop(&pre));
	t = s.top;
	for(int i=0; i<=t; i++) printf("%c", pop(&s));
	printf("\n");
	return 0;
}

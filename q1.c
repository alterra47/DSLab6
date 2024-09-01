#include<stdio.h>
#include<ctype.h>
#define MAX 20
#include<string.h>
typedef struct{
	int arr[MAX];
	int top;
}Stack;
int isFull(Stack *s){
	if(s->top==MAX-1){
		printf("Stack is full!\n");
		return 1;
	}
	else return 0;
}
int isEmpty(Stack *s){
	if(s->top==-1){
		printf("Stack is empty!\n");
		return 1;
	}
	else return 0;
}
void push(Stack *s, int item){
	if(isFull(s)==1)return;
	else{
		s->arr[++(s->top)]=item;
	}
}
int pop(Stack *s){
	if(isEmpty(s)==1)return -1;
	else return s->arr[(s->top)--];
}
int main(){
	Stack s;
	s.top=-1;
	char c[20]; 
	printf("Enter prefix expression:\n");
	scanf("%s", c);
	for(int i=strlen(c)-1; i>=0; i--){
		if(isdigit(c[i]))push(&s, c[i]-'0');
		//removing ascii value
		else if(c[i]=='+'){
			int a=pop(&s);
			int b=pop(&s);
			push(&s, a+b);
		}
		else if(c[i]=='-'){
                        int a=pop(&s);
                        int b=pop(&s);
                        push(&s, a-b);
                }
		else if(c[i]=='*'){
                        int a=pop(&s);
                        int b=pop(&s);
                        push(&s, a*b);
                }
		else if(c[i]=='/'){
                        int a=pop(&s);
                        int b=pop(&s);
                        push(&s, a/b);
                }
		else if(c[i]=='%'){
                        int a=pop(&s);
                        int b=pop(&s);
                        push(&s, a%b);
                }
		else continue;
	}
	printf("Required result is: %d\n", pop(&s));
	return 0;
}

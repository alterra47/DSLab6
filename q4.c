#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
typedef struct{
	char* arr[MAX];
	int top;
}Stack;
int isFull(Stack *s){
	if(s->top==MAX-1){
		printf("Stack is full!");
		return 1;
	}
	else return 0;
}
int isEmpty(Stack *s){
	if(s->top==-1){
                printf("Stack is empty!");
                return 1;
        }
        else return 0;
}
void push(Stack *s, char *str){
	if(isFull(s)==1) return;
	s->arr[++(s->top)]=str;
}
char* pop(Stack *s){
	if(isEmpty(s)==1) return "\0";
        return s->arr[(s->top)--];
}
int main(){
	Stack st;
	st.top=-1;
	char c[20];
	char s[20][20];
	printf("Enter any prefix expression:\n");
	scanf("%s",c);
	for(int i=0; i<strlen(c); i++){
		s[i][0]=c[i];
	}
	for(int i=strlen(c)-1;  i>=0; i--){
		if(isdigit(s[i][0]))push(&st, s[i]);
		else if(s[i][0]=='+'||s[i][0]=='-'||s[i][0]=='*'||s[i][0]=='/'||s[i][0]=='%'){
			char  *a=pop(&st);
			char *b=pop(&st);
			strcat(a,b);
			strcat(a,s[i]);
			push(&st, a);
		}
	}
	int t=st.top;
	printf("Required postfix is: ");
	for(int i=0; i<=t; i++){
		printf("%s",pop(&st));
	}
	printf("\n");
	return 0;
}

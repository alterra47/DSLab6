#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 20
typedef struct{
	char* arr[20];
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
	printf("%s\n", pop1(&s1));
	return 0;
}

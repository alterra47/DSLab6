#include<stdio.h>
#define MAX 3
typedef struct{
	char arr[MAX];
	int top1;
	int top2;
}TwoStack;
int isFull(TwoStack *s){
	if(s->top1==(s->top2)-1){
		printf("Stack is full!\n");
		return 1;
	}
	else return 0;
}
int isEmpty(TwoStack *s){
	if(s->top2==MAX){
		printf("Stack1 is empty!\n");                                                                                                                                return -1;
	}
        if(s->top1==-1){
                printf("Stack2 is empty!\n");
                return 1;
        }
        else return 0;
}
void pushTo1(TwoStack *s){
	if(isFull(s)==1) return;
	printf("Enter charecter to be pushed:\n");
	char c;
	scanf(" %c", &c);
	s->arr[++(s->top1)] = c;
	printf("top1: %d\n", s->top1);
}
void pushTo2(TwoStack *s){
	if(isFull(s)==1) return;
        printf("Enter charecter to be pushed:\n");
        char c;
        scanf(" %c", &c);
        s->arr[--(s->top2)] = c;
        printf("top2: %d\n", s->top2);
}
void popFrom1(TwoStack *s){
	if(isEmpty(s)==1) return;
	printf("Popped element is %c\n", s->arr[(s->top1)--]);
}
void popFrom2(TwoStack *s){
	if(isEmpty(s)==-1) return;
        printf("Popped element is %c\n", s->arr[(s->top2)++]);
}
void display(TwoStack *s){
	if(isEmpty(s)==1) return;
	printf("Elements of stack from 1st stack are:\n");
	for(int i=0; i<=s->top1; i++){
		printf("%c\t", s->arr[i]);
	}
	if(isEmpty(s)==-1) return;
	printf("\nElements of stack from 2st stack are:\n");
        for(int i=MAX-1; i>=s->top2; i--){
                printf("%c\t", s->arr[i]);
        }
	printf("\n");
}
int main(){
	TwoStack s;
	s.top1=-1;
	s.top2=MAX;
	int ch;
	do{
		printf("Enter to 1.Push to 1 2.Pop from 1 3.Push to 2 4.Pop from 2 5.Display 6.Quit\n");
		scanf("%d", &ch);
		switch(ch){
			case 1:  pushTo1(&s);
				 break;
			case 2: popFrom1(&s);
				break;
			case 3:  pushTo2(&s);
                                 break;
                        case 4: popFrom2(&s);
                                break;
			case 5: display(&s);
				break;
			default: ch=6;
		}
	}
	while(ch!=6);
	return 0;
}

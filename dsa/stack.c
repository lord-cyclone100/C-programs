#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct stack{
	int a[MAX];
	int top;
};

void push(struct stack *s,int value){
	if(s->top == MAX-1){
		printf("Stack is full\n");
		return;
	}
	s->top++;
	s->a[s->top]=value;
	return;
}

void pop(struct stack *s){
	if(s->top == -1){
		printf("Stack is empty\n");
		return;
	}
	s->top--;
	return;
}

void display(struct stack *s){
	if(s->top == -1){
		printf("Stack is empty");
		return;
	}
	int i=0;
	while(i<=s->top){
		printf("%d ",s->a[i]);
		i++;
	}
	return;
}

void peek(struct stack *s){
	if(s->top == -1){
		printf("Stack is empty");
		return;
	}
	printf("Top element:%d",s->a[s->top]);
	return;
}

void is_full(struct stack *s){
	if(s->top >= MAX-1){
		printf("Stack is full");
	}
	else{
		printf("Stack is not full");
	}
	return;
}

void is_empty(struct stack *s){
	if(s->top ==-1){
		printf("Stack is empty");
	}
	else{
		printf("Stack is not empty");
	}
	return;
}

int main(void){
	struct stack s;
	s.top=-1;
	int choice,value;
	printf("Menu\n");
	printf("1.)Push\n");
	printf("2.)Pop\n");
	printf("3.)Display\n");
	printf("4.)Peek\n");
	printf("5.)Is full\n");
	printf("6.)Is empty\n");
	printf("0.)Exit\n");
	
	do{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter value:");
				scanf("%d",&value);
				push(&s,value);
				break;
			case 2:
				pop(&s);
				break;
			case 3:
				display(&s);
				break;
			case 4:
				peek(&s);
				break;
			case 5:
				is_full(&s);
				break;
			case 6:
				is_empty(&s);
				break;
			case 0:
				printf("Exiting program...");
            default:
                printf("Please enter correct option");
                break;
		}
	}
	while(choice!=0);
}

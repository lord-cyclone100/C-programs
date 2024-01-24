#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct queue{
	int a[MAX];
	int front;
	int rear;
};

void enqueue(struct queue*q,int value){
	if(q->rear==MAX-1){
		printf("Queue is full");
		return;
	}
	else if(q->front==-1 && q->rear==-1){
		q->front=q->rear=0;
		q->a[q->rear]=value;
		return;
	}
	else{
		q->rear++;
		q->a[q->rear]=value;
		return;
	}
}

void dequeue(struct queue*q){
	if(q->front==-1 && q->rear==-1){
		printf("Queue is empty");
		return;
	}
	else if(q->front==q->rear){
		q->front=-1;
		q->rear=-1;
		return;
	}
	q->front++;
	return;
}

void display(struct queue*q){
	if(q->front==-1 && q->rear==-1){
		printf("Queue is empty");
		return;
	}
	int i;
	for(i=q->front;i<=q->rear;i++){
		printf("%d ",q->a[i]);
	}
	return;
}

void peek(struct queue*q){
	if(q->front==-1 && q->rear==-1){
		printf("Queue is empty");
		return;
	}
	printf("Top element:%d",q->a[q->rear]);
	return;
}

void is_full(struct queue*q){
	if(q->rear==MAX-1){
		printf("Queue is full");
		return;
	}
	else{
		printf("Queue is not full");
		return;
	}
}

void is_empty(struct queue *q){
	if((q->front==q->rear)||(q->front!=-1 && q->rear!=-1)){
		printf("Queue is empty");
		return;
	}
	else{
		printf("Queue is not empty");
		return;
	}
}

int main(void){
	struct queue q;
	q.front=-1;
	q.rear=-1;
	int value,choice;
	printf("Menu\n");
	printf("1.)Enqueue\n");
	printf("2.)Dequeue\n");
	printf("3.)Display\n");
	printf("4.)Peek\n");
	printf("5.)Is full\n");
	printf("6.)Is empty\n");
    printf("0.)Exit program\n");
	
	do{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter value:");
				scanf("%d",&value);
				enqueue(&q,value);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				display(&q);
				break;
			case 4:
				peek(&q);
				break;
			case 5:
				is_full(&q);
				break;
			case 6:
				is_empty(&q);
				break;
			case 0:
				printf("Exiting program...");
		}
	}
	while(choice!=0);
	
	return 0;
}
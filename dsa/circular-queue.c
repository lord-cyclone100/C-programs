#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct queue{
	int a[MAX];
	int front;
	int rear;
};

void enqueue(struct queue *q,int value){
	if((q->rear+1)%MAX==q->front){
		printf("Queue is full");
		return;
	}
	else if(q->front==-1 && q->rear==-1){
		q->front=q->rear=0;
		q->a[q->rear]=value;
		return;
	}
	else{
		q->rear=(q->rear+1)%MAX;
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
	q->front=(q->front+1)%MAX;
	return;
}

void display(struct queue*q){
	if(q->front==-1 && q->rear==-1){
		printf("Queue is empty");
		return;
	}
	int i=q->front;
    while(i!=q->rear){
    	printf("%d ",q->a[i]);
    	i=(i+1)%MAX;
	}
	printf("%d ",q->a[i]);
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
				printf("Exiting program...");
		}
	}
	while(choice!=0);

	return 0;
}
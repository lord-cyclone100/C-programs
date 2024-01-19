#include<stdio.h>
#define MAX 100

void insert_at_beg(int a[],int *size,int value){
	int i;
	if(*size>=MAX){
		printf("Array is full");
		return;
	}
	for(i=*size;i>=0;i--){
		a[i+1]=a[i];
	}
	a[0]=value;
	(*size)++;
	return;
}

void insert_at_pos(int a[],int *size,int value,int index){
	int i;
	if(*size>=MAX){
		printf("Array is full");
		return;
	}
	if(index<0 || index>(*size)){
		printf("Invalid index");
		return;
	}
	for(i=*size;i>=index;i--){
		a[i+1]=a[i];
	}
	a[index]=value;
	(*size)++;
	return;
}

void insert_at_end(int a[],int *size,int value){
	int i;
	if(*size>=MAX){
		printf("Array is full");
		return;
	}
	for(i=0;i<*size;i++){
	}
	a[*size]=value;
	(*size)++;
	return;
}

void delete_from_beg(int a[],int *size){
	int i;
	if(*size==0){
		printf("Array is empty");
		return;
	}
	for(i=0;i<*size;i++){
		a[i]=a[i+1];
	}
	(*size)--;
	return;
}

void delete_from_end(int a[],int *size){
	int i;
	if(*size==0){
		printf("Array is empty");
		return;
	}
	(*size)--;
	return;
}

void print_array(int a[],int size){
	int i;
	if(size == 0){
		printf("Array is empty");
		return;
	}
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	return;
}



int main(void){
	int a[100], size, choice, value, index;
	printf("Initializing the array\n");
	printf("Enter the size of the array:");
	scanf("%d",&size);
	
	printf("Enter array elements:");
	int i;
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printf("The initial array:");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\nMenu\n");
	printf("1.)Insert at beginning\n");
	printf("2.)Insert at end\n");
	printf("3.)Insert at any index\n");
	printf("4.)Delete from beginning\n");
	printf("5.)Delete from end\n");
	printf("6.)Display array\n");
	printf("0.)Exit\n");
	do{
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter value to insert:");
				scanf("%d",&value);
				insert_at_beg(a,&size,value);
				break;
			case 2:
				printf("Enter value to insert:");
				scanf("%d",&value);
				insert_at_end(a,&size,value);
				break;
			case 3:
				printf("Enter value to insert:");
				scanf("%d",&value);
				printf("Enter index:");
				scanf("%d",&index);
				insert_at_pos(a,&size,value,index);
				break;
			case 4:
				delete_from_beg(a,&size);
				break;
			case 5:
				delete_from_end(a,&size);
				break;
			case 6:
				print_array(a,size);
				break;
			case 0:
				printf("Exiting program...");
		}
	}
	while(choice !=0);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
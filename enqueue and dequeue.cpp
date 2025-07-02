#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;
void enqueue(int value){
	if(rear==SIZE-1)
	printf("queue is full\n");
	else{
		if(front==-1)
		front=0;
		rear++;
		queue[rear]=value;
		printf("inserted %d\n",value);
	}
}
void dequeue(){
	if(front==-1||front > rear)
	printf("queue is empty\n");
	else{
		printf("deleted %d\n",queue[front]);
		front++;
	}
}
void display(){
	if(front==-1||front>rear)
	printf("queue is empty\n");
	else{
		printf("queue: ");
		for(int i=front;i<=rear;i++)-
		printf("%d\n",queue[i]);
		printf("\n");
	}
}
int main(){
	enqueue(87);
	enqueue(34);
	enqueue(54);
	display();
	
	dequeue();
	display();
	
	enqueue(43);
	enqueue(56);
	enqueue(23);
	display();
	
	return 0;
}
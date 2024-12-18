#include <stdio.h>
#include <stdlib.h>
int front=-1,rear=-1;
void display(int queue[],int size){
int i=front;
if(front==-1 && rear==1){
printf("\n queue is empty");
}
else{
printf("\n queue elements are :");
while(1){
printf(" \n %d",queue[i]);
if(rear==i)
break;
i=(i+1)%size;
}
}
}
void enque(int queue[],int size,int value){
if((rear+1)%size==front){
printf("\n queue is full");
}
else{
if(front==-1)
front=0;
rear=(rear+1)%size;
queue[rear]=value;
printf("enqueued %d \n",value);
}
}
void deque(int queue[],int size){
if(front==-1){
printf("queue is empty");
}
else{
printf("dequeued %d \n",queue[front]);
if(front==rear){
front=rear=-1;
}
else{
front=(front+1)%size;
}
}
}
void search(int queue[], int size) {
    int s, flag = 0;
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("\nEnter the value to be searched: ");
        scanf("%d", &s);
        
        int i = front;
        while (i != rear) {
            if (s == queue[i]) {
                flag = 1;
                printf("Element found at position %d\n", i);
                break;
            }
            i = (i + 1) % size; // Move to the next index, wrap around if needed
        }

        // Check the rear element, since the while loop stops before it
        if (flag == 0 && queue[rear] == s) {
            flag = 1;
            printf("Element found at position %d\n", rear);
        }

        if (flag == 0) {
            printf("Element not found\n");
        }
    }
}

void main() {
int size;
int ch,value;
printf("enter the size of queue:");
scanf("%d",&size);
int queue[size];
do{
printf("\n 1.enqueue \n 2.dequeue \n 3.display \n 4.search \n 5.exit");
printf("\n enter your choice:");
scanf("%d",&ch);
switch(ch){
case 1:
printf("enter the value to be inserted:");
scanf("%d",&value);
enque(queue,size,value);
display(queue,size);
break;
case 2:
deque(queue,size);

break;
case 3:
display(queue,size);
break;
case 4:
search(queue,size);
break;
case 5:
printf("exit from the program");
break;
default:
printf("invalid choice");
}
}while(ch!=5);
}

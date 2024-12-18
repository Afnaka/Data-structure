
#include<stdio.h>
#include<stdlib.h>
struct node{ 
        int data;
        struct node*next;

};
struct node*top=NULL;
void display(){
         struct node*temp=top;
	if(top==NULL)
	printf("stack underflow");
        while(temp !=NULL){
        printf("%d \n",temp->data);
        temp=temp->next;
}
}

void push( int data){
        struct node*newnode=(struct node*) malloc(sizeof(struct node));
	
        newnode->data=data;
        newnode->next=top;
        top=newnode;

	display();
}
 int  pop(){
	struct node*temp=top;
	if(temp==NULL){
	printf("stack is empty");
	return 0;
}

	temp=top;
	top=temp->next;
	free(temp);
	display();

}
 int  search(int s){
	int f=0;
	struct node*temp=top;
	while(temp!=NULL){
		if( temp->data==s){
		f=1;
		printf("element found");
	}
	temp=temp->next;
}
if(f==0)
	printf("element not found");

}

void main(){
int ch,data,s;
do{
	printf("\n 1. push operation \n 2.pop operation \n 3.search \n 4. display \n 5.exit");
	printf("\n enter your choice");
	scanf("%d",&ch);
	switch(ch){
	case 1:
		printf("enter the data to be entered");
		scanf("%d",&data);
		push(data);
		break;
	case 2:
		pop();
		break;
	case 3:
		printf("enter the value to be search");
		scanf("%d",&s);
		search(s);
		break;
	 case 4:
                display();
                break;
	case 5:
		printf("exit from the program");
		break;
	default:
	printf("invalid");

}

}while(ch!=5);
}

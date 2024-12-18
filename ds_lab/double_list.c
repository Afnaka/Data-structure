#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node*prev;
	int data;
	struct node*next;

};
struct node*head=NULL;
void display(){
	struct node*temp=head;
	if(head==NULL){
	printf("\n list empty");
	}
	while(temp!=NULL){
	printf("%d \n",temp->data);
	temp=temp->next;
}



}
void insert_beg(int data){
	struct node*newnode=(struct node*) malloc(sizeof(struct node));
	if(head==NULL){
	newnode->data=data;
	newnode->next=head;
	newnode->prev=NULL;
	head=newnode;
	}
	else{
	newnode->data=data;
	newnode->prev=NULL;
        newnode->next=head;
        head->prev=newnode;
        head=newnode;

	}
	display();

}
void insert_end(int data){
	if(head==NULL){
	 insert_beg(data);


}
	else{
	struct node*newnode=(struct node*) malloc(sizeof(struct node));
         struct node*temp=head;

	newnode->data=data;
	temp=head;
	while(temp->next!=NULL){
	temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next=NULL;
	display();
}

}

void insert_pos(int p,int data){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (p == 1) {
        insert_beg(data);
        return;
    }

    struct node* temp = head;
    int i = 1;

    while (i < p - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition not found\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

     if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    display();
}





void search(int s){
	int f=0;
        struct node*temp=head;

        while(temp!=NULL){
                if(temp->data==s){
                        f=1;
                        printf("element found\n");
                }
        temp=temp->next;
}
        if(f!=1)
        printf("element not found\n");


}
 void delete_beg(){
	struct node*temp=head;
	if(head==NULL)
	printf("list is empty");
	else{
	temp=head;
	head=head->next;
	head->prev=NULL;
	free(temp);
}
display();
}
void delete_end(){
	struct node*temp=head;
	if(head==NULL)
	printf("list is empty");
	else{
	temp=head;
	while(temp->next!=NULL){
	temp=temp->next;
}
	temp->prev->next=NULL;
	free(temp);

}
display();


}
void del_pos(int p) {
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    if (p == 1) {
        delete_beg();
        return;
 }

    struct node* temp = head;
    int i = 1;
    while (i < p && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition not found\n");
        return;
    }

    printf("%d is deleted\n", temp->data);

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;


    free(temp);
    display();
}




void main(){
	int data,ch,p,s;
	do{
	printf("\n 1.insert at begning \n 2.insert at end \n 3.insert at any position \n 4.search \n 5.delete from begning \n 6.delete from end \n 7.delete from any position \n 8.display \n 9. exit");
	printf("\n enter your choice");
	scanf("%d",&ch);
	switch(ch){
	case 1:
	printf("\n enter the data to be inserted");
	scanf("%d",&data);
	insert_beg(data);
	break;
	case 2:
	printf("\n enteer the data to be inserted");
	scanf("%d",&data);
	insert_end(data);
	break;
	case 3:
	printf("enter the position to be inserted");
	scanf("%d",&p);
	printf("enter the data to be inserted");
	scanf("%d",&data);
	insert_pos(p,data);
	break;
	case 4:

	if(head==NULL){
        printf("list is empty  ");

        }
        else{
        printf("enter the value to be search  ");
        scanf("%d",&s);
        search(s);
        break;
        }
	case 5:
	delete_beg();
	break;
	case 6:
	delete_end();
	break;
	case 7:
	if(head==NULL){
        printf("list is empty");

        }
 
else{
        printf("enter the position to be deleted  ");
        scanf("%d",&p);
        del_pos(p);
	break;
}
	case 8:
	display();
	break;
	
	case 9:
	
        printf("\n exist from the program ");
        break;

       

}

}while(ch!=9);


}


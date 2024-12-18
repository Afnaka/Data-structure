#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node*left;
	struct node*right;
};
struct node*tree=NULL;

void insertion(int value){
	struct node *node,*parent;
	struct node*ptr=(struct node*) malloc(sizeof(struct node)) ;
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;

	if(tree==NULL){
	tree=ptr;
	ptr->left=NULL;
	ptr->right=NULL;
	}
	else{
	parent=NULL;
	node=tree;
	while(node!=NULL){
	parent=node;
	if( value)
}
}
}
void main(){
int value,ch;
do{
	printf("\n 1.insert \n 2.deletion \n 3.search \n 4.traversal \n 5.exit");
	printf("enter your choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1:
	printf("enter the value ");
	scanf("%d",&value);
	insertion(value);
	break;
	case 2:
	traversal();
	break;

}
}while(ch!=6)

}

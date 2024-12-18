#include <stdio.h>
#define MAX_SIZE 32
const int universal_set=(1< MAX_SIZE)-1;
void display(int set){
	printf("{");
	for(int i=0;i<MAX_SIZE;i++){
	printf("%d",i);
}
	printf("}");

}
void add(int*set,int element){
	if(element>=0 && element <MAX_SIZE){
	 *set |= (1 << element);
}
	else{
	printf("invalid");
	}
}

void main(){
	int set1,set2,n1,n2,element,operation ,data;
	printf("enter the size of set1:");
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		printf("enter the elements %d:",i);
		scanf("%d",&element);
		add(&set1,element);
	
	}
	printf("enter the size of set2:");
	scanf("%d",&n2);
	for(int i=0;i<n2;i++){
		printf("enter the elements %d:",i);
		scanf("%d",&element);
		add(&set2,element);
	}
	printf("\n set1:");
	display(set1);
	printf("\n set2:");
	display(set2);
	do{
	printf("\n 1.Add element to set1 \n 2.remove element from set1 \n 3.union of set1 and set2 \n 4.intersection of set1 and set2 \n 5.differnces of set1 and set2 \n 6.complement of set1 \n 7.exit");
	printf("\n enter your choice:");
	scanf("%d",&operation);
	switch(operation){
	case 1:
	printf("enter the element to be added in set1:");
	scanf("%d",&data);
	add(&set1,data);
	printf("modified set :");
	display(set1);
	break;


		}
	}while(operation!=8);

}

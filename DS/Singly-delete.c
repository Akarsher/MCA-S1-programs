
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;

void create(int n){
	struct node *newNode, *temp;
    	int data, i;
    	
	head = (struct node *)malloc(sizeof(struct node));   
		 	
    	printf("Enter the data of 1st node : ");
    	scanf("%d", &data);
    	
    	head->data = data;
    	head->next = NULL; 
    	
    	temp = head;
    	for(i=2; i<=n; i++)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		
		printf("Enter the data of node %d: ", i);
		scanf("%d", &data);

		newNode->data = data; 
		newNode->next = NULL;  

		temp->next = newNode; 
		temp = temp->next;   
	}
}
void traverseList()
{
    struct node *temp;

   
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data); 
        temp = temp->next;                 
    }printf("NULL\n");
}
void deleteFront(){
	struct node *ptr;
	if(head == NULL){
		printf("Underflow\n");
	}else{
		ptr = head;
		head = head->next;
		printf("Node Deleted : %d\n",ptr->data);
		free(ptr);
	}
}
void deleteLast(){
	struct node *ptr,*ptr1;
	if(head == NULL){
		printf("Underflow\n");
	}else{
		if(head->next == NULL){
			printf("Node Deleted : %d\n",head->data);
			head = NULL;
			free(head);
		}else{
			ptr = head;
			while(ptr->next != NULL){
				ptr1 = ptr;
				ptr = ptr->next;
			}
			ptr1->next = NULL;
			printf("Node Deleted : %d\n",ptr->data);
			free(ptr);
		}
	}
}
void deleteSpec(int key){
	struct node *ptr,*ptr1;
	int flag=0;
	if(head == NULL){
		printf("Underflow\n");
	}else{
		if(head->data == key){
			printf("Node Deleted : %d\n",head->data);
			head = head->next;
		}else{
			ptr1 = head;
			ptr = head->next;
			while(ptr != NULL){
				if(ptr->data == key){
					ptr1->next = ptr->next;
					printf("Node Deleted : %d\n",ptr->data);
					free(ptr);ptr=NULL;
					flag = 1;
				}else{
					ptr1 = ptr;
					ptr = ptr->next;
				}
			}
			if(flag == 0){
				printf("Node does not exists\n");
			}
		}
	}
}
void main(){
	int op,n,key;
	printf("1. Create\n2. Delete from front\n3. Delete from end\n4. Delete from location\n5. Traverse\n6. Exit\n");
	do{
		printf("\nEnter Option : ");
		scanf("%d",&op);
	
		switch(op){
			case 1: printf("Enter Limit : ");
    				scanf("%d", &n);
				create(n);
				break;
			
			case 2: deleteFront();
				break;
			
			case 3: deleteLast();
				break;
			
			case 4: printf("Enter Key Element : ");
				scanf("%d",&key);
				deleteSpec(key);
				break;
			
			case 5: traverseList();
				break;
			default: break;
		}
	}while(op!=6);	
}

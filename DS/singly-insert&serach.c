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

void insertFirst(int item){

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL){
		printf("List is Empty.\n");
	}
	else{
		temp->data = item;
		if(head == NULL){
			temp->next = NULL;
			head = temp;
		}
		else{
			temp->next = head;
			head = temp;
		}
		printf("Node Inserted at Begining.\n");
	}
	
}

void insertEnd(int item){
	struct node *ptr;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL){
		printf("List is Empty.\n");
	}
	else{
		temp->data=item;
		temp->next=NULL;
		if(head==NULL){
			head=temp;
		}else{
			ptr=head;
			while(ptr->next != NULL){
				ptr = ptr->next;
			}
			ptr->next=temp;
		}
		printf("Inserted at the end\n");
	}
}

void insertSpeci(int key,int item){
	struct node *ptr;
	int flag = 0;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL){
		printf("List is Empty.\n");
	}
	else{
		temp->data=item;
		if(head == NULL){
			temp->next = NULL;
			head = temp;
			printf("Inserted as head\n");
		}else{
			ptr = head;
			while(ptr != NULL){
				if(ptr->data == key){
					temp->next = ptr->next;
					ptr->next = temp;
					printf("Node inserted\n");
					flag = 1;
				}
				ptr = ptr->next;
			}
			if(flag != 1){
				printf("Key not found !\n");
			}
		}
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

int search(int item){
	struct node *ptr = head;
	int c=1;
	if(head->data == item){
		return 1;
	}
	while(ptr != NULL){
		if(ptr->data == item){
			return c;
		}else{
			c++;
			ptr =ptr->next;
		}
	}return 0;
}

void main(){
	int o,n,item,key,s;
	printf("1. Create\n2. Insert at Front\n3. Insert at End\n4. Insert at a Position\n5. Traverse\n6. Search\n7. Exit\n");
	do{
		printf("Enter Option : ");
		scanf("%d",&o);
		switch(o){
			case 1: printf("Enter Limit : ");
    				scanf("%d", &n);
				create(n);
				break;
				
			case 2: printf("Enter Element : ");
				scanf("%d",&item);
				insertFirst(item);
				break;
			
			case 3: printf("Enter Element : ");
				scanf("%d",&item);
				insertEnd(item);
				break;
				
			case 4: printf("Enter Element to Insert : ");
				scanf("%d",&item);
				printf("Enter Key Element : ");
				scanf("%d",&key);
				insertSpeci(key,item);
				break;
				
			case 5: traverseList();
				break;
			
			case 6: printf("Enter Element : ");
				scanf("%d",&item);
				s = search(item);
				if(s != 0){
					printf("Element Found at %d\n",s);
				}else{
					printf("Element is not in list\n");
				}
				break;
				
			default: break;
		}
	}while(o!=7);
}

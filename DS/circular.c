#include <stdio.h>
#include<stdlib.h>

#define MAX 5

int rear=-1;
int front=-1;
int arr[10],i;

 void insert();
 void display();
 void delete();
 
 
 int main()
 {
  int ch;
  while(1){
  printf("\n1.Insert\n2.display\n3.deletion \n");
  printf("Enter your choice:");
  scanf("%d",&ch);
  
  switch(ch)
  {
        case 1:
            insert(); 
            break;
        case 2:
            display();
            break;    
        case 3:
            delete();
            break;
        default:
            printf("invalid entry, Exiting program ...");
              return 0;
   }
 }
}

 void insert(){
	int item;
	if((rear+1)%MAX==front)  
	{
	  printf("Queue is Full,cannot insert values.\n");
	}
	else{
	   printf("Enter the value to be inserted: ");
	   scanf("%d",&item);
	   if(rear==-1 && front==-1)
	   {  
	     rear =0;
	     front =0;
	   }
	   else{
	      rear=(rear+1)%MAX;
	      }
	   arr[rear]=item;
	   printf("%d inserted successfully.\n",item);  
	   }
	 }
 void delete(){
 	int item;
 	if(front==-1)
 	  printf("Queue is Empty ,cannot delete any values\n");    
        else{
           if(rear==front)
           {
             item=arr[front];
             rear=-1;
             front=-1;
           }
           else{
             item =arr[front];
             front=(front+1)%MAX;
             }
           printf("%d deleted successfully.\n",item);
           }
         }    
 void display(){
 	int i;
 	if(front==-1)
 	   printf("Queue is Empty.");
 	else{
 	   i=front;
 	   printf("Queue Elements Are:\n");
 	   while(1){
 	        printf("%d ->",arr[i]);
 	        if(i==rear)
 	          break;
 	        i=(i+1)%MAX;
 	      }
 	   printf("\n");
 	}
 }	          
 	
 	          
            
            
            

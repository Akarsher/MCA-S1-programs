#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
	};
struct node* top = NULL;

void push(int item) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL) {
	   printf("Stack Overflow! Unable to push %d\n", item);
	   return;
	}
	newNode->data = item;
	newNode->next = top;
	top = newNode;
	printf("%d pushed onto the stack\n", item);
	}

void pop() {
	if (top == NULL) {
	    printf("Stack Underflow! Cannot pop\n");
	    return;
	}
	struct node* temp = top;
	int poppedItem = top->data;
	top = top->next;
	free(temp);
	printf("%d popped from the stack\n", poppedItem);
	}

void traverseStack() {
	if (top == NULL) {
	   printf("Stack is empty\n");
	   return;
	}
	printf("Stack elements are:\n");
	struct node* temp = top;
	while (temp != NULL) {
	printf("%d -> ", temp->data);
	temp = temp->next;
	}
	printf("NULL\n");
	}

int main() {
	int choice, item;
	printf("Stack Operations :\n1. Push\n2. Pop\n3. Traverse\n4. Exit\n");
	do {
	printf("\nEnter your choice: ");
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			printf("Enter the element to push: ");
			scanf("%d", &item);
			push(item);
			break;
		case 2:
			pop();
			break;
		case 3:
			traverseStack();
			break;
		case 4:
			printf("Exiting program\n");
			break;
		default:
			printf("Invalid choice!.\n");
			}
		} while (choice != 4);
			return 0;
		}

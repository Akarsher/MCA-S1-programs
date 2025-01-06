#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void push(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Memory allocation failed!\n");
		return;
		}
	newNode->data = value;
	newNode->next = NULL;
	if (front == NULL) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
		}
	printf("%d added to the queue.\n", value);
	}
	
void pop() {
	if (front == NULL) {
		printf("Queue is already empty!\n");
		return;
		}
	struct Node* temp = front;
	front = front->next;
	printf("%d removed from the queue.\n", temp->data);
	free(temp);
	if (front == NULL) {
		rear = NULL;
		}
	}
	
void traverse() {
	if (front == NULL) {
		printf("Queue is empty!\n");
		return;
		}
	struct Node* temp = front;
	printf("Queue elements: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
		}
	printf("\n");
	}
	
int main() {
	int ch, value;
	while (1) {
		printf("1. Enqueue\t2. Dequeue\t3. Traverse\t4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &ch);
	switch (ch) {
		case 1:
			printf("Enter value to push: ");
			scanf("%d", &value);
			push(value);
			break;
		case 2:
			pop();
			break;
		case 3:
			traverse();
			break;
		case 4:
			printf("Exiting program.\n");
			exit(0);
		default:
			printf("Invalid choice.\n");
			}
		}
		return 0;
}

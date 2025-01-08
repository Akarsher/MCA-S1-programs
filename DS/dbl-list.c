#include<stdio.h>
#include<stdlib.h>

int count = 0;
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *beg = NULL, *end = NULL;

void creation();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void display();


int main() {
    int choice;
    while (1) {
        printf("\n1.creation\n2.insert beginning \n3.insert end \n4.insert position \n5.delete beginning \n6.delete end \n7.delete position \n8.search \n9.display \n10.exit \n");
        printf("\n enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                creation();
                break;
            case 2:
                insert_begin();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_pos();
                break;
            case 5:
                delete_begin();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_pos();
                break;
            case 8:
                search();
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);

            default:
                printf("\n invalid choice");
        }
    }
}

void creation() {
    int n, item, i = 0;
    struct node *ptr, *temp;
    if (count == 0) {
        printf("\nEnter the number of nodes to be inserted: ");
        scanf("%d", &n);
        if (n == 0) {
            printf("\nNo creation");
        } else {
            while (i < n) {
                printf("\nEnter value to insert: ");
                scanf("%d", &item);
                ptr = (struct node*)malloc(sizeof(struct node));
                ptr->data = item;
                ptr->next = NULL;
                if (count == 0) {
                    beg = ptr;
                    beg->prev = NULL;
                    end = ptr;
                    count = 1;
                    i++;
                    temp = beg;
                } else {
                    temp->next = ptr;
                    ptr->prev = temp;
                    end = ptr;
                    temp = temp->next;
                    i++;
                }
            }
            printf("\nList is created\n");
        }
    } else {
        printf("\nList already created\n");
    }
}

void insert_begin() {
    int data;
    struct node *ptr;

    printf("\nEnter value to insert: ");
    scanf("%d", &data);

    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    if (beg == NULL) {
        beg = ptr;
        beg->next = NULL;
        beg->prev = NULL;
        end = ptr;
    } else {
        ptr->prev = NULL;
        ptr->next = beg;
        beg->prev = ptr;
        beg = ptr;
    }
    count++;
}

void insert_end() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;
    if (end == NULL) {
        ptr->next = NULL;
        ptr->prev = NULL;
        beg = ptr;
        end = ptr;
    } else {
        temp = end;
        ptr->prev = temp;
        ptr->next = NULL;
        temp->next = ptr;
        end = ptr;
    }
    count++;
    printf("\nNode inserted successfully ");
}

void insert_pos() {
    int item, pos, i;
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if (pos == 1) {
        insert_begin();
    } else {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        temp = beg;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == NULL) {
                printf("\nInsertion not possible");
                return;
            }
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = ptr;
        }
        temp->next = ptr;
        if (ptr->next == NULL) {
            end = ptr;
        }
        count++;
        printf("\nNode inserted\n");
    }
}

void delete_begin() {
    struct node *temp;
    if (beg == NULL) {
        printf("\nList is empty");
    } else {
        temp = beg;
        beg = beg->next;
        if (beg != NULL) {
            beg->prev = NULL;
        } else {
            end = NULL;
        }
        free(temp);
        count--;
        printf("\nNode deleted");
    }
}

void delete_end() {
    struct node *temp;
    if (end == NULL) {
        printf("\nList is empty");
    } else {
        temp = end;
        end = end->prev;
        if (end != NULL) {
            end->next = NULL;
        } else {
            beg = NULL;
        }
        free(temp);
        count--;
        printf("\nNode deleted");
    }
}

void delete_pos() {
    struct node *ptr, *temp;
    int pos, i;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if (beg == NULL) {
        printf("\nDeletion not possible");
        return;
    } else if (pos == 1) {
        delete_begin();
    } else {
        temp = beg;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == NULL || temp->next == NULL) {
                printf("\nDeletion not possible");
                return;
            }
        }
        ptr = temp->next;
        temp->next = ptr->next;
        if (ptr->next != NULL) {
            ptr->next->prev = temp;
        }
        if (ptr == end) {
            end = temp;
        }
        free(ptr);
        count--;
        printf("\nNode deleted");
    }
}

void display() {
    struct node *ptr;
    ptr = beg;
    if (ptr == NULL) {
        printf("\nList is empty");
    } else {
        printf("\nList: ");
        while (ptr != NULL) {
            printf("\n%d", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void search() {
    struct node *ptr;
    int item, count = 0, i = 0;
    ptr = beg;
    if (ptr == NULL) {
        printf("\nEmpty list");
    } else {
        printf("\nEnter element to be searched: ");
        scanf("%d", &item);
        while (ptr != NULL) {
            if (ptr->data == item) {
                printf("\n%d found at position %d", ptr->data, i + 1);
                count = 1;
                break;
            }
            ptr = ptr->next;
            i++;
        }
        if (count == 0) {
            printf("\nElement not found");
        }
    }
}



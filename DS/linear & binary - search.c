#include <stdio.h>

void linear(int a[], int n);  
void binary(int a[], int n, int target); 
void sortArray(int a[], int n);

int main() {
int a[10], n, i, ch;
int j,temp;
printf("Enter the limit: ");
scanf("%d", &n);
printf("Enter the array elements: ");
 for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
 }

printf("Enter choice:\n");
printf("1. Linear search\n");
printf("2. Binary search\n");
scanf("%d", &ch);

 switch (ch) {
     case 1: 
        linear(a, n); 
        break;
     case 2:
        sortArray(a,n);
        printf("Sorted array: ");
        for (i = 0; i < n; i++)
        printf("%d ", a[i]);
        printf("\nEnter the element to search: ");
        int t;
        scanf("%d", &t);
        
        binary(a, n, t); 
        break;
    default:
         printf("Exit\n");
         break;
    }
    return 0;
}


void linear(int a[], int n) {
    int t,i;
    printf("Enter the element to search: ");
    scanf("%d", &t);

    for (i=0;i<n;i++) {
        if (a[i] == t) {
            printf("Element found at %d\n",i);
            return; 
        }
       }

printf("Element not found\n");
}

void sortArray(int a[], int n) {
int temp;
        for (int i = 0; i < n - 1; i++) {
          for (int j = 0; j < n - i - 1; j++) {
           if (a[j] > a[j + 1]) {
            temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
           }
          }
  }
}

void binary(int a[], int n, int t) {
    

    int left=0,right=n-1;
    while (left<=right) {
        int mid=left+(right-left)/2;

        if (a[mid] == t) {
            printf("Element found at %d\n", mid);
            return;
        }

        if (a[mid]<t)
            left = mid+1;
        else
            right = mid-1;
    }

    printf("Element not found\n");
}


#include <stdio.h>
#include <stdbool.h>
int a[11] = {0}, b[11] = {0}, res[11] = {0};
int U[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void display(int bs[]) {
for (int i = 1; i < 11; i++) {
if (bs[i] == 1) {
printf("%d\t", i);
}
}
printf("\n");
}
void input(int bs[], int n) {
int x;
printf("Enter the elements: ");
for (int i = 0; i < n; i++) {
scanf("%d", &x);
if (x >= 1 && x <= 10) {
bs[x] = 1;
} else {
printf("Invalid element %d..\n", x);
i--;
}
}
}
void set_union() {
for (int i = 1; i < 11; i++) {
res[i] = a[i] | b[i];
}
printf("\nUnion Set: ");
display(res);
}
void set_intersection() {
for (int i = 1; i < 11; i++) {
res[i] = a[i] & b[i];
}
printf("\nIntersection Set: ");
display(res);
}
void set_difference() {
for (int i = 1; i < 11; i++) {
res[i] = a[i] & ~b[i];
}
printf("\nDifference Set (A - B): ");
display(res);
}
int main() {
int n, m, choice;
printf("Enter the number of elements in set A: ");
scanf("%d", &n);
input(a, n);
printf("Enter the number of elements in set B: ");
scanf("%d", &m);
input(b, m);
printf("\nMenu:\n");
printf("1. Display Set A and B\n2. Union of A and B\n3. Intersection of A and B\n4. Difference of A and B\n5. Exit\n");
do {
  printf("Enter your choice: ");
  scanf("%d", &choice);
switch (choice) {
case 1:
  printf("Set A: ");
  display(a);
  printf("Set B: ");
  display(b);
  break;
case 2:
  set_union();
  break;
case 3:
  set_intersection();
  break;
case 4:
  set_difference();
  break;
case 5:
  printf("Exiting...\n");
  break;
default:
  printf("Invalid choice\n");
}
} while (choice != 5);
return 0;
}

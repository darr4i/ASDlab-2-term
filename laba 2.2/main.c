#include <stdio.h>
#include <stdlib.h>
struct Node {
 int value;
 struct Node *next;
};
void addNode(struct Node **head, int value) {
 struct Node *newNode = malloc(sizeof(struct Node));
 newNode->value = value;
 newNode->next = NULL;
 if (*head == NULL) {
 *head = newNode;
 } else {
 struct Node *current = *head;
 while (current->next != NULL) {
 current = current->next;
 }
 current->next = newNode;
 }
}
void deleteNode(struct Node **head, int value) {
 if (*head == NULL) {
 return;
 }
 struct Node *current = *head;
 if (current->value == value) {
 *head = current->next;
 free(current);
 return;
 }
 while (current->next != NULL && current->next->value != value) {
 current = current->next;
 }
 if (current->next == NULL) {
 return;
 }
 struct Node *temp = current->next;
 current->next = temp->next;
 free(temp);
}
void freeList(struct Node **head) {
 struct Node *current = *head;
 while (current != NULL) {
 struct Node *temp = current;
 current = current->next;
 free(temp);
 }
 *head = NULL;
}
int main(){
int n;
 printf("Enter the value of n: ");
 scanf("%d", &n);
 if (n < 20 || n % 20 != 0) {
 printf("Error: Invalid number \n");
 return 1;
 }
 int *arr = malloc(n * sizeof(int));
 struct Node *head = NULL;
 printf("Enter the elements of the linked list: ");
 for (int i = 0; i < n; i++) {
 int value;
 scanf("%d", &value);
 addNode(&head, value);
 arr[i] = value;
 }
 int temp, pos;
 for (int i = 0; i < n; i += 20) {
 for (int j = 0; j < 10; j++) {
 pos = j + i;
 temp = arr[pos];
 arr[pos] = arr[i + 9 - j];
 arr[i + 9 - j] = temp;
 }
 for (int j = 10; j < 15; j++) {
 pos = i + j;
 temp = arr[pos];
 arr[pos] = arr[i + 19 - j];
 arr[i + 19 - j] = temp;
 }
 }
 printf("Re-arranged array: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
 freeList(&head);
 free(arr);
return 0;
}

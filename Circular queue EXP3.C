#include <stdio.h>
#define Maxsize 100
int queue[Maxsize];
int front= -1;
int rear= -1;
int maxsize = Maxsize; 

void insert(int item, int queue[]) {
    if ((rear + 1) % maxsize == front) {
        printf("Queue overflow!\n");
        return;
    }

    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % maxsize;
    }

    queue[rear] = item;
    printf("Inserted %d successfully at index %d.\n", item, rear);
}
void delete(int item, int queue[]){
      if ( rear ==-1 && front ==-1){
        printf("Queue is empty");
    }
    printf("Deleted element: %d from index %d\n", queue[front], front);
     if (front==rear){
        front=-1;
        rear=-1;
    }
    else {
        front = (front + 1) % maxsize;
    }
}


void display(int item, int queue[]) {
    int i;
    if (front == -1 && rear == -1) {
        printf("\nCircular queue is empty\n");
        return;
    }

    printf("\nQueue elements: ");

    if (front <= rear) {
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
   
    else {
        for (i = front; i < maxsize; i++) {
            printf("%d ", queue[i]);
        }
       
        for (i = 0; i <= rear; i++) { 
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}


int main() {
    int choice;
    int x;
    int queue[Maxsize];

    printf("enter the maximum size of the array(Maximum can be %d):- ", Maxsize);
    scanf("%d", &maxsize);

    if (maxsize > Maxsize || maxsize <= 0) {
        printf("invalid size. Setting capacity to %d.\n", Maxsize);
        maxsize = Maxsize;
    }

    do {
        printf("\nenter 1 to insert an element\n");
        printf("enter 2 to delete an element\n");
        printf("enter 3 to display an element\n");
        printf("enter 4 to exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("enter the element you want to insert: ");
                scanf("%d", &x);
                insert(x, queue);
                break;

            case 2:
                delete(x, queue);
                break;

            case 3:
                display(x, queue);
                break;

            case 4:
                printf("exiting the program..\n");
                break;

            default:
                printf("invalid option choose a number within the range.\n");
        }

    } while (choice != 4);

    return 0;
}

#include <stdio.h>
#define MAX 100  

int queue[MAX];
int front = -1, rear = -1;
int size; 

void enqueue(int value) {
    if ((rear + 1) % size == front) {
        printf("Queue is FULL!\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        queue[rear] = value;
        printf("%d inserted into queue.\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
    } else {
        int val = queue[front];
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % size;
        }
        printf("%d deleted from queue.\n", val);
    }
}


void display() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % size;
    }
    printf("\n");
}


void peek() {
    if (front == -1)
        printf("Queue is EMPTY!\n");
    else
        printf("Front element: %d\n", queue[front]);
}

int main() {
    int choice, value;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

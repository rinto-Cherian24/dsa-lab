#include <stdio.h>

int deque[100], front = -1, rear = -1, size;

void insertFront(int value) {
    if((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Queue Overflow! Cannot insert.\n");
    } 
    else {
        if(front == -1) {   // Empty queue
            front = rear = 0;
        }
        else if(front == 0) {
            front = size - 1;   // Wrap to last index
        }
        else {
            front--;     // Normal movement
        }
        deque[front] = value;
        printf("%d inserted at front\n", value);
    }
}

void insertRear(int value) {
    if((front == 0 && rear == size - 1) || (front == rear + 1)) {
        printf("Queue Overflow! Cannot insert.\n");
    }
    else {
        if(front == -1) {   // Empty queue
            front = rear = 0;
        }
        else if(rear == size - 1) {
            rear = 0;     // Wrap around
        }
        else {
            rear++;       // Normal movement
        }
        deque[rear] = value;
        printf("%d inserted at rear\n", value);
    }
}

void deleteFront() {
    if(front == -1) {
        printf("Queue Underflow! Cannot delete.\n");
    }
    else {
        printf("%d deleted from front\n", deque[front]);
        if(front == rear) {   // Only one element left
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0;     // Circular shift
        }
        else {
            front++;
        }
    }
}

void deleteRear() {
    if(rear == -1) {
        printf("Queue Underflow! Cannot delete.\n");
    }
    else {
        printf("%d deleted from rear\n", deque[rear]);
        if(front == rear) {     // Only one element left
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size - 1;    // Wrap around
        }
        else {
            rear--;
        }
    }
}

void display() {
    if(front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while(i != rear) {
        printf("%d ", deque[i]);
        i = (i + 1) % size;   // Move circularly
    }
    printf("%d\n", deque[rear]);
}

int main() {
    int choice, value;

    printf("Enter size of deque: ");
    scanf("%d", &size);

    while (1) {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

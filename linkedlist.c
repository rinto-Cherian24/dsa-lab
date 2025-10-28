#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *link;
}Node;

Node *head = NULL;

Node *newnode(int value){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->link = NULL;
    return p;
}

void insertBegin(int value){
    Node *new = newnode(value);
    new->link = head;
    head = new;
    printf("Inserted at the beginning\n");
}

void insertEnd(int value){
    Node *new = newnode(value);
    if(head == NULL){
        head = new;
    }
    else{
        Node *ptr = head;
        while(ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = new;
    }
    printf("Inserted at end\n");
}

void insertPos(int value, int key){
    if(head == NULL){
        printf("List is empty. Key cannot be found.\n");
        return;
    }
    Node *new = newnode(value);
    Node *ptr = head;

    while(ptr != NULL && ptr->data != key)
        ptr = ptr->link;

    if(ptr == NULL){
        printf("Key not found.\n");
    }
    else{
        new->link = ptr->link;
        ptr->link = new;
        printf("Inserted after %d\n", key);
    }
}

void deletePos(int value){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    Node *temp = head, *prev = NULL;

    while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->link;   // ✅ corrected here
    }

    if(temp == NULL){
        printf("Element not found.\n");
        return;
    }

    if(temp == head){
        head = head->link;   // ✅ corrected here
    }
    else{
        prev->link = temp->link;  // ✅ corrected here
    }

    free(temp);
    printf("%d deleted from the list\n", value);
}

void display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    Node *ptr = head;
    printf("List: ");
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

int main(){
    int choice, value, key;
    while(1){
        printf("\n----Single Linked List----\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert after key\n4. Delete\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter key: ");
                scanf("%d", &key);
                insertPos(value, key);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deletePos(value);
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

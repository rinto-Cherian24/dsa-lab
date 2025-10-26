#include <stdio.h>
int queue[100];
int front = -1;
int rear = -1;
int maxsize;

void enqueue(int value){
    if(rear == maxsize -1){
        printf("Queue overflow. Cannot insert.\n");
    }
    else{
        if(front ==-1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d enqueud to the queue\n",value);
    }
}
void dequeue(){
    if( front == -1 || front > rear ){
        printf("Queue underflow. Cannot delete.\n");    
    } 
    else{
        printf("%d dequeued from the queue\n",queue[front]);
        front++;
        if(front > rear)
            front = rear = -1;
    }
}
void peek(){
    if(front == -1){
        printf("Queue is empty.\n");
    }
    else{
        printf("Front element is %d\n",queue[front]);
    }
}
void display(){
    if(front == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are:\n");
        for(int i = front; i<=rear; i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
int main(){
   printf("Enter the size of the queue: ");
    scanf("%d",&maxsize);
    int choice,value;

    if(maxsize > 100 || maxsize <=0){
        printf("Invalid input.Exiting....\n");
        return 0;
    }

    while(1){
        printf("Enter your choice:\n1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted into the queue:\n");
                scanf("%d",&value);
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
                printf("Exiting...");
                return 0;
            default:
                printf("Invalid choice. Enter again.\n");
        }
    }

}
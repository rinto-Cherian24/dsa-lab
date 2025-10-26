#include <stdio.h>
int stack[100];
int top = -1;
int maxsize;

void push(int value){
    if(top == maxsize -1)
        printf("Stack Overflow. Cannot push.\n");
    else{
        top++;
        stack[top]=value;
        printf("Pushed into the stack\n");
    }    
}
void pop(){
    if(top == -1)
        printf("Stack Underflow. Cannot pop.\n");
    else{
        printf("%d popped from the stack\n",stack[top]);
        top--;;
    }
}
void peek(){
    if(top == -1)
        printf("Stack is empty.\n");
    else
        printf("Top element is %d\n",stack[top]);
}
void display(){
    if(top == -1)
        printf("Stack is empty.");
    else{
        printf("Stack elements are: ");
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}
int main(){
    printf("Enter the size of the stack: ");
    scanf("%d",&maxsize);
    int choice,value;

    if(maxsize > 100 || maxsize <=0){
        printf("Invalid input.Exiting....\n");
        return 0;
    }

    while(1){
        printf("Enter your choice:\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be pushed into the stack:\n");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop();
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
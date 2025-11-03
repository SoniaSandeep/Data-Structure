#include<stdio.h>
#define N 5

int cqueue[N];
int front=-1, rear=-1;

void insert(int value){
if ((rear+1)%N==(front%N)){
        printf("Queue overflow!\n");
        return;
        }
if (front==-1) {
    front=0;
}
rear=(rear+1)%N;
cqueue[rear]=value;
printf("Inserted %d \n", value);
}

void delete(){
if(front==-1){
    printf("Queue underflow!\n");
    return;
}
printf("Deleted %d\n",cqueue[front]);
if (front == rear) {
        front = rear = -1;
        return;
    }
front=(front+1)%N;
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % N;
    }
    printf("\n");
}


int main(){
int choice, value;
while(1){
    printf("\n Enter choice in Queue operations menu: \n");
    printf(" 1.Insert \n 2.Delete \n 3.Display \n 4.Exit \n");
    scanf("%d",&choice);

    switch(choice){
    case 1:
        printf("Enter value: ");
        scanf("%d", &value);
        insert(value);
        break;

    case 2:
        delete();
        break;

    case 3:
        display();
        break;

    case 4:
        printf("Exiting program\n");
        return 0;
    default:
        printf("Invalid choice!\n");

}
}

}

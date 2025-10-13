#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void Queue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow!\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}


void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}


void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    int choice, value;
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf(" 1. Queue\n 2. dequeue\n 3. Display\n 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to queue: ");
                scanf("%d", &value);
                Queue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }
    return 0;
}

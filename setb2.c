#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the doubly linked circular list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function prototypes
Node* createNode(int data);
void append(Node** head, int data);
void display(Node* head);

int main() {
    Node* head = NULL;
    int choice, data, n;

    do {
        printf("\nMenu:\n");
        printf("1. Append Node\n");
        printf("2. Display List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes to append: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter data for node %d: ", i + 1);
                    scanf("%d", &data);
                    append(&head, data);
                }
                break;
            case 2:
                printf("Current List:\n");
                display(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    // Free memory
    if (head != NULL) {
        Node* temp = head;
        Node* next;
        do {
            next = temp->next;
            free(temp);
            temp = next;
        } while (temp != head);
    }

    return 0;
}

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Append a node to the end of the list
void append(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* tail = (*head)->prev;
        newNode->next = *head;
        newNode->prev = tail;
        tail->next = newNode;
        (*head)->prev = newNode;
    }
}

// Display the list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

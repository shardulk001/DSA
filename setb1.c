#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function prototypes
Node* createNode(int data);
void insertOrdered(Node** head, int data);
Node* search(Node* head, int data);
void display(Node* head);

int main() {
    Node* head = NULL;
    int choice, data;
    Node* result;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Ordered\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertOrdered(&head, data);
                printf("Data inserted.\n");
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                result = search(head, data);
                if (result != NULL) {
                    printf("Data %d found.\n", result->data);
                } else {
                    printf("Data %d not found.\n", data);
                }
                break;
            case 3:
                printf("Current List:\n");
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    // Free memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert a node into the list while maintaining order
void insertOrdered(Node** head, int data) {
    Node* newNode = createNode(data);
    Node* current = *head;

    // Insert at the beginning if the list is empty or the new data is smaller
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Traverse the list to find the insertion point
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Insert the new node
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Search for a node with specific data
Node* search(Node* head, int data) {
    Node* temp = head;
    while (temp != NULL && temp->data < data) {
        temp = temp->next;
    }
    return (temp != NULL && temp->data == data) ? temp : NULL;
}

// Display the list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

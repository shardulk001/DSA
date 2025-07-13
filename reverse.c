// Iterative C program to reverse a linked list

#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

// Given the head of a list, reverse the list and return the
// head of reversed list
struct Node* reverseList(struct Node* head) {

    // Initialize three pointers: curr, prev and next
    struct Node *curr = head, *prev = NULL, *next;

    // Traverse all the nodes of Linked List
    while (curr != NULL) {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    // Return the head of reversed linked list
    return prev;
}

// This function prints the contents
// of the linked list starting from the head
void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}

// Function to create a new node
struct Node* createNode(int new_data) {
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int main() {

    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Print the original linked list
    printf("Given Linked list:");
    printList(head);

    // Function call to return the reversed list
    head = reverseList(head);

    // Print the reversed linked list
    printf("\nReversed Linked List:");
    printList(head);

    return 0;
}

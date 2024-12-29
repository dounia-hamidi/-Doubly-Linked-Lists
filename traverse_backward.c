#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a doubly linked list
struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node
    struct Node* prev;  // Pointer to the previous node
};

// Function to create a new node with a given value
struct Node* create_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;  // Set the value of the node
    new_node->next = NULL;   // Initially, next is NULL
    new_node->prev = NULL;   // Initially, prev is NULL
    return new_node;
}

// Function to insert a node at the end of the doubly linked list
void insert_end(struct Node** head, int value) {
    struct Node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;  // If the list is empty, new node becomes the head
        return;
    }

    struct Node* temp = *head;
    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Insert the new node at the end
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to traverse and print elements of the doubly linked list from head to tail
void traverse_forward(struct Node* head) {
    struct Node* temp = head;  // Start from the head
    printf("Doubly Linked List (Forward): ");

    while (temp != NULL) {
        printf("%d ", temp->data);  // Print data of the current node
        temp = temp->next;          // Move to the next node
    }
    printf("\n");
}

// Function to traverse and print elements of the doubly linked list from tail to head
void traverse_backward(struct Node* head) {
    struct Node* temp = head;

    // Traverse to the last node (tail)
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    // Print elements from tail to head
    printf("Doubly Linked List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);  // Print data of the current node
        temp = temp->prev;          // Move to the previous node
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;  // Initialize the head of the list as NULL

    // Insert nodes at the end of the doubly linked list
    insert_end(&head, 10);  // Insert 10 at the end
    insert_end(&head, 20);  // Insert 20 at the end
    insert_end(&head, 30);  // Insert 30 at the end
    insert_end(&head, 40);  // Insert 40 at the end

    // Print the list by traversing forward (from head to tail)
    traverse_forward(head);

    // Print the list by traversing backward (from tail to head)
    traverse_backward(head);

    return 0;
}

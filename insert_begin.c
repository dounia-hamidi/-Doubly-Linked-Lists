#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in a doubly linked list
struct Node {
    int data;           // Data of the node
    struct Node* next;  // Pointer to the next node
    struct Node* prev;  // Pointer to the previous node
};

// Function to create a new node with given value
struct Node* create_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;  // Set the value of the node
    new_node->next = NULL;   // Initially, next is NULL
    new_node->prev = NULL;   // Initially, prev is NULL
    return new_node;
}

// Function to insert a node at the beginning of the doubly linked list
void insert_begin(struct Node** head, int value) {
    // Create a new node
    struct Node* new_node = create_node(value);

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
    } else {
        // Otherwise, insert the node at the beginning
        new_node->next = *head;  // The new node's next points to the current head
        (*head)->prev = new_node; // The current head's prev points to the new node
        *head = new_node;         // The head of the list is now the new node
    }
}

// Function to print the doubly linked list (from head to tail)
void print_list(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;  // Initialize the head of the list as NULL

    // Insert elements at the beginning of the doubly linked list
    insert_begin(&head, 10);  // Insert 10 at the beginning
    insert_begin(&head, 20);  // Insert 20 at the beginning
    insert_begin(&head, 30);  // Insert 30 at the beginning

    // Print the doubly linked list
    print_list(head);

    return 0;
}


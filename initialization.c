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
    new_node->next = NULL;    // Initially, next is NULL
    new_node->prev = NULL;    // Initially, prev is NULL
    return new_node;
}

// Function to insert a node at the end of the doubly linked list
void insert_end(struct Node** head, int value) {
    struct Node* new_node = create_node(value);

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = new_node;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = new_node;
    new_node->prev = temp;
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

    // Add 3 nodes with arbitrary values (e.g., 10, 20, 30)
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);

    // Print the doubly linked list
    print_list(head);

    return 0;
}

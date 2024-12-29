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

// Function to copy the doubly linked list D and return the new list
struct Node* copy(struct Node* head) {
    if (head == NULL) {
        return NULL;  // Return NULL if the original list is empty
    }

    struct Node* new_head = NULL;  // Initialize a new head for the copied list
    struct Node* temp = head;      // Temporary pointer to traverse the original list

    // Traverse the original list and copy each node
    while (temp != NULL) {
        insert_end(&new_head, temp->data);  // Insert a copy of the current node's data at the end of the new list
        temp = temp->next;                  // Move to the next node in the original list
    }

    return new_head;  // Return the head of the new doubly linked list
}

int main() {
    struct Node* head = NULL;  // Initialize the head of the list as NULL

    // Insert nodes at the end of the doubly linked list
    insert_end(&head, 10);  // Insert 10 at the end
    insert_end(&head, 20);  // Insert 20 at the end
    insert_end(&head, 30);  // Insert 30 at the end
    insert_end(&head, 40);  // Insert 40 at the end
    insert_end(&head, 50);  // Insert 50 at the end

    // Print the original list by traversing forward (from head to tail)
    traverse_forward(head);

    // Create a copy of the original list
    struct Node* copied_list = copy(head);

    // Print the copied list
    printf("Copied List:\n");
    traverse_forward(copied_list);

    return 0;
}

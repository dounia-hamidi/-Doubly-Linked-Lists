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
    struct Node* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

// Function to delete the node at position p in the doubly linked list
void delete(struct Node** head, int p) {
    // If the list is empty or the position is invalid
    if (*head == NULL || p < 0) {
        printf("List is empty or invalid position.\n");
        return;
    }

    struct Node* temp = *head;
    int index = 0;

    // If the position to delete is the head node
    if (p == 0) {
        *head = temp->next;  // Update head to the next node
        if (*head != NULL) {
            (*head)->prev = NULL;  // If there is a node after the head, set its prev to NULL
        }
        free(temp);  // Free the old head node
        return;
    }

    // Traverse the list to find the node at position p
    while (temp != NULL && index < p) {
        temp = temp->next;
        index++;
    }

    // If the position is out of bounds
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    // Remove the node from the list
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;  // Update the next node's prev pointer
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;  // Update the previous node's next pointer
    }

    free(temp);  // Free the memory of the deleted node
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

    // Insert nodes at the beginning of the doubly linked list
    insert_begin(&head, 10);  // Insert 10 at the beginning
    insert_begin(&head, 20);  // Insert 20 at the beginning
    insert_begin(&head, 30);  // Insert 30 at the beginning

    // Print the list before deletion
    printf("Before Deletion:\n");
    print_list(head);

    // Delete the node at position 1 (which is the second node in the list)
    delete(&head, 1);

    // Print the list after deletion
    printf("After Deletion:\n");
    print_list(head);

    return 0;
}


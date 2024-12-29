#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // For using the bool data type

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

// Function to check if the doubly linked list has a cycle
bool has_cycle(struct Node* head) {
    if (head == NULL) {
        return false;  // An empty list can't have a cycle
    }

    struct Node* slow = head;    // Slow pointer moves one step at a time
    struct Node* fast = head;    // Fast pointer moves two steps at a time

    // Traverse the list with fast moving two steps and slow moving one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        // Move slow pointer by one step
        fast = fast->next->next;  // Move fast pointer by two steps

        // If fast and slow pointers meet, there's a cycle
        if (slow == fast) {
            return true;
        }
    }

    // If fast pointer reaches NULL or fast->next is NULL, no cycle
    return false;
}

// Function to traverse and print elements of the doubly linked list from head to tail
void traverse_forward(struct Node* head) {
    struct Node* temp = head;  // Start from the head
    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d ", temp->data);  // Print data of the current node
        temp = temp->next;          // Move to the next node
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
    insert_end(&head, 50);  // Insert 50 at the end

    // Print the list by traversing forward (from head to tail)
    traverse_forward(head);

    // Check for a cycle in the list
    if (has_cycle(head)) {
        printf("The list contains a cycle.\n");
    } else {
        printf("The list does not contain a cycle.\n");
    }

    return 0;
}

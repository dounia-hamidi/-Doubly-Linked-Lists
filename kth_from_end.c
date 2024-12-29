#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct ListNode {
    int value;
    struct ListNode* next;
};

// Function to find the k-th node from the end of the list
struct ListNode* kth_from_end(struct ListNode* head, int k) {
    struct ListNode* first = head;
    struct ListNode* second = head;

    // Move the first pointer k steps ahead
    for (int i = 0; i < k; i++) {
        if (first == NULL) {
            // If there are fewer than k nodes in the list, return NULL
            return NULL;
        }
        first = first->next;
    }

    // Now move both pointers one step at a time until the first reaches the end
    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    // When the first pointer reaches the end, the second pointer is at the k-th node from the end
    return second;
}

// Helper function to create a new node
struct ListNode* create_node(int value) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Function to print the value of a node
void print_node(struct ListNode* node) {
    if (node != NULL) {
        printf("Value of k-th node from end: %d\n", node->value);
    } else {
        printf("The list has fewer than k nodes.\n");
    }
}

// Main function to test the kth_from_end function
int main() {
    // Creating the linked list 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    // Find the 2nd node from the end
    struct ListNode* result = kth_from_end(head, 2);

    // Print the result
    print_node(result);

    // Free allocated memory (not strictly necessary in this short program)
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

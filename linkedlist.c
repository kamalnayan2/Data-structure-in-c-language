#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
struct node {
    int data; // The data in the node
    struct node *next; // The pointer to the next node
};

// Create a list of n nodes
struct node *createList(int n) {
    struct node *head = NULL; // The pointer to the head of the list
    struct node *newNode, *temp; // Helper variables
    int data, i;

    // Loop to create n nodes
    for (i = 0; i < n; i++) {
        // Allocate memory for a new node
        newNode = (struct node *)malloc(sizeof(struct node));

        // Check if memory is allocated
        if (newNode == NULL) {
            printf("Unable to allocate memory.\n");
            exit(0);
        }

        // Input data for the node
        printf("Enter the data of node %d: ", i + 1);
        scanf("%d", &data);

        // Link data field with data
        newNode->data = data;

        // Link address field to NULL
        newNode->next = NULL;

        // If this is the first node, make it the head
        if (head == NULL) {
            head = newNode;
        }
        // Else, link the last node with the new node
        else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Return the head of the list
    return head;
}

// Delete a node from the list by its position
void deleteNode(struct node **head, int position) {
    struct node *temp, *prev; // Helper variables
    int i;

    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Check if the position is valid
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    // If the position is 1, delete the head node
    if (position == 1) {
        temp = *head; // Store the head node
        *head = (*head)->next; // Make the next node as the head
        free(temp); // Free the old head node
    }
    // Else, delete the node at the given position
    else {
        temp = *head; // Store the head node
        // Loop to find the node at the position
        for (i = 1; i < position && temp != NULL; i++) {
            prev = temp; // Store the previous node
            temp = temp->next; // Move to the next node
        }

        // Check if the node exists
        if (temp == NULL) {
            printf("No node found at position %d.\n", position);
        }
        else {
            prev->next = temp->next; // Unlink the node from the list
            free(temp); // Free the node
        }
    }
}

// Display the list
void displayList(struct node *head) {
    struct node *temp; // Helper variable

    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Loop to print the data of each node
    temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n, position; // Variables to store the number of nodes and the position to delete
    struct node *head = NULL; // The pointer to the head of the list

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the list
    head = createList(n);

    // Display the list
    printf("\nThe original list is:\n");
    displayList(head);

    // Input the position to delete
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    // Delete the node at the position
    deleteNode(&head, position);

    // Display the list
    printf("\nThe updated list is:\n");
    displayList(head);

    return 0;
}
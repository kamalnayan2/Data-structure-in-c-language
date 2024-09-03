/**
 *  binary_tree.c
 * ief Implementation of a binary tree data structure in C
 *
 * This program creates a binary tree and allows the user to insert nodes
 * with integer values. The tree is then traversed in inorder fashion
 * and the node values are printed to the console.
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/**
 *  Structure to represent a node in the binary tree
 */
struct node {
    int data; /**< integer value stored in the node */
    struct node *right; /**< pointer to the right child node */
    struct node *left; /**< pointer to the left child node */
};

/**
 *  Create a new node in the binary tree
 *
 *  root the current root node of the tree
 *  item the integer value to be stored in the new node
 *  the new root node of the tree
 */
struct node *create(struct node *root, int item) {
    if (root == NULL) {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    } else {
        if (item < root->data) {
            printf("%d inserted left of %d\n", item, root->data);
            root->left = create(root->left, item);
        } else if (item > root->data) {
            printf("%d inserted right of %d\n", item, root->data);
            root->right = create(root->right, item);
        } else {
            printf("Duplicate Element is Not Allowed !!!");
        }
        return root;
    }
}

/**
 *  Perform an inorder traversal of the binary tree
 *
 *  root the root node of the tree
 */
void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

/**
 *  Main function
 * 0 on successful execution
 */
int main() {
    struct node *root = NULL;
    setbuf(stdout, NULL);
    char ch;
    int item;

    root = NULL;
    do {
        printf("\nEnter data for node ");
        scanf("%d", &item);
        root = create(root, item);
        printf("Do you want to insert more elements? ");
        scanf(" %c", &ch); // use a space before %c to clear stdin
    } while (ch == 'y' || ch == 'Y');

    printf("inorder\n");
    inorder(root);
    getch();
    return 0;
}
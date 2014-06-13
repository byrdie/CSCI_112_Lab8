/* 
 * File:   main.c
 * Author: Roy Smart
 * CSCI 112 Lab 8
 * Montana State University
 *
 * Created on June 10, 2014, 11:18 AM
 */


#include "main.h"

/*
 * main creates a tree, prints it, and executes extra credit function
 */
int main(int argc, char** argv) {
    int content_array[] = {6, 2, 5, 0, 1, 3, 4};

    /*initialize tree*/
    tree lab_tree;
    lab_tree.size = sizeof (content_array) / sizeof (int);
    build_tree(content_array, &lab_tree);

    int i = 0;
    while (1) {

        printf("\n");
        /*print tree post-order*/
        puts("Print tree in post-order");
        print_postorder(lab_tree.root);
        printf("\n\n");

        /*extra credit call*/
        int search_num; //number to be searched for
        int result = FALSE; //pass/fail of function call

        printf("Please enter number to search in the tree\n");
        scanf("%d", &search_num);
        int new_content = 0x2a << i;
        Node * new_child = node_constructor(new_content);
        result = extra_credit(search_num, new_child, lab_tree.root);

        /*print result of function call if successful*/
        if (result) {
            printf("Match! Content of new Node: %d\n", new_child->content);
        } else {
            printf("No match. New node was not created.\n");
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

/*
 * Node constructor allocates memory for a new node and adds the content of the
 * node into the correct field.
 * 
 * returns a pointer to the allocated node
 */
Node * node_constructor(int content) {
    Node * new_node = malloc(sizeof (Node)); //dynamically allocate space for new node
    new_node->content = content; //initialize content    

    /*ensure no junk for pointers to children*/
    new_node->left = NULL;
    new_node->right = NULL;
}

/*
 * build tree takes an array of tree elements and inserts them into a heap
 * structure. The function then uses the heap structure to reference the 
 * element's parent and set up the link to the child.
 */
void build_tree(int * content_array, tree * tree) {
    /*allocate space for binary tree heap*/
    Node * tree_heap[tree->size];

    /*
     * loop to insert all array contents into tree. Start at 1 so heap array 
     * arithmetic is executed properly
     */
    int i;
    for (i = 1; i <= tree->size; i++) {
        /*allocate new node. NOTE: content array and heap array are offset by one*/
        Node * next_node = node_constructor(content_array[i - 1]);

        /*fill binary heap with new node*/
        tree_heap[i] = next_node;

        /*Set up link from parent to child*/
        if (i == 1) { //if root node
            tree->root = next_node;
        } else { //if not root set parent to current node using heap
            int parent_index = i / 2; //use heap to find parent 
            if (i % 2 == 0) { // even values of i are left children
                tree_heap[parent_index]->left = next_node;
            } else { // odd values are right children
                tree_heap[parent_index]->right = next_node;
            }
        }
    }
}

/*
 * print postorder accepts a tree and local root as a parameter and recursively
 * traverses and prints all of the content.
 */
void print_postorder(Node * current_node) {

    if (current_node->left != NULL) { // visit left node
        print_postorder(current_node->left);
    }

    if (current_node->right != NULL) { //visit right node
        print_postorder(current_node->right);
    }
    printf("%d, ", current_node->content); //visit current node
}

/*
 * extra credit takes a number to find in the tree. The function finds the 
 * number, creates random node as a child and passes back the pointer to the
 * child.
 * 
 * On success it passes back an int 1, on failure a 0
 */
int extra_credit(int reference_num, Node * pointer_arg, Node * current_node) {
    /*check if reference_num is in current node*/
    if (reference_num == current_node->content) {
        current_node->left = pointer_arg;
        return TRUE;
    }

    /*if not check its children*/
    int result = FALSE;
    if (current_node->left != NULL) {
        result = extra_credit(reference_num, pointer_arg, current_node->left);
    }
    if (current_node->right != NULL && result == FALSE) {
        result = extra_credit(reference_num, pointer_arg, current_node->right);
    }
    return result;
}


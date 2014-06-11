/* 
 * File:   main.c
 * Author: Roy Smart
 * CSCI 112 Lab 8
 * Montana State University
 *
 * Created on June 10, 2014, 11:18 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int content_array[] = {6, 2, 5, 0, 1, 3, 4};

    /*initialize tree*/
    tree lab_tree;
    lab_tree.size = sizeof (content_array) / sizeof (int);
    build_tree(content_array, &lab_tree);

    /*print tree in-order*/
    print_postorder(lab_tree.root);

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

    /*loop to insert all array contents into tree*/
    int i;
    for (i = 1; i <= tree->size; i++) {
        Node * next_node = node_constructor(content_array[i - 1]); //allocate new node
        /*fill binary heap with new node*/
        tree_heap[i] = next_node;

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
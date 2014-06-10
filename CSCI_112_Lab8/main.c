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
    lab_tree.size = sizeof(content_array);
    build_tree(content_array, lab_tree);

    return (EXIT_SUCCESS);
}

/*
 * Node constructor allocates memory for a new node and adds the content of the
 * node into the correct field.
 * 
 * returns a pointer to the allocated node
 */
Node * node_constructor(int content) {
    Node * new_node = malloc(sizeof (Node));
    new_node->content = content;
    new_node->left = NULL;
    new_node->right = NULL;
}

/*
 * build_tree accepts an array of content to be placed into a tree. Content is
 * inserted into the tree in correct order and a pointer to the root node
 * is returned.
 */
void build_tree(int * content_array, tree * tree) {
    /*loop to insert all array contents into tree*/
    int i;
    for (i = 0; i < tree->size; i++) {
        Node * next_node = node_constructor(content_array[i]); //allocate new node

        /*insert new node into tree*/
        if (tree->root == NULL) { //nothing in the tree
            tree->root = next_node;
        } else { //root is declared, recursively find spot
            recursive_insert(tree->root, next_node);
        }
    }

}

/*
 * recursive insert accepts a node being inserted and the current local node
 * being examined. Once a spot is found the node is saved using its parent
 */
void recursive_insert(Node * local_root, Node * node) {
    if (local_root->content < node->content) { //traverse left child
        if (local_root->left == NULL) { //nothing there, insert node
            local_root->left = node;
        } else { //already a child, traverse to next level
            recursive_insert(local_root->left, node);
        }
    } else if (local_root->content > node->content) { //traverse right child
        if (local_root->right == NULL) { //nothing there, insert node
            local_root->right = node;
        } else { //already a child, traverse to next level
            recursive_insert(local_root->right, node);
        }
    } else {
        printf("Node is already in tree\n");
    }
}

/*
 * print inorder accepts a tree and local root as a parameter and recursively
 * traverses and prints all of the content.
 */ 
void print_inorder(tree * tree, Node * local_root){
    
}
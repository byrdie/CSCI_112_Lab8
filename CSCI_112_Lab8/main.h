/* 
 * File:   main.h
 * Author: roy.smart
 *
 * Created on June 10, 2014, 11:23 AM
 */

#ifndef MAIN_H
#define	MAIN_H

/*struct for nodes of tree*/
typedef struct Node{
    int content;
    struct Node * left;
    struct Node * right;
}Node;

/*struct for tree*/
typedef struct{
    int size;
    Node * root;
}tree;

/*function prototypes*/
Node * node_constructor(int);
void build_tree(int*, tree*);
void recursive_insert(Node*, Node*);
void print_inorder(tree *, Node*);

#endif	/* MAIN_H */


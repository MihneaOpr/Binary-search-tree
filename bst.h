
#ifndef __BST_H_
#define __BST_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define BST_DATA_LEN  50

typedef struct {
    char name[30];
    char class[30];
    double grade;
} Student;


typedef struct bst_node_t bst_node_t;
struct  bst_node_t {
    /* left child */
    bst_node_t *left;

    /* right child */
    bst_node_t *right;

    /* data contained by the node */
    void *data;
};

typedef struct bst_tree_t bst_tree_t;
struct bst_tree_t {
    /* root of the tree */
    bst_node_t  *root;

    /* function used for sorting the keys */
    int	(*cmp)(void *key1, void *key2);
};

/* Alloc memory for bst */
bst_tree_t *bst_tree_create(int (*cmp_f) (void *, void *));

/* Insert new node in bst*/
void bst_tree_insert(bst_tree_t *bst_tree, void *data, size_t size);

void bst_tree_sort(bst_node_t *);

void bst_tree_remove(bst_tree_t *bst_tree, void *data);

void bst_tree_free(bst_tree_t *bst_tree);

Student* bst_tree_search(bst_node_t *bst_node, char *name);

#endif

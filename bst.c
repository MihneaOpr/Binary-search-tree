#include "bst.h"

bst_node_t *__bst_node_create(void *data, size_t size_of_data)
{
    bst_node_t *bst_node;

    bst_node = malloc(sizeof(bst_node_t));

    bst_node->left = bst_node->right = NULL;

    bst_node->data = calloc(1, size_of_data);

    memcpy(bst_node->data, data, size_of_data);

    return bst_node;
}

bst_tree_t *bst_tree_create(int (*cmp_f) (void *, void *))
{
    bst_tree_t *bst_tree;

    bst_tree = malloc(sizeof(bst_tree_t));

    bst_tree->root  = NULL;
    bst_tree->cmp   = cmp_f;

    return bst_tree;
}

void bst_tree_insert(bst_tree_t *bst_tree, void *data, size_t size_of_data)
{
    bst_node_t *root    = bst_tree->root;
    bst_node_t *parent  = NULL;
    bst_node_t *node    = __bst_node_create(data, size_of_data);

    if(root == NULL) {
        bst_tree->root = node;
        return;
    }
    while(root != NULL) {
        parent = root;
        if(bst_tree->cmp(root->data, data) > 0) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    if(bst_tree->cmp(parent->data, data) > 0) {
        parent->left = node;
    } else {
        parent->right = node;
    }
}

Student* bst_tree_search(bst_node_t *bst_node, char *name) {
    if(bst_node == NULL) {
        return NULL;
    }
    Student* stud = (Student *)bst_node->data;
    char name_lower[30];
    strcpy(name_lower, stud->name);
    for(int i = 0; i < strlen(stud->name); i++) {
        name_lower[i] = tolower(stud->name[i]);
    }
    if(strcmp(name_lower, name) != 0) {
        bst_tree_search(bst_node->left, name);
        bst_tree_search(bst_node->right, name);
    } else {
        return stud;
    }  
}

void __bst_tree_free(bst_node_t *bst_node)
{
    if (!bst_node)
        return;

    __bst_tree_free(bst_node->left);
    __bst_tree_free(bst_node->right);
    free(bst_node->data);
    free(bst_node);
}

void bst_tree_sort(bst_node_t *bst_node) {
    static int place = 0;
    if(bst_node != NULL) {
        if(bst_node->right != NULL) {
            bst_tree_sort(bst_node->right);
        }
        Student stud =*(Student *) bst_node->data;
        printf("%d.%s -> grade: %lf\n", ++place, stud.name, stud.grade);
        if(bst_node->left != NULL) {
            bst_tree_sort(bst_node->left);
        }
    }
}

void bst_tree_free(bst_tree_t *bst_tree)
{
    __bst_tree_free(bst_tree->root);
    free(bst_tree);
}


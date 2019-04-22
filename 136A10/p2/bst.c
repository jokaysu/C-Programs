#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "bst.h"

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Chenzheng Su
    login ID: c28su
*/

// IMPORTANT: DO NOT CHANGE THESE VALUES
const int PRE_ORDER = 0;
const int IN_ORDER = 1;
const int POST_ORDER = 2;

// IMPORTANT: DO NOT CHANGE THESE DEFINITIONS
struct bstnode {
    int item;
    struct bstnode *left;
    struct bstnode *right;
    int size;
};

typedef struct bstnode *Node;

struct bst {
    struct bstnode *root;
};

Bst bst_create(void) {
    Bst t = malloc(sizeof(struct bst));
    t->root = malloc(sizeof(struct bstnode));
    t->root->left = NULL;
    t->root->right = NULL;
    t->root->size = 0;
    return t;
}

void destroyNode(Node node) {
    if (!node) {
        free(node);
        return;
    }
    if (node->size == 1) free(node);
        else {
            destroyNode(node->left);
            destroyNode(node->right);
            free(node);
        }
}

void bst_destroy(Bst t) {
    if (bst_size(t) == 0) {
        free(t->root);
        free(t);
    } else {
        destroyNode(t->root);
        free(t);
    }
}

int bst_size(Bst t) {
    return t->root->size;
}

void bst_insert(int i, Bst t) {
    Node cur = t->root;
    if (bst_size(t) == 0) {
        cur->item = i;
        cur->size++;
        return;
    }
    while (cur) {
        if (cur->item == i) return;
        cur->size++;
        if (i < cur->item) {
            if (cur->left) {
                cur = cur->left;
            }
            else {
                cur->left = malloc(sizeof(struct bstnode));
                cur = cur->left;
                cur->item = i;
                cur->left = NULL;
                cur->right = NULL;
                cur->size = 1;
            }
        } else {
            if (cur->right) {
                cur = cur->right;
            }
            else {
                cur->right = malloc(sizeof(struct bstnode));
                cur = cur->right;
                cur->item = i;
                cur->left = NULL;
                cur->right = NULL;
                cur->size = 1;
            }
        }
    }
}

bool bst_find(int i, Bst t) {
    Node cur = t->root;
    while (cur) {
        if (cur->item == i) return true;
        if (i < cur->item) cur = cur->left;
            else cur = cur->right;
    }
    return false;
}

int bst_select(int k, Bst t) {
    Node cur = t->root;
    while (cur->size != 1) {
        if (!cur->left) {
            if (k == 1) break;
            cur = cur->right;
            k -= 1;
            continue;
        }
        if (!cur->right) {
            if (cur->size == k) break;
            cur = cur->left;
            k -= 1;
            continue;
        }
        if (k <= cur->left->size) {
            cur = cur->left;
            k -= 1;
        } else {
            k = k - 1 - cur->left->size;
            cur = cur->right;
        }
    }
    return cur->item;
}

void bst_remove (int i, Bst t) {
    Node cur = t->root;
    while (cur) {
        if (cur->item == i) break;
        if (i < cur->item) cur = cur->left;
            else cur = cur->right;
    }
    Node par = t->root;
    while (par) {
        if (par->left == cur || par->right == cur) break;
        if (i < par->item) par = par->left;
            else par = par->right;
    }
    if (cur->size == 1) {
        if (par->left == cur) par->left = NULL;
            else par->right = NULL;
        free(cur);
        return;
    }
    if (!cur->left) {
        if (par->left == cur) par->left = cur->right;
            else par->right = cur->right;
        free(cur);
    } else if (!cur->right) {
        if (par->left == cur) par->left = cur->left;
            else par->right = cur->left;
        free(cur);
    } else {
        struct bst b;
        b.root = cur;
        cur->item = bst_select(1, &b);
        //int t = cur->item;
        par = cur;
        cur = cur->right;
        bool flag = true;
        while (cur->left) {
            flag = false;
            par = cur;
            cur = cur->left;
        }
        if (flag) par->right = cur->right;
            else par->left = cur->right;
        free(cur);
    }
}

int nodeRange(int s, int e, Node c) {
    if (!c) return 0;
    if (c->size == 1) {
        if (c->item >= s && c->item <= e)
            return 1;
        else return 0;
    }
    if (c->item >= s && c->item <= e) 
        return 1 + nodeRange(s, e, c->left)
                 + nodeRange(s, e, c->right);
    if (c->item > e) return nodeRange(s, e, c->right);
        else return nodeRange(s, e, c->left);
}

int bst_range(int start, int end, Bst t) {
    return nodeRange(start, end, t->root);
}

void nodePrint(int o, Node n, int *times) {
    if (!n) return;
    if (o == PRE_ORDER) {
        printf("%d", n->item);
        (*times)--;
        if (*times != 0) printf(",");
            else printf("]\n");
        nodePrint(o, n->left, times);
        nodePrint(o, n->right, times);
    }
    if (o == IN_ORDER) {
        nodePrint(o, n->left, times);
        printf("%d", n->item);
        (*times)--;
        if (*times != 0) printf(",");
            else printf("]\n");
        nodePrint(o, n->right, times);
    }
    if (o == POST_ORDER) {
        nodePrint(o, n->left, times);
        nodePrint(o, n->right, times);
        printf("%d", n->item);
        (*times)--;
        if (*times != 0) printf(",");
            else printf("]\n");
    }
}

void bst_print (int o, Bst t) {
    int ti = t->root->size;
    printf("[");
    nodePrint(o, t->root, &ti);
}

void nodeToArray(Node n, int *arr, int *cur) {
    if (!n) return;
    if (n->size == 1) {
        arr[*cur] = n->item;
        (*cur)++;
        return;
    }
    nodeToArray(n->left , arr, cur);
    arr[*cur] = n->item;
    (*cur)++;
    nodeToArray(n->right, arr, cur);
}

int *bst_to_sorted_array(Bst t) {
    int l = t->root->size;
    int *ans = malloc(l * sizeof(int));
    int c = 0;
    nodeToArray(t->root, ans, &c);
    return ans;
}

Node arrToNode(int *a, int s, int e) {
    if (!a || s > e) return NULL;
    Node n = malloc(sizeof(struct bstnode));
    int mid = (e - s) / 2 + s;
    n->item = a[mid];
    n->size = e - s + 1;
    n->left = arrToNode(a, s, mid - 1);
    n->right = arrToNode(a, mid + 1, e);
    return n;
}

Bst sorted_array_to_bst(int *arr, int len) {
    Bst b = malloc(sizeof(struct bst));
    b->root = arrToNode(arr, 0, len - 1);
    return b;
}


#include <stdlib.h>
#include <stdio.h>

typedef struct BSTNode *Link;
typedef struct BSTNode {
    int value;
    Link left, right;
} BSTNode;
typedef BSTNode *BSTree;

BSTree newNode(int value) {
    BSTree new = malloc(sizeof(BSTNode));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

BSTree BSTInsert(BSTree t, int value) {
    if (t == NULL) {
        return newNode(value);
    } else if (t->value > value) {
        t->left = BSTInsert(t->left, value);
    } else if (t->value < value) {
        t->right = BSTInsert(t->right, value);
    }
    // If t->value == value, do nothing
    return t;
}

void freeTree(BSTree t) {
    if (t == NULL) {
        return;
    }
    freeTree(t->left);
    freeTree(t->right);
    free(t);
}

void printInfix(BSTree t) {
    if (t == NULL) return;
    printInfix(t->left);
    printf("%d ", t->value);
    printInfix(t->right);
}

void printPostfix(BSTree t) {
    if (t == NULL) return;
    printInfix(t->left);
    printInfix(t->right);
    printf("%d ", t->value);
}

void printPrefix(BSTree t) {
    if (t == NULL) return;
    printf("%d ", t->value);
    printInfix(t->left);
    printInfix(t->right);
}

// To be explained
int TreeNumNodes(BSTree t);
// To be explained
int TreeHeight(BSTree t);

// TODO: Q2
int countInternal(BSTree t);
// TODO: Q3
int nodeDepth(BSTree t);
// TODO: Q4
int BSTreeMaxBranchLen(BSTree t);
// TODO: Q5
int BSTWidth(BSTree t);

BSTree constructN(int n) {
    int values[7] = {5, 8, 3, 4, 9, 1, 7};
    int i;

    BSTree t = NULL;
    for (i = 0; i < n; i++) {
        t = BSTInsert(t, values[i]);
    }

    return t;
}

int main(void) {

    BSTree t0 = constructN(7);
    BSTree single = newNode(5);

    printInfix(t0);
    printf("\n");

#ifdef Q1

    printf("Nodes in full tree: %d\n", TreeNumNodes(t0));
    printf("Nodes in half tree: %d\n", TreeNumNodes(t0->right));
    printf("Nodes in single: %d\n", TreeNumNodes(single));
    printf("Nodes in empty tree: %d\n", TreeNumNodes(NULL));

    printf("Height of full tree: %d\n", TreeHeight(t0));
    printf("Height of half tree: %d\n", TreeHeight(t0->right));
    printf("Height of single: %d\n", TreeHeight(single));
    printf("Height of empty tree: %d\n", TreeHeight(NULL));

#endif

#ifdef Q2

    printf("Internal nodes in full tree: %d\n", countInternal(t0));
    printf("Internal nodes in half tree: %d\n", countInternal(t0->left));
    printf("Internal nodes in single: %d\n", countInternal(single));

#endif

#ifdef Q3

    printf("1 at depth: %d\n", nodeDepth(t0, 1));
    printf("5 at depth: %d\n", nodeDepth(t0, 5));
    printf("3 at depth: %d\n", nodeDepth(t0, 3));
    printf("9 at depth: %d\n", nodeDepth(t0, 9));
    printf("20 at depth: %d\n", nodeDepth(t0, 20));

#endif

#ifdef Q4

    printf("Max branch length on full tree: %d\n", BSTreeMaxBranchLen(t0));
    printf("Max branch length on half tree: %d\n", BSTreeMaxBranchLen(t0->left));
    printf("Max branch length on single: %d\n", BSTreeMaxBranchLen(single));

#endif

#ifdef Q5

    BSTree t1 = constructN(1);
    BSTree t2 = constructN(2);
    BSTree t3 = constructN(3);
    BSTree t4 = constructN(5);
    BSTree t5 = constructN(7);

    printInfix(t1); printf("has width: %d\n", BSTWidth(t1));
    printInfix(t2); printf("has width: %d\n", BSTWidth(t2));
    printInfix(t3); printf("has width: %d\n", BSTWidth(t3));
    printInfix(t4); printf("has width: %d\n", BSTWidth(t4));
    printInfix(t5); printf("has width: %d\n", BSTWidth(t5));

    freeTree(t1);
    freeTree(t2);
    freeTree(t3);
    freeTree(t4);
    freeTree(t5);

#endif

    freeTree(t0);
    freeTree(single);

    return EXIT_SUCCESS;
}

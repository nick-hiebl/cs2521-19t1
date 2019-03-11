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

/*            5
 *           / \
 *          /   \
 *         3     8
 *        / \   / \
 *       2   4 7  10
 *                 \
 *                 12
 *                  \
 *                  15
 */

BSTree constructN(int n) {
    int values[9] = {5, 8, 3, 7, 4, 2, 10, 12, 15};
    int i;

    BSTree t = NULL;
    for (i = 0; i < n; i++) {
        t = BSTInsert(t, values[i]);
    }

    return t;
}
// #define HEIGHT_DIFF
int printHeightDiff(BSTree t) {
    if (t == NULL) return 0;
    int left = printHeightDiff(t->left);
    int right = printHeightDiff(t->right);
    printf("Height difference at node %d is %d\n", t->value, left - right);
    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

#define IS_AVL
int isAVL(BSTree t) {
    if (t == NULL) return 0;
    int left = isAVL(t->left);
    if (left == -1) return -1;
    int right = isAVL(t->right);
    if (right == -1) return -1;
    if (left - right > 1 || left - right < -1) {
        return -1;
    }
    if (left > right) {
        return left + 1;
    } else {
        return right + 1;
    }
}

int main(void) {

    BSTree t0 = constructN(3);
    BSTree t1 = constructN(6);
    BSTree t2 = constructN(7);
    BSTree t3 = constructN(9);

#ifdef HEIGHT_DIFF

    printf("For t0:\n");
    printHeightDiff(t0);

    printf("For t1:\n");
    printHeightDiff(t1);

    printf("For t2:\n");
    printHeightDiff(t2);

    printf("For t3:\n");
    printHeightDiff(t3);

#endif

#ifdef IS_AVL

    printf("isAVL(t0) = %d\n", isAVL(t0));
    printf("isAVL(t1) = %d\n", isAVL(t1));
    printf("isAVL(t2) = %d\n", isAVL(t2));
    printf("isAVL(t3) = %d\n", isAVL(t3));

#endif

    freeTree(t0);
    freeTree(t1);
    freeTree(t2);
    freeTree(t3);

    return EXIT_SUCCESS;
}

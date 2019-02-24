#include <stdlib.h>
#include <stdio.h>

typedef struct _Node {
    int value;
    struct _Node *next;
} Node;

typedef Node* List;

List singleList(int value) {
    List node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

List fromArgs(int argc, char **argv) {
    int i;
    List l = NULL;
    for (i = argc - 1; i > 0; i--) {
        List temp = singleList(atoi(argv[i]));
        temp->next = l;
        l = temp;
    }

    return l;
}

void printList(List l) {
    if (l == NULL) {
        printf("X\n");
    } else {
        printf("%d -> ", l->value);
        printList(l->next);
    }
}

int sumUsingWhile(List l) {
    return -1;
}

int sumUsingFor(List l) {
    return -1;
}

int sumUsingRecursion(List l) {
    return -1;
}

int main(int argc, char **argv) {
    List l = fromArgs(argc, argv);

    printList(l);

    printf("Sum is %d\n", sumUsingWhile(l));
    printf("Sum is %d\n", sumUsingFor(l));
    printf("Sum is %d\n", sumUsingRecursion(l));

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int index;
  double value;
  struct _node *next;
} *Node;

typedef struct _vector {
  Node first;
  int dimension;
} *Vector;

Vector addVectors(Vector a, Vector b);

void showVector(Vector v) {
  Node curr = v->first;
  int i = 0;
  printf("(");
  while (i < v->dimension) {
    if (curr != NULL && curr->index == i) {
      printf("%.2lf,", curr->value);
      curr = curr->next;
    } else {
      printf("0.00,");
    }
    i++;
  }
  printf(")\n");
}

Vector newVector(int dimension) {
  Vector v = malloc(sizeof(struct _vector));
  v->dimension = dimension;
  v->first = NULL;
  return v;
}

Node newNode(int i, double v, Node n) {
  Node node = malloc(sizeof(struct _node));
  node->index = i;
  node->value = v;
  node->next = n;
  return node;
}

void freeList(Node n) {
  Node next = n->next;
  free(n);
  if (next != NULL) freeList(next);
}

void freeVector(Vector v) {
  freeList(v->first);
  free(v);
}

int main(void) {
  Vector v1 = newVector(8);
  v1->first = newNode(4, 1.7, v1->first);
  v1->first = newNode(1, -0.1, v1->first);
  v1->first = newNode(0, 2.3, v1->first);

  Vector v2 = newVector(8);
  v2->first = newNode(7, -1.8, v2->first);
  v2->first = newNode(4, -1.7, v2->first);
  v2->first = newNode(1, 3.14, v2->first);

  showVector(v1);
  showVector(v2);

  Vector sum = addVectors(v1, v2);
  showVector(sum);

  freeVector(v1);
  freeVector(v2);

  return EXIT_SUCCESS;
}

Vector addVectors(Vector a, Vector b) {
  Vector res = newVector(a->dimension);
  return res;
}

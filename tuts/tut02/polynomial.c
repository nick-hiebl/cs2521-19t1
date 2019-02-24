#include <stdio.h>
#include <stdlib.h>

double eval_polynomial(double[], int, double);

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    fprintf(stderr, "Give coefficients as command-line arguments\n");
    return EXIT_FAILURE;
  }

  double *coefficients;
  int n = argc - 1;
  coefficients = malloc(n * sizeof(double));
  int i;
  for (i = 0; i < n; i++) {
    coefficients[i] = atof(argv[argc - i - 1]);
  }

  printf("%.2lf", coefficients[0]);
  for (i = 1; i < n; i++) {
    printf(" + %.2lfx^%d", coefficients[i], i);
  }
  printf("\nx = ");

  double x;
  scanf("%lf", &x);

  double f_x = eval_polynomial(coefficients, n, x);

  printf("f(x) = %lf\n", f_x);

  return EXIT_SUCCESS;
}

double eval_polynomial(double coefficients[], int n, double x) {
  return 0;
}

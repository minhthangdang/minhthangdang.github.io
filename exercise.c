#include <stdio.h>
#include <stdlib.h>

/**
* Find two x and y values where x and y have the same remainder when divided by n
*
* @param n - positive integer
* @param m - the size of array a (m > n)
* @param a - array of m non-negative integers
* @return an array contains x and y values (of -1 if not found)
*/
int* find_congruence(int n, int m, int *a)
{
  int *x, i, r;
  static int result[2] = {-1, -1}; // hold the results, values of -1 if not found
  
  // create an array of n elements with default value of -1
  x = (int *)calloc(n, sizeof(int));
  for (i=0; i<n; i++) {
    x[i] = -1;
  }
  
  // find two values that have the same remainder when divided by n
  for (i=0; i<m; i++) {
    r = a[i] % n;
    
    if (x[r] == -1) {
      x[r] = a[i];
    } else {
      result[0] = x[r];
      result[1] = a[i];
      break;
    }
  }
  
  return result;
}

void main()
{
  int n, m, *a, *result;
  
  // input for n
  printf("Enter value for n: ");
  scanf("%d", &n);
  
  // input for m
  printf("Enter value for m: ");
  scanf("%d", &m);
  
  // create an array of m elements
  a = (int *)calloc(m, sizeof(int));
  int i;
  for (i=0; i<m; i++) {
    printf("Enter a[%d]: ", i);
    scanf("%d", &a[i]);
  }
  
  // find x and y
  result = find_congruence(n, m, a);
  
  // print the result
  printf("x = %d, y =%d", result[0], result[1]);
  
}
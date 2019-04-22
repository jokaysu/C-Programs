#include <stdio.h>

int g(int x);
int h(int x);

int f(int x) {
  printf("f(%d) called\n",x);
  int y = g(x);
  y += h(g(x-1));
  return y;
}

int g(int x) {
  printf("g(%d) called\n",x);
  int y = h(x * 5);
  return y;
}

int h(int x) {
  printf("h(%d) called\n",x);
  int y = x * x;
  return y / 2;
}


int main(void) {
  int x = f(5);
  printf("x = %d\n",x);
}

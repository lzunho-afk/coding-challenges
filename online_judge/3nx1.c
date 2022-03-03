#include <stdio.h>

int main(int argc, char **argv) {
  /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/
  
  int i, j, h, g, aux;
  int valMax, count;
  
  while (scanf("%d %d", &i, &j) != EOF) {
    valMax = 1;
    if (i > j) {
      h = j;
      g = i;
    } else {
      h = i;
      g = j;
    }
    
    for (h; h <= g; h++) {
      aux = h;
      count = 0;
      while(aux > 1) {
	if (aux % 2 != 0) {
	  aux = 3*aux + 1;
	} else {
	  aux = aux/2;
	}
	count++;
      }
      if (count > valMax) {
	valMax = count;
      }
    }
    if (i == 1 && j == 1) {
      printf("%d %d %d\n", i, j, 1); 
    } else {
      printf("%d %d %d\n", i, j, valMax+1);
    }
  }
  return 0;
}

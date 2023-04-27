#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 500

int t[MAX];

void shifttable(char p[]) {
  int i, j, m;
  m = strlen(p);
  
  for(i = 0 ; i < MAX ; i++)
    t[i] = m;
  
  for(j = 0 ; j < m-1 ; j++)
    t[p[j]] = m - 1 - j;
}

int horspool(char src[], char p[]) {
  int i, j, k, m, n, count = 0;
  n = strlen(src);
  m = strlen(p);
  
  printf("Length of the text = %d\n", n);
  printf("Length of the pattern = %d\n", m);
  
  i = m - 1;
  
  while(i < n) {
    k = 0;
    while((k < m) && (p[m-1-k] == src[i-k])) {
      k++;
      count++; // increment count for each comparison
    }
    
    if(k == m) {
      printf("Number of key comparisons in successful search: %d\n", count);
      return(i - m + 1);
    }
    else {
      count++; // increment count for comparison in if statement
      i += t[src[i]];
    }
  }
  printf("Number of key comparisons in unsuccessful search: %d\n", count);
  return -1;
}

int main() {
  char src[100], p[100];
  int pos;
  
  printf("Enter the text:\n");
  fgets(src, sizeof(src), stdin);
  src[strcspn(src, "\n")] = '\0'; // remove newline character
  
  printf("Enter the pattern:\n");
  fgets(p, sizeof(p), stdin);
  p[strcspn(p, "\n")] = '\0'; // remove newline character
  
  shifttable(p);
  
  pos = horspool(src, p);
  
  if(pos >= 0)
    printf("The desired pattern was found starting from position %d\n", pos+1);
  else
    printf("The pattern was not found in the given text\n");
  
  return 0;
}

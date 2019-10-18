#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gauss(float** ip, int n){
  float c,d;
  int q;
  for(int i=0; i<n; i++){
    if(ip[i][i]==0){ //checking 0's
      for(q=i; (ip[q][i]==0 && q<n-1); q++);
      if(q==n-1 && ip[q][i]==0){
        break;
      } else{
        for(int j=0; j<n; j++){
          ip[i][j] += ip[q][j];
        }
      }
    }
    c= ip[i][i];
    if(ip[i][i]!=0){
      for(int k=i+1; k<n; k++){
        d = ip[k][i];

        for(int j=0; j<n; j++){
          ip[i][j] = d/c*ip[i][j]; //multiplying row
        }

        for(int j=0; j<n; j++){
          ip[k][j] = ip[k][j] - ip[i][j]; //subtracting rows
          ip[i][j] = ip[i][j]*c/d;
        }
      }
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%.3f ", ip[i][j]);
    }
    printf("\n");
  }
  c= ip[0][0];
  for(int i=1; i<n; i++){
    c = c*ip[i][i];
  }
  printf("определитель = %.0f", c);
  
}

int main(void) {
  int n,m;
  float** ip;
  printf("type number of rows for random matrix and '-1' to create your own matrix: ");
  scanf("%d", &n);
  
  srand(time(NULL));
  
  if(n!=-1){
    ip = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
      ip[i] = (float*)malloc(n*sizeof(float));
    }
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        ip[i][j] = rand()%100;
      }
    }
  } else {
    printf("number of rows: ");
    scanf("%d", &m);
    n = m;
    ip = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++){
      ip[i] = (float*)malloc(n*sizeof(float));
    }
    printf("elements: ");
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        scanf("%f", &ip[i][j]);
      }
    }
    
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%.0f ", ip[i][j]);
    }
    printf("\n");
  }

  gauss(ip, n);

  return 0;
}

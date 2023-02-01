#include <stdio.h>
#include <time.h>

void merge(int array[], int a, int b, int c){
  int n1 = b - a + 1;
  int n2 = c - b;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = array[a + i];
  for (int j = 0; j < n2; j++)
    M[j] = array[b + 1 + j];

  int i = 0;
  int j = 0;
  int k = a;

  while (i < n1 && j < n2){
    if (L[i] <= M[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1){
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2){
    array[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int array[], int left, int right){
  if (left < right){
    int a = left + (right - left) / 2;

    mergeSort(array, left, a);
    mergeSort(array, a + 1, right);

    merge(array, left, a, right);
  }
}

int main(){
  FILE *input;
  input = fopen("input.txt", "r");
  int size = 6000;
  int array[size];
  int i;

  for (i = 0; i < size; i++){
    fscanf(input, "%d", &array[i]);
  }

  double time_spent = 0.0; 
  clock_t begin = clock();

  mergeSort(array, 0, size - 1);

  clock_t end = clock();
  time_spent += (double)(end - begin)*1000 / CLOCKS_PER_SEC; 

  for (int i = 0; i < size; ++i){
    printf("%d - ", array[i]);
  } 
  printf("\n%f ms", time_spent);
}

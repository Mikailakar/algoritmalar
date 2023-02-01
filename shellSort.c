#include <stdio.h>
#include <time.h>

void shellSort(int array[], int n){
  for (int interval = n / 2; interval > 0; interval /= 2){
    for (int i = interval; i < n; i += 1){
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval){
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
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

  shellSort(array, size);
  for (int i = 0; i < size; ++i){
    printf("%d - ", array[i]);
  }
 
  clock_t end = clock();
  time_spent += (double)(end - begin)*1000 / CLOCKS_PER_SEC; 
  printf("\n%f ms", time_spent);
}

#include <stdio.h>
#include <time.h>

void insertionSort(int array[], int size){
  for (int i = 1; i < size; i++){
    int temp = array[i];
    int j = i - 1;
    while (temp < array[j] && j >= 0){
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = temp;
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

  insertionSort(array, size);
  for (int i = 0; i < size; ++i){
    printf("%d - ", array[i]);
  }
 
  clock_t end = clock();
  time_spent += (double)(end - begin)*1000 / CLOCKS_PER_SEC; 
  printf("\n%f ms", time_spent);
}

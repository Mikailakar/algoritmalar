#include <stdio.h>
#include <time.h>

void selectionSort(int array[], int size){
  for (int i = 0; i < size - 1; i++){
    int min = i;
    for (int j = i + 1; j < size; j++){
      if (array[j] < array[min])
        min = j;
    }
    int temp = array[min];
    array[min] = array[i];
    array[i] = temp;
  }
}

int main(){
  FILE *input;
  input = fopen("sirali.txt", "r");
  int size = 6000;
  int array[size];
  int i;

  for (i = 0; i < size; i++){
    fscanf(input, "%d", &array[i]);
  }

  double time_spent = 0.0; 
  clock_t begin = clock();

  selectionSort(array, size);
  for (int i = 0; i < size; ++i){
    printf("%d - ", array[i]);
  }
 
  clock_t end = clock();
  time_spent += (double)(end - begin)*1000 / CLOCKS_PER_SEC; 
  printf("\n%f ms", time_spent);
}

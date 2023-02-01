#include <stdio.h>
#include <time.h>

void heap(int array[], int a, int i) {
  int max = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  
  if (left < a && array[left] > array[max])
    max = left;
  
  if (right < a && array[right] > array[max])
    max = right;
  
  if (max != i) {
    int temp = array[i];
    array[i] = array[max];
    array[max] = temp;

    heap(array, a, max);
  }
}
  
void heapSort(int array[], int a) {
  for (int i = a / 2 - 1; i >= 0; i--)
    heap(array, a, i);

  for (int i = a - 1; i >= 0; i--) {
    int temp = array[0];
    array[0] = array[i];
    array[i] = temp;

  heap(array, i, 0);
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

  heapSort(array, size);

  clock_t end = clock();
  time_spent += (double)(end - begin)*1000 / CLOCKS_PER_SEC; 

  for (int i = 0; i < size; ++i){
    printf("%d - ", array[i]);
  } 
  printf("\n%f ms", time_spent);
}

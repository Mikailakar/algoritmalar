#include <stdio.h>
#include <time.h>

void quickSort(int array[], int first, int last){
  if (first < last){
    int pivot = array[last];
    int i = (first - 1);

    for (int j = first; j < last; j++) {
      if (array[j] <= pivot) {
        i++;
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
      }
    }
    int s = array[i + 1];
    array[i + 1] = array[last];
    array[last] = s;
    
    int a = i + 1;
    quickSort(array, first, a - 1);
    quickSort(array, a + 1, last);
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

  quickSort(array, 0, size - 1);

  clock_t end = clock();
  time_spent += (double)(end - begin)*1000 / CLOCKS_PER_SEC; 

  for (int i = 0; i < size; ++i){
    printf("%d - ", array[i]);
  } 
  printf("\n%f ms", time_spent);
}

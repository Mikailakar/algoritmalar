#include <stdio.h>
#include <time.h>

void quickSort(int array[],int first,int last){
  if (first < last){
    int temp;
    int pivot = first;
    int i = first;
    int j = last;
    while (i < j){
      while (array[i] <= array[pivot] && i < last)
        i++;
      while (array[j] > array[pivot])
        j--;
      if (i < j){
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
  }

  temp=array[pivot];
    array[pivot]=array[j];
    array[j]=temp;
    quickSort(array,first,j-1);
    quickSort(array,j+1,last);
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

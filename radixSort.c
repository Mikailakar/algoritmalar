#include <stdio.h>
#include <time.h>

int getMax(int array[], int n){
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
 
void countSort(int array[], int size, int place){
    int output[size];
    int count[10] = { 0 };

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
 
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
 
    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixSort(int array[], int size){
    int max = getMax(array, size);
 
    for (int place = 1; max / place > 0; place *= 10)
        countSort(array, size, place);
}

int main(){
  FILE *input;
  input = fopen("n3_aralık3.txt", "r");
  int size = 10000;
  int array[size];
  int i;

  for (i = 0; i < size; i++){
    fscanf(input, "%d", &array[i]);
  }

  double time_spent = 0.0;
  clock_t begin = clock();

  radixSort(array, size);

  clock_t end = clock();
  time_spent += (double)(end - begin);

  for (int i = 0; i < size; ++i){
    printf("%d - ", array[i]);
  } 
  printf("\n%f ms", time_spent);
}

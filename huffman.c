#include <stdio.h>
#include <stdlib.h>

struct node{
  int isLeaf;
  int freq;
  char ch;
  char cd;
  struct node *left, *right;
};

void quickSort(int count[], char le[], int first, int last){
  if (first < last){
    int pivot = count[last];
    int i = (first - 1);

    for (int j = first; j < last; j++) {
      if (count[j] <= pivot) {
        i++;
        int t = count[i];
        count[i] = count[j];
        count[j] = t;
        char te = le[i];
        le[i] = le[j];
        le[j] = te;
      }
    }
    int s = count[i + 1];
    count[i + 1] = count[last];
    count[last] = s;
    char se = le[i + 1];
    le[i + 1] = le[last];
    le[last] = se;
    
    int a = i + 1;
    quickSort(count, le, first, a - 1);
    quickSort(count, le, a + 1, last);
  }
}

struct node *huffmanTree(int count[], char le[]){
  struct node *z = (struct node*)malloc(sizeof(struct node));
  z->isLeaf = 0;
  z->freq = count[0] + count[1];
  z->left = (struct node*)malloc(sizeof(struct node));
  z->left->isLeaf = 1;
  z->left->freq = count[0];
  z->left->ch = le[0];
  z->left->cd = '0';
  z->right = (struct node*)malloc(sizeof(struct node));
  z->right->isLeaf = 1;
  z->right->freq = count[1];
  z->right->ch = le[1];
  z->right->cd = '1';

  struct node *y;
  for(int i = 2; i < 6; i++){
    y = (struct node*)malloc(sizeof(struct node));
    y->isLeaf = 0;
    y->freq = z->freq + count[i];
    if(count[i] > z->freq){
      y->left = z;
      z->cd = '0';
      y->right = (struct node*)malloc(sizeof(struct node));
      y->right->isLeaf = 1;
      y->right->freq = count[i];
      y->right->ch = le[i];
      y->right->cd = '1';
      z = y;
    }
    else{
      y->right = z;
      z->cd = '1';
      y->left = (struct node*)malloc(sizeof(struct node));
      y->left->isLeaf = 1;
      y->left->freq = count[i];
      y->left->ch = le[i];
      y->left->cd = '0';
      z = y;
    }
  }
  return y;
}

int ind(int count, struct node *top){
  struct node *temp = top;
  int i = 0;
  while(temp->isLeaf != 1){
    if(temp->left->isLeaf == 1){
      if(temp->left->freq == count)
        temp = temp->left;
      else
        temp = temp->right;
      i++;
    }
    else{
      if(temp->right->freq == count)
        temp = temp->right;
      else
        temp = temp->left;
      i++;
    }
  }
  return i;
}

int lbin(int count, int ind, int j, struct node *top){
  struct node *temp = top;
  int bin[ind];
  int i = 0;
  while(temp->isLeaf != 1){
    if(temp->left->isLeaf == 1){
      if(temp->left->freq == count){
        temp = temp->left;
        bin[i] = 0;
      }else{
        temp = temp->right;
        bin[i] = 1;
      }
      i++;
    }
    else{
      if(temp->right->freq == count){
        temp = temp->right;
        bin[i] = 1;
      }else{
        temp = temp->left;
        bin[i] = 0;        
      }
      i++;
    }
  }
  
  return bin[j];
}

int findc(char le[], char let){
  int j;
  for(int i = 0; i < 6; i++){
    if(le[i] == let){
      j = i;
      i = 6;
    }
  }
  return j;
}

int main(){
  FILE *metin;
  metin = fopen("metin.txt", "r");
  int size = 1000000;
  char array[size];

  for(int i = 0; i < size; i++){
    fscanf(metin, "%c", &array[i]);
  }
  fclose(metin);

  char le[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int count[6] = {0, 0, 0, 0, 0, 0};

  for(int i = 0; i < size; i++){
    for(int j = 0; j < 6; j++){
      if(array[i] == le[j]){
        count[j]++;
        j = 6;
      }
    }
  }

  quickSort(count, le, 0, 5);

  struct node *top = huffmanTree(count, le);

  int bb = count[findc(le, 'a')];
  int aa = ind(bb, top);
  int a[aa];
  for(int i = 0; i < aa; i++){
    a[i] = lbin(bb, aa, i, top);
  }
  bb = count[findc(le, 'b')];
  aa = ind(bb, top);
  int b[aa];
  for(int i = 0; i < aa; i++){
    b[i] = lbin(bb, aa, i, top);
  }
  bb = count[findc(le, 'c')];
  aa = ind(bb, top);
  int c[aa];
  for(int i = 0; i < aa; i++){
    c[i] = lbin(bb, aa, i, top);
  }
  bb = count[findc(le, 'd')];
  aa = ind(bb, top);
  int d[aa];
  for(int i = 0; i < aa; i++){
    d[i] = lbin(bb, aa, i, top);
  }
  bb = count[findc(le, 'e')];
  aa = ind(bb, top);
  int e[aa];
  for(int i = 0; i < aa; i++){
    e[i] = lbin(bb, aa, i, top);
  }
  bb = count[findc(le, 'f')];
  aa = ind(bb, top);
  int f[aa];
  for(int i = 0; i < aa; i++){
    f[i] = lbin(bb, aa, i, top);
  }

  FILE *hb;
  hb = fopen("compressed.txt","w");

  for(int i = 0; i < size; i++){
    if(array[i] == 'a'){
      for(int j = 0; j < 3; j++){
        int hh = a[j];
        fprintf(hb, "%d", hh);
      }
      continue;
    }else if(array[i] == 'b'){
      for(int j = 0; j < 5; j++){
        int hh = b[j];
        fprintf(hb, "%d", hh);
      }
      continue;
    }else if(array[i] == 'c'){
        int hh = c[0];
        fprintf(hb, "%d", hh);
      continue;
    }else if(array[i] == 'd'){
      for(int j = 0; j < 2; j++){
        int hh = d[j];
        fprintf(hb, "%d", hh);
      }
      continue;
    }else if(array[i] == 'e'){
      for(int j = 0; j < 4; j++){
        int hh = e[j];
        fprintf(hb, "%d", hh);
      }
      continue;
    }else if(array[i] == 'f'){
      for(int j = 0; j < 5; j++){
        int hh = f[j];
        fprintf(hb, "%d", hh);
      }
      continue;
    }
  }
  fclose(hb);

  printf("Dosya huffman algoritmasiyla sikistirildi.");

  return 0;
}
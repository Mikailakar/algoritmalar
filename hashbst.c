#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	int value;
	struct node *left;
	struct node *right;
};

struct bst{
	struct node *head;
};
 
struct bst *array;
int size;
void displayt(struct node *node);
struct node* removee(struct node *temp, int value);

void init(){
    int i = 0;
    for(i = 0; i < size; i++){
       	array[i].head = NULL;
    }
}

void add(int value){
	int key = value%size;
	struct node *temp = array[key].head;
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->key = key;
	new->value = value;
	new->left = NULL;
	new->right = NULL;
 
	if(temp == NULL){
		array[key].head = new;
		printf("%d indexine %d elemani yerlestirildi\n", key, value);
	}
	else{
		while(temp != NULL){
			if(temp->value == value){
				printf("%d elemani zaten dizidedir!\n", value);
				return;
			}else if(temp->value < value){
				if(temp->right == NULL){
					temp->right = new;
					printf("%d indexine %d elemani yerlestirildi\n", key, value);
					return;
				}
				temp = temp->right;
			}else{
				if(temp->left == NULL){
					temp->left = new;
					printf("%d indexine %d elemani yerlestirildi\n", key, value);
					return;
				}
				temp = temp->left;
			}
		}
	} 
}

void display(){
	for(int i = 0; i < size; i++){
		printf("\narray[%d]: ", i);
		displayt(array[i].head);
	}
}

void displayt(struct node *node){
    if(node == NULL)
       	return;
    printf("%d ", node->value);
    if(node->left != NULL)
       	displayt(node->left);
    if(node->right != NULL)
       	displayt(node->right);
}

struct node* findn(struct node* temp, int value){
	if(temp == NULL)
		return NULL;
	if(temp->value > value)
		return findn(temp->left, value);
	if(temp->value < value)
		return findn(temp->right, value);
	if(temp->value == value)
		return temp;
}

void delete(int value){
   	int i = value%size;
   	struct node *temp = (struct node*)array[i].head;	
   	if(findn(temp, value) == NULL){
       	printf("%d elemani dizide bulunamadi!\n", value);
   	}else{
		temp = removee(temp, value);
       	array[i].head = temp;
		printf("%d elemani diziden silindi\n", value);
   	}
}
 
struct node* removee(struct node *temp, int value){
    if(temp == NULL){
      	return NULL;
    }
    if(temp->value > value){
       	temp->left = removee(temp->left, value);
       	return temp;
    }else if(temp->value < value){
       	temp->right = removee(temp->right, value);
       	return temp;
    }else{
       	if(temp->left == NULL  &&  temp->right == NULL){
        	return NULL;
       	}else if(temp->left != NULL  &&  temp->right == NULL){
            return temp->left;
        }else if(temp->left == NULL  &&  temp->right != NULL){
            return temp->right;
       	}else{
         	struct node *leftn = temp->left;
        	while (leftn->right != NULL){
                leftn = leftn->right;
            }
            temp->value = leftn->value;
            temp->left = removee(temp->left, temp->value);
            return temp;
        }
    }
}
 
int main(){
	printf("Dizinin boyutunu girin: ");
 	scanf("%d", &size); 
	while(size == 0){
		printf("HATALI GIRIS!!!\n\n");
		printf("Dizinin boyutunu girin: ");
 		scanf("%d", &size);
	}
	array = (struct bst*)malloc(size * sizeof(struct bst*));

    int input, value;
	int c = 1;
	init();
 
	while(c == 1){
		display();
		printf("\n\n1.Hash tablosuna eleman ekle\n2.Hash tablosundan eleman sil\n3.Programi sonlandir\n-> "); 
 		scanf("%d", &input); 
		switch(input){ 
		case 1:
		    printf("Eleman girin: ");
		    scanf("%d", &value);
		    add(value); 
		    break; 
		case 2: 
		    printf("Silinecek elemani girin: ");
		    scanf("%d", &value);
		    delete(value); 
		    break;
		case 3:
			c = 0;
			break;
		default: 
		    printf("HATALI GIRIS!!!\n"); 
		}
	}

	return 0;
}

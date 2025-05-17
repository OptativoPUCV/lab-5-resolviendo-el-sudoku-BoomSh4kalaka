#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
    int array[10];
    for (int i=0;i<9;i++) 
    {
      for (int k=0;k<10;k++)
        array[k]=0;
      
      for (int j=0;j<9;j++)
      {
        int num = n->sudo[i][j];
        if (num == 0) continue;
        if (array[num]) return 0;
        array[num] = 1;
      }
    }

    for (int j =0;j<9;j++) 
    {
      for (int k=0;k<10;k++)
        array[k]=0;
      
      for (int i=0;i<9;i++)
      {
        int num = n->sudo[i][j];
        if (num == 0) continue;
        if (array[num]) return 0;
        array[num] = 1;
      }
    }

    for (int k = 0 ; k < 9 ; k++) {
      for (int i = 0 ; i < 10 ; i++) array[i] = 0;
      for (int a = 0 ; a < 9 ; a++) {
        int row = (k / 3) * 3 + (a / 3);
        int col = (k % 3) * 3 + (a % 3);
        int num = n->sudo[row][col];
        if (num != 0) {
          if (array[num]) return 0;
          array[num] = 1;
        }
      }
    }
    return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int row, col;
    for(row=0;row<9;row++){
        for(col=0;col<9;col++){
            if(n->sudo[row][col]==0){
                int i;
                for(i=1;i<=9;i++){
                    Node* new=copy(n);
                    new->sudo[row][col]=i;
                    pushBack(list, new);
                }
                return list;
            }
        }
    } 

    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/
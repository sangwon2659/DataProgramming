#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 8

void main(){
        short cell[MAX][MAX] = {0};
        int count = 0;
        int x,y;
        srand(time(NULL));
        for(int i=0; i<10; i++){
                x = rand()%MAX; y=rand()%MAX;
                if(cell[x][y] == 0){
                        cell[x][y] = '*';
                }
        }

        for(int i=0; i<MAX; i++){
                for(int j=0; j<MAX; j++){
                        if(cell[i][j] != '*'){
                                for(int k=i-1; k<=i+1; k++){
                                        for(int l=j-1; l<=j+1; l++){
                                                if(k>= 0 && k<=MAX && l>=0 && l<=MAX && cell[k][l] == '*'){
                                                        count++;
                                                }
                                        }
                                }
                                cell[i][j] = count;
                                count = 0;
                        }
                }
        }

        for(int i=0; i<MAX; i++){
                for(int j=0; j<MAX; j++){
                        if(cell[i][j] == '*') printf("*");
                        else{
                        printf("%d", cell[i][j]);
                        }
                }
                printf("\n");
        }
}


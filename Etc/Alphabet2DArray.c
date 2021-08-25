#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char array[6][5];
int i, j, count;

void main(){
        for(i=0; i<5; i++){
                for(j=0; j<5; j++){
                        array[i][j] = 'a' + count;
                        count++;
                        printf("%c ", array[i][j]);
                }
                printf("\n");
        }
        array[6][0] = 'z';
        printf("z");
        printf("\n");
        printf("\n");

        count = 0;
        for(i=4; i>=0; i--){
                for(j=4; j>=0; j--){
                        array[j][i] = 'a' + count;
                        count++;
                }
        }
        array[6][0] = 'z';

        for(i=0; i<5; i++){
                for(j=0; j<5; j++){
                        printf("%c ", array[i][j]);
                }
                printf("\n");
        }
        printf("%c ", array[6][0]);
        printf("\n");
}


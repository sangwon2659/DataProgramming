#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i;
int A[10] = {0};
int max = 0, min = 100;

int maximum(int A[10]){
        for(i=0; i<10; i++){
                if(A[i] > max) max = A[i];
        }
        return max;
}

int minimum(int A[10]){
        for(i=0; i<10; i++){
                if(A[i] < min) min = A[i];
        }
        return min;
}

void main(){
        srand(time(NULL));
        for(i=0; i<10; i++){
                A[i] = rand()%100;
        }

        max = maximum(A);
        min = minimum(A);

        printf("Max number is: %d Min number is: %d\n", max, min);
}


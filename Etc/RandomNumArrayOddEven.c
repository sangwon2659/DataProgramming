#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int A[20], odd[20], even[20];
int odd_count=0, even_count=0;

void main(){
        srand(time(NULL));
        for(int i=0; i<20; i++){
                A[i] = rand()%100;
                if(A[i]%2==0){
                        even[even_count++] = A[i];
                }
                else{
                        odd[odd_count++] = A[i];
                }
        }
        printf("Number of element in even array: %d\n", even_count);
        printf("Number of element in odd array: %d\n", odd_count);
        printf("Elements in even array: ");
        for(int i=0; i<even_count; i++){
                printf("%d ", even[i]);
        }
        printf("\n");
        printf("Elements in odd array: ");
        for(int i=0; i<odd_count; i++){
                printf("%d ", odd[i]);
        }
        printf("\n");
}


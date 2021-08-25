#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void main(){
        int a, i, j, k, l;
        int n_ODD=0, n_A=0, count=0;
        int A[100];
        int OK[100], ODD[100];
        srand(8);

        for(i=0; i<20; i++){
                OK[i] = rand()%100 + 1;
        }

        for(i=0; i<20; i++){
                for(j=i+1; j<20; j++){
                        if(OK[i] > OK[j]){
                                a = OK[i];
                                OK[i] = OK[j];
                                OK[j] = a;
                        }
                }
        }

        printf("OK list: ");
        for(i=0; i<20; i++){
                printf("%d ", OK[i]);
        }
        printf("\n");


        for(i=0; i<20; i++){
                if(OK[i]%2==1){
                       ODD[n_ODD]=OK[i];
                       OK[i] = 0;
                       n_ODD++;
                }
        }

        for(i=0; i<20; i++){
                if(OK[i]>0){
                        A[n_A]=OK[i];
                        n_A++;
                }
                OK[i]=0;
        }
        for(i=0; i<(20-n_ODD); i++){
                OK[i] = A[i];
        }

        printf("OK list: ");
        for(i=0; i<(20-n_ODD); i++){
                printf("%d ", OK[i]);
        }

        printf("ODD list: ");
        for(i=0; i<n_ODD; i++){
                printf("%d ", ODD[i]);
        }
        printf("\n");

        n_A = 0;

        for(i=0; i<n_ODD; i++){
                for(j=1; j<101; j++){
                        if(ODD[i]%j==0){
                                count++;
                        }
                }
                if(count==2){
                        A[n_A] = ODD[i];
                        n_A++;
                        for(k=0; k<(20-n_ODD+n_A); k++){
                                if(ODD[i]<OK[k]){
                                        for(l=(20-n_ODD+n_A); l>=k; l--){
                                                OK[l+1] = OK[l];
                                        }
                                        OK[k] = ODD[i];
                                        break;
                                }
                        }
                        for(k=i; k<n_ODD-1; k++){
                                ODD[k] = ODD[k+1];
                        }
                }
                count=0;
        }

        printf("Prime number: ");
        for(i=0; i<n_A; i++){
                printf("%d ", A[i]);
        }
        printf("\n");

        printf("OK list: ");
        for(i=0; i<(20-n_ODD+n_A); i++){
                printf("%d ", OK[i]);
        }

        printf("   ODD list: ");
        for(i=0; i<(n_ODD-n_A); i++){
                printf("%d ", ODD[i]);
        }
        printf("\n");

}


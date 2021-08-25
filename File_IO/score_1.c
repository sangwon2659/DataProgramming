#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i, j, num1, num2;
float a, avg_;
float avg_array[6];
int prevent[6] = {0};
char string[100];
FILE *fp1, *fp2, *wp1, *wp2;
struct score_{
        char name[20];
        int score1;
        int score2;
        float avg;
};
struct score_ score[6];

void main(){
        fp1 = fopen("name.txt", "r");
        for(i=0; i<6; i++){
                fscanf(fp1, "%s", string);
                strcpy(score[i].name, string);
        }
        fclose(fp1);

        fp2 = fopen("num.txt", "r");
        for(i=0; i<6; i++){
                fscanf(fp2, "%d", &num1);
                fscanf(fp2, "%d", &num2);
                score[i].score1 = num1;
                score[i].score2 = num2;
        }
        fclose(fp2);

        wp1 = fopen("new1.txt", "w");
        for(i=0; i<6; i++){
                avg_ = (score[i].score1+score[i].score2)/2;
                avg_array[i] = avg_;
                score[i].avg = avg_;
                fprintf(wp1, "%s %d %d %f\n", score[i].name, score[i].score1, score[i].score2, score[i].avg);
        }

        for(i=0; i<6; i++){
                for(j=i+1; j<6; j++){
                        if(avg_array[i] < avg_array[j]){
                                a = avg_array[i];
                                avg_array[i] = avg_array[j];
                                avg_array[j] = a;
                        }
                }
        }
        fclose(wp1);

        wp2 = fopen("new2.txt", "w");
        for(i=0; i<6; i++){
                for(j=0; j<6; j++){
                        if(avg_array[i] == score[j].avg && prevent[j] == 0){
                                fprintf(wp2, "%s %d %d %f\n", score[j].name,
                                                score[j].score1, score[j].score2, score[j].avg);
                                prevent[j] = 1;
                                break;
                        }
                }
        }
        fclose(wp2);
}

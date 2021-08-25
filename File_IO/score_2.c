#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int i, j, num, best_score1, best_improvement, best_avg_, best_score1_, best_improvement_;
float avg, best_avg;
struct score_{
        char name[20];
        int score1;
        int score2;
        float avg;
};
struct score_ score[7];
float max = 0.0;
int max_ = 0;
int improvement;
char string[100];
FILE *fp1, *fp2, *wp1, *wp2;

void main(){
        fp1 = fopen("score1.txt", "r");
        for(i=0; i<7; i++){
                fscanf(fp1, "%s", string);
                strcpy(score[i].name, string);
                fscanf(fp1, "%d", &num);
                score[i].score1 = num;
        }
        fclose(fp1);

        fp2 = fopen("score2.txt", "r");
        for(i=0; i<7; i++){
                fscanf(fp2, "%s", string);
                fscanf(fp2, "%d", &num);
                for(j=0; j<7; j++){
                        if(strcmp(score[j].name,string)==0){
                                score[j].score2 = num;
                        }
                }
        }
        fclose(fp2);

        wp1 = fopen("new1.txt", "w");
        for(i=0; i<7; i++){
                avg = (score[i].score1+score[i].score2)/2;
                score[i].avg = avg;
                fprintf(wp1, "%s %d %d %.1f\n", score[i].name, score[i].score1, score[i].score2, score[i].avg);
        }
        fclose(wp1);

        for(i=0; i<7; i++){
                if(score[i].avg > max){
                        max = score[i].avg;
                        best_avg_ = i;
                }
        }
        best_avg = max;

        for(i=0; i<7; i++){
                if(score[i].score1 > max_){
                        max_ = score[i].score1;
                        best_score1_ = i;
                }
        }
        best_score1 = max_;

        max_ = 0;
        for(i=0; i<7; i++){
                improvement = score[i].score2 - score[i].score1;
                if(improvement > max_){
                        max_ = improvement;
                        best_improvement_ = i;
                }
        }
        best_improvement = max_;

        wp2 = fopen("new2.txt", "w");
        fprintf(wp2, "Best avg. score: %s\n", score[best_avg_].name);
        fprintf(wp2, "Best score1: %s\n", score[best_score1_].name);
        fprintf(wp2, "Best score improvement: %s\n", score[best_improvement_].name);
}


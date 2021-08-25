#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char c;
int i, tag;
int alp_count = 0, cap_count = 0, small_count = 0, line_count = 0, word_count = 0;
int longest_count = 0, the_count = 0, trees_count = 0, count = 0, val = 0;
int max = 0;
char A[100];
char Longest[100];
FILE *fp;
char dictionary[1000][100];

void main(){
        fp = fopen("tree.txt", "r");
        while((c=fgetc(fp)) != EOF) {
                if(c == '\n') line_count++;
                if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
                        if(c >= 'A' && c <= 'Z') cap_count++;
                        else if(c >= 'a' && c <= 'z') small_count++;
                        alp_count++;
                        A[i++] = c;
                        tag = 1;
                }
                else if(tag){
                        A[i] = '\0';
                        i = 0;
                        tag = 0;
                        if(strlen(A) >= max){
				if(strlen(A)>max) longest_count = 0;
                                max = strlen(A);
                                strcpy(Longest, A);
				if(strcmp(A,Longest) == 0) longest_count++;
                        }
			word_count++;
			strcpy(dictionary[count++], A);
                }
		if(strcmp(A,"The")==0 || strcmp(A,"the")==0) the_count++;
        	if(strcmp(A,"Trees")==0 || strcmp(A,"trees")==0) trees_count++;
	}

	for(i=0; i<count; i++)
		printf("%s \n", dictionary[i]);

        printf("Number of alphabet: %d\n", alp_count);
        printf("Number of cap letters: %d\n", cap_count);
        printf("Number of small letters: %d\n", small_count);
        printf("Number of lines: %d\n", line_count);
        printf("Number of words: %d\n", word_count);
        printf("Longest word: %s Repeated %d times\n", Longest, longest_count);
	printf("Number of the word tree: %d\n", the_count);
	printf("Number of the word trees: %d\n", trees_count);
}


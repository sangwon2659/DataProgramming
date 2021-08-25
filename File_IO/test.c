#include <stdio.h>
#include <string.h>
void main()
{
 char c; char dictionary[200][100]; char A[100];
 int i, count; int tag = 0;
 FILE *fp;
 i=0; count = 0;
 fp = fopen("tree.txt", "r");
 while((c=fgetc(fp)) != EOF) {
 putchar(c);
 if (c >= 'a' && c <= 'z') { A[i++] = c; tag = 1; }
 else if (tag) { A[i] = '\0'; i = 0;
 strcpy(dictionary[count++], A);
 tag = 0; }
 }
 for(i=0; i < count; i++)
 printf("%s \n", dictionary[i]);
 fclose(fp);
}

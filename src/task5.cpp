#include <malloc.h>

void split(char ***result, int *N, char *buf, char ch){
    int counter=0;
    for (int i=0;buf[i]!='\0';i++)          //count words
        if (buf[i]==ch)
            counter++;
    *result=(char**)malloc((counter+1)*sizeof(char**));
    int last=0;
    int i=0;
    for (;buf[i]!='\0';i++){
        if (buf[i]==ch){                    //if got a separator add word
            char* c = (char*) malloc(i-last+1);
            c[i-last]='\0';
            for (int j=last;j<i;j++)        //create new str and copy word
                c[j-last]=buf[j];
            (*result)[(*N)]=c;
            *N=*N+1;
            last=i+1;
        }
    }
    char* c = (char*) malloc(i-last+1);     //add last word
    c[i-last]='\0';
    for (int j=last;j<i;j++)
        c[j-last]=buf[j];
    (*result)[(*N)]=c;
    *N=*N+1;
}
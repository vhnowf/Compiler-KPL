#include<stdio.h>
#include"list.h"
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

void readFileStopWord(LISTSW* lsw, char *filename){
    int num;
    FILE *file;
    char buff[MAX];
    if((file = fopen(filename,"r"))==NULL){
        printf("Can not open file.\n");
    } else{
    while (fscanf(file, "%s", buff) != EOF) {
        InsertSW(lsw,buff); 
        }
    }
}
void readFile(LLIST* l,LISTSW *lsw, LISTL *ll,char *filename){
    FILE *file;
    int c;
    int flag_1;
    int flag_2;
    int flag_3 = 1;
    int flag_4;
    int i = 0, line = 1;
    if((file = fopen(filename,"r"))==NULL){
        printf("Can not open file.\n");
    } else{
            char word[MAX];
            while((c = fgetc(file)) != EOF) {
                if(!isalpha(c)){
                        if(c == '.' || c == '\n'){
                            flag_1 = 1;
                        } else flag_1 = 0;
                        if(isupper(word[0])){
                            flag_2 = 1;
                        } else flag_2 = 0;
                        if(flag_2 == 1 && flag_3 == 0){
                            flag_4 = 1;
                        } else flag_4 = 0;
                        word[i] = '\0';
                        if(flag_4 == 0 && searchStopWord(lsw,word)!=0 && strlen(word)>1 ){
                            for(int j=0; j<strlen(word); j++){
                                word[j] = tolower(word[j]);
                            }
                            InsertList(l,word,line);
                        } 
                        if(c == '\n'){
                            line++;
                        }
                        flag_3 = flag_1;
                        i = 0;
                        
                
            }
             else {
                    word[i] = c;
                    i++;
                }
        }
    }
}

int main(int argc, char* argv[]) {
    LISTSW lsw = NULL;
    LLIST l = NULL;
    LISTL ll = NULL;
    readFileStopWord(&lsw,argv[1]);
    readFile(&l,&lsw,&ll,argv[2]);
    TraverseLink(&l);
}


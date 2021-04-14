#include "list.h"
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>

void InsertSW(LISTSW* lsw, char data[MAX]) {
    LIST_SW* e = (LIST_SW*)malloc(sizeof(LIST_SW));
	strcpy(e->word,data);
	e->next = *lsw;
	*lsw = (LISTSW)e;
}
int searchStopWord(LISTSW *lsw, char *word){
    LIST_SW* tmp;
    tmp = *lsw;
    while(tmp != NULL){
        if(strcmp(word,tmp->word)==0){
            return 0;
        }
        tmp = tmp->next;
    }
    return 1;
}
LIST_LINE *InitLineList(int line){
    LIST_LINE *root = malloc(sizeof(LIST_LINE));
    root->line = line;
    return root;
};
LIST_LINE* searchLineList(LIST_LINE *list,int line) {
    LIST_LINE *node = NULL;
    LIST_LINE *tmp = list;
    while(tmp != NULL) {
        if(tmp->line == line){
        node = tmp;
        break;
        }
        tmp = tmp->next;
    }
    return node;
}
void InsertLineList(LISTL *ll, int line){
    LIST_LINE *new_node = InitLineList(line);
    if(*ll == NULL || (*ll)->line > line){
        new_node->next = *ll;
        *ll = new_node;
    } else {
        LIST_LINE *cur = *ll;
        while(cur->next != NULL && cur->next->line < line){
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }
    
}
LIST_ELEM *searchList(LIST_ELEM *list, char *word){
    LIST_ELEM *node = NULL;
    LIST_ELEM *tmp = list;
    while(tmp != NULL) {
        if(strcmp(tmp->data,word)==0){
        node = tmp;
        break;
        }
        tmp = tmp->next;
    }
    return node;
}
LIST_ELEM *InitList(char *word,int line){
    LIST_ELEM *root = malloc(sizeof(LIST_ELEM));
    strcpy(root->data,word);
    InsertLineList(&(root->lline),line);
    root->count = 1;
    root->next = NULL;
    return root;
};
void TraverseLine(LIST_LINE *l){
    LIST_LINE *p = l;
    while(p != NULL){
        printf(" %d",p->line);
        p = p->next;
    }
}
void TraverseLink(LLIST* l){
    LIST_ELEM* p;
    p = *l;
    while(p != NULL){
        printf("%s %d",p->data,p->count);
        LIST_LINE *tmp;
        tmp = p->lline;
        TraverseLine(tmp);
        printf("\n");
        p = p->next;
    }
	
}
void InsertList(LLIST *l, char *word, int line){

        LIST_ELEM *result;
        if((result = searchList(*l,word))!=NULL){
            result->count++;
            LIST_LINE *check = searchLineList(result->lline,line);
            if (check == NULL){
            InsertLineList(&(result->lline),line);
            }
        }else {
            LIST_ELEM *new_node = InitList(word,line);
            if(*l == NULL){
               *l = new_node;
            } else if (strcmp((*l)->data,word)>0){
                new_node->next = *l;
                *l = new_node;
            }
            else{
                LIST_ELEM *cur = *l;
                while(cur->next != NULL && strcmp(cur->next->data,word)<0){
                    cur = cur->next;
                }
                new_node->next = cur->next;
                cur->next = new_node;
        
            }
    }
}
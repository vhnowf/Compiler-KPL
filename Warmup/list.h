// singly-linked list with static data type

#ifndef __LLIST_H__
#define __LLIST_H__

#ifdef __cplusplus
extern "C" {
#endif
#define MAX 100
typedef struct _LIST_ELEM LIST_ELEM, *LLIST;
typedef struct _LIST_LINE LIST_LINE, *LISTL;
typedef struct _LIST_SW LIST_SW, *LISTSW;
struct _LIST_LINE{
    int line;
    LIST_LINE *next;
};
struct _LIST_ELEM {
	char data[MAX];
    int count;
    LIST_LINE *lline;
	LIST_ELEM *next;
};
struct _LIST_SW{
    char word[MAX];
    LIST_SW *next;
};




void InsertSW(LISTSW* lsw, char data[MAX]);
int searchStopWord(LISTSW *lsw, char *word);
LIST_LINE *InitLineList(int line);
LIST_LINE* searchLineList(LIST_LINE *list,int line);
void InsertLineList(LISTL *ll, int line);
LIST_ELEM *searchList(LIST_ELEM *list, char *word);
LIST_ELEM *InitList(char *word,int line);
void TraverseLine(LIST_LINE *l);
void TraverseLink(LLIST* l);
void InsertList(LLIST *l, char *word, int line);



#ifdef __cplusplus
}
#endif


#endif // __LLIST_H__
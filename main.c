/**2-1單鏈表插入
 * 编写一个在单链表中数据域值为a的结点之后，
 * 插入一个新结点的算法，如果链表中没有数据域值为a的结点，
 * 则把新结点插入到表尾.
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int DataType ;

typedef struct Node{
    DataType  data ;
    struct Node *next ;
}SLNode;

//初始化鏈表空間以及數據
void ListInitiate(SLNode **head){
    *head = (SLNode *)malloc(sizeof(SLNode)) ;//給頭節點申請空間
    (*head)->next = NULL ;
}

//得到當前鏈表的節點個數
int ListLength(SLNode *head){
    SLNode *p = head ;
    int size = 0 ;
    while(p != NULL){
        p = p->next ;
        size ++ ;
    }
    return size ;
}
/*******************************************************/
//在數據與爲a的節點後插入新節點,考慮異常情況
int ListInsert(SLNode *head, int a, DataType s){
    SLNode *p, *q ;
    p = head ;
    while (p->next != NULL && p->data != a){
        p = p->next ;
    }
    if(p->next == NULL && p->data != a){
        printf("抱歉沒有找到數據與爲a的節點,那麼就默認插到連尾") ;
        q = (SLNode *)malloc(sizeof(SLNode)) ;
        p->next = q ;
        q->next = NULL ;
        q->data = s ;
        printf("尾插入成功") ;
        return 1 ;
    }
    else{//找到了

        q = (SLNode *)malloc(sizeof(SLNode)) ;
        q->next = p->next ;
        q->data = s ;
        p->next = q ;
        return 1;
    }
}
/*******************************************************/
//輸入現有鏈表裏面的數據
void ListPrint(SLNode *head){
    SLNode *p = head ;
    while(p->next != NULL){
        printf("  %d", p->data) ;
        p = p->next ;
    }
}

int main() {
    printf("Hello, World!\n");
    SLNode *head ;
    ListInitiate(&head) ;
    for (int i = 0; i < 10; ++i) {
        ListInsert(head, i, i+1) ;
    }

    ListPrint(head) ;
    return 0;
}
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
//("抱歉沒有找到數據與爲a的節點,那麼就默認插到連尾") ;
int ListInsert(SLNode *head, DataType a){
    SLNode *p, *q ;
    p = head ;
    while (p->next != NULL && p->data != a){
        p = p->next ;
    }
    if(p->next == NULL && p->data != a){

        q = (SLNode *)malloc(sizeof(SLNode)) ;
        p->next = q ;
        q->next = NULL ;
        q->data = a ;
        //printf("尾插入成功\n") ;
        return 1 ;
    }
    else{//找到了

        q = (SLNode *)malloc(sizeof(SLNode)) ;
        q->next = p->next ;
        q->data = a ;
        p->next = q ;
        return 1;
    }
}
/*******************************************************/
//輸入現有鏈表裏面的數據
void ListPrint(SLNode *head){
    SLNode *p = head->next ;
    while(p != NULL){
        printf("%-4d", p->data) ;
        p = p->next ;
    }
}

int main() {
    printf("Hello, World!\n");
    SLNode *head ;
    ListInitiate(&head) ;
    for (int i = 0; i < 10; ++i) {
        ListInsert(head, i+1) ;
    }

    int index = 7 ;
    int non = 20 ;

    ListInsert(head, index) ;//验证第一种情况
    ListInsert(head, non) ;//验证第二种情况
    ListPrint(head) ;
    return 0;
}
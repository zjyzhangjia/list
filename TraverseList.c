#include "stdio.h"
#include "traverselist.h"

//    定义链表遍历函数
void TraverseList(PNode List) {
    PNode P = List->Next;    //    首节点赋值给临时节点P
    printf("遍历链表的值为：");
    if (P == NULL)
        printf("链表为空");
    while (P != NULL)        //当临时节点P不为尾节点时，输出当前节点值 
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}
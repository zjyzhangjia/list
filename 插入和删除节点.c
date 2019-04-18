#include "stdio.h"
#include "InsertList.h"
#include "DeleteList.h"

//     定义链表插入函数
//    在链表位置第pos节点前插入包含数据val的节点
void InsertList(PNode List, int pos, int val) {
	int position = 0;
	PNode P = List;    //    定义节点p指向头节点
	//    寻找pos节点的前驱结点
	while (P != NULL&&position<pos - 1)
	{
		P = P->Next;
		++position;
	}
	PNode Tmp = (PNode)malloc(sizeof(Node));    //    分配一个临时节点用来存储要插入的数据
	if (Tmp == NULL)
	{
		printf("内存分配失败！");
		exit(-1);
	}
	//    插入节点
	Tmp->Element = val;
	Tmp->Next = P->Next;
	P->Next = Tmp;
}


//   定义删除链表元素函数
//    删除链表中的第pos节点
void DeleteList(PNode List, int pos) {
	int position = 0;
	PNode P = List;    //    定义一个指针p指向链表头节点
	//    寻找pos节点位置的前驱节点
	while (P != NULL&&position < pos - 1) {
		P = P->Next;
		++position;
	}

	//    删除节点
	PNode Tmp = P->Next;    //    定义临时指针Tmp指向要删除的节点
	P->Next = Tmp->Next;    //    使要删除节点的前驱结点指向其后驱节点
	free(Tmp);    //    释放删除节点的内存空间，防止内存泄漏
	Tmp = NULL;    //    使q指向空指针，防止产生野指针
}
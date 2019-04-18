#include "stdio.h"
#include "InsertList.h"
#include "DeleteList.h"

//     ����������뺯��
//    ������λ�õ�pos�ڵ�ǰ�����������val�Ľڵ�
void InsertList(PNode List, int pos, int val) {
	int position = 0;
	PNode P = List;    //    ����ڵ�pָ��ͷ�ڵ�
	//    Ѱ��pos�ڵ��ǰ�����
	while (P != NULL&&position<pos - 1)
	{
		P = P->Next;
		++position;
	}
	PNode Tmp = (PNode)malloc(sizeof(Node));    //    ����һ����ʱ�ڵ������洢Ҫ���������
	if (Tmp == NULL)
	{
		printf("�ڴ����ʧ�ܣ�");
		exit(-1);
	}
	//    ����ڵ�
	Tmp->Element = val;
	Tmp->Next = P->Next;
	P->Next = Tmp;
}


//   ����ɾ������Ԫ�غ���
//    ɾ�������еĵ�pos�ڵ�
void DeleteList(PNode List, int pos) {
	int position = 0;
	PNode P = List;    //    ����һ��ָ��pָ������ͷ�ڵ�
	//    Ѱ��pos�ڵ�λ�õ�ǰ���ڵ�
	while (P != NULL&&position < pos - 1) {
		P = P->Next;
		++position;
	}

	//    ɾ���ڵ�
	PNode Tmp = P->Next;    //    ������ʱָ��Tmpָ��Ҫɾ���Ľڵ�
	P->Next = Tmp->Next;    //    ʹҪɾ���ڵ��ǰ�����ָ��������ڵ�
	free(Tmp);    //    �ͷ�ɾ���ڵ���ڴ�ռ䣬��ֹ�ڴ�й©
	Tmp = NULL;    //    ʹqָ���ָ�룬��ֹ����Ұָ��
}
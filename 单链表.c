#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;  //������
	struct Node* next;  //ָ����
};

struct Node* creatList()  //�����б�
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));//��̬�ڴ����룬headNode��Ϊ�ṹ�����
	//����ʹ��ǰ��ʼ��
	//headNode->data = 1;
	headNode->next = NULL;
	return headNode;
};

struct Node* creatNode(int data)  //�����ڵ�
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void printList(struct Node* headNode)  //ִ�������ڵ�����û�з���ֵ,�����ڵ�
{
	struct Node* pMove = headNode->next;
	while (pMove)//���ڵ㲻Ϊ����ʼ��ӡ
	{
		printf("%d\t", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

//����ڵ㣬�����������Ǹ���������ڵ�������Ƕ��٣�����ͷ��
void insertNodeByHead(struct Node* headNode, int data)
{
	//1��������ڵ�
	struct Node* newNode = creatNode(data);
	//���ܲ嵽headNodeǰ��
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//ɾ���ڵ�
void deletNodeByAppoin(struct Node* headNode,int posData)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)//�ж��б��Ƿ�Ϊ��
		printf("�޷�ɾ���б�Ϊ��\n");
	else
	{
		while (posNode->data != posData)
		{
			posNodeFront = posNode;
			posNode = posNode->next;
			if (posNode==NULL)//˵���ҵ��˱�β
			{
				printf("û���ҵ������Ϣ���޷�ɾ��\n");
				return;
			}
		}
		posNodeFront->next = posNode->next;
		free(posNode);//��freeɾ��posNode�ڵ�
	}
}



int main()
{
	//struct Node Node1 = { 1, NULL };   //1�����ݣ�null��ָ��
	//struct Node Node2 = { 2, NULL };
	//struct Node Node3 = { 3, NULL };    //�ṹ�����
	//Node1.next = &Node2;   //��Node1��ָ��ָ��Node2
	//Node2.next = &Node3;   //��Node2��ָ��ָ��Node3,....��̬�б�
	struct Node* list = creatList();
	insertNodeByHead(list, 1);
	insertNodeByHead(list, 2);
	insertNodeByHead(list, 3);
	printList(list);

	deletNodeByAppoin(list, 2);
	printList(list);

	system("pause");
	return 0;
}
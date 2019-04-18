#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;  //数据域
	struct Node* next;  //指针域
};

struct Node* creatList()  //创建列表
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));//动态内存申请，headNode成为结构体变量
	//变量使用前初始化
	//headNode->data = 1;
	headNode->next = NULL;
	return headNode;
};

struct Node* creatNode(int data)  //创建节点
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void printList(struct Node* headNode)  //执行括号内的内容没有返回值,遍历节点
{
	struct Node* pMove = headNode->next;
	while (pMove)//当节点不为空则开始打印
	{
		printf("%d\t", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

//插入节点，参数：插入那个链表，插入节点的数据是多少，采用头插
void insertNodeByHead(struct Node* headNode, int data)
{
	//1创建插入节点
	struct Node* newNode = creatNode(data);
	//不能插到headNode前面
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//删除节点
void deletNodeByAppoin(struct Node* headNode,int posData)
{
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)//判断列表是否为空
		printf("无法删除列表为空\n");
	else
	{
		while (posNode->data != posData)
		{
			posNodeFront = posNode;
			posNode = posNode->next;
			if (posNode==NULL)//说明找到了表尾
			{
				printf("没有找到相关信息，无法删除\n");
				return;
			}
		}
		posNodeFront->next = posNode->next;
		free(posNode);//用free删除posNode节点
	}
}



int main()
{
	//struct Node Node1 = { 1, NULL };   //1是数据，null是指针
	//struct Node Node2 = { 2, NULL };
	//struct Node Node3 = { 3, NULL };    //结构体变量
	//Node1.next = &Node2;   //将Node1的指针指向Node2
	//Node2.next = &Node3;   //将Node2的指针指向Node3,....静态列表
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
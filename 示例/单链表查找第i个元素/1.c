#include <stdio.h>
#include <stdlib.h>

typedef int ElementType; //   定义数据类型,可根据需要进行其他类型定义

typedef struct ListNode {
	ElementType Element; // 数据域
	struct ListNode *Next; // 指针域

} Node , *PNode;

PNode CreateList(void);        //    声明创建链表函数
void TraverseList(PNode List); //    声明遍历链表函数
PNode FindList(PNode List);    //    声明查找函数
void insertList(PNode list, int pos, int val); // 声明插入函数
void DeleteTheList(PNode List); // 定义删除整个链表
void DeleteList(PNode List, int pos); // 删除某个节点

int main(){
	

	PNode List = CreateList();    //创建一个指针，使其指向新创建的链表的头指针
	// insertList(List, 2, 8);
	// TraverseList(List);
	// FindList(List);
	// DeleteTheList(List);
	DeleteList(List,1);

	
	
	return 0;
}

PNode CreateList(void) {
	int len;  //    用于定义链表长度
	int val;  //    用于存放节点数值


	PNode Phead = (PNode)malloc(sizeof(Node)); //    创建分配一个头节点内存空间
//头节点相当于链表的哨兵，不存放数据，指向首节点（第一个节点）

	if (Phead == NULL) //    判断是否分配成功
	{
		printf("空间分配失败 \n");
		exit(-1);
	}



	PNode PTail = Phead; //    链表的末尾节点，初始指向头节点
	PTail->Next = NULL;  //    最后一个节点指针置为空
	printf("请输入节点个数：");
	scanf("%d", &len);   //    输入节点个数

	for (int i = 0; i < len; i ++)
	{
		PNode pNew = (PNode)malloc(sizeof(Node));
		 if (pNew == NULL) {
            printf("分配新节点失败\n");
            exit(-1);
        }
        printf("请输入第 %d 个节点的数据：", i + 1);
        scanf("%d", &val);    //    输入链表节点的数据

        pNew->Element = val;  //    把数据赋值给节点数据域
        PTail->Next = pNew;   //    末尾节点指针指向下一个新节点
        pNew->Next = NULL;        //    新节点指针指向为空
        PTail = pNew;    //    将新节点复制给末尾节点  
	}

	printf("创建链表成功\n");
    return Phead;    //    返回头节点

};


void TraverseList(PNode List) {
	PNode p = List->Next;
	printf("遍历链表的值为：");
	if (p == NULL)
	{
		 printf("链表为空");
	}

	while (p != NULL) {
		printf("%d", p->Element);
		p = p->Next;
	}

	printf("\n");
}


PNode FindList(PNode List) {
	PNode p = List->Next;  //    定义临时指针P指向首节点的地址
	int num = 0;       //    用于记录链表节点位置
	int val = 0; 	  //    用于存放要查询的值
	printf("请输入要查询的数：");
	scanf("%d", &val);  //    输入要查询的数值
	while (p != NULL && p->Element != val) {
		p = p->Next;
		++ num;
	}

	if (p != NULL)
	{
		printf("找到的节点为：%d", num + 1);
	} else {
		printf("找不到该节点");
	}
	printf("\n");
    return p;
}

//     定义链表插入函数
//    在链表位置第pos节点前插入包含数据val的节点

void insertList(PNode list, int pos, int val) {
	int position = 0;
	PNode p = list;   //    定义节点p指向头节点
	//    寻找pos节点的前驱结点
	while (p != NULL && position < pos - 1) {
		p = p->Next;
		++position;
	}

	PNode tmp = (PNode)malloc(sizeof(Node));
	if (tmp == NULL)
	{  printf("内存分配失败！");
        exit(-1);/* code */
	}

	//    插入节点
	tmp->Element = val;
	tmp->Next = p->Next;
	p->Next = tmp;
}

//定义删除整个链表函数
void DeleteTheList(PNode List) {
    PNode P, Tmp;
    P = List->Next;    //定义指针P指向链表要删除的链表List的第一个点节点
    List->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;        //临时Tmp指向要删除的节点的下个节点
        free(P);    //释放指针P指向的节点
        P = Tmp;    //重新赋值
    }
    printf("删除链表成功！\n");
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




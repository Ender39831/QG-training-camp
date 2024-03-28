#include <stdio.h>
#include <stdlib.h>
#include "A one-way linked list.h"

//定义链表结点结构体
struct Node {
    int number;  //表示是第几个创建的结点
    int data;   //结构体里放个值
    struct Node* next;
};

//全局变量，链表头指针
struct Node* head = NULL;
int num = 1;   //结点的序号
// 创建链表
void create() {
    int n, d;     //n为一开始创建时的个数，d为data的值
    struct Node* temp, * newNode;

    printf("请输入要创建的链表中结点的个数：");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("请输入第 %d 个结点的值：", i + 1);
        scanf("%d", &d);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->number = num++;
        newNode->data = d;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

//删除结点
void delete(int target) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == target) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            printf("删除完成！\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("未找到值为 %d 的结点\n", target);
}

// 增添结点
void add(int target) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->number = num++;
    newNode->data = target;
    newNode->next = head;
    head = newNode;
}

// 打印链表
void print() {
    struct Node* current = head;
    printf("链表中的结点为：\n");
    while (current != NULL) {
        printf("number:%d    data:%d \n", current->number, current->data);
        current = current->next;
    }
    printf("\n");
}

// 查找链表中的中间结点
void findMiddleNode() {
    struct Node* slow = head;
    struct Node* fast = head;

    if (head != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        printf("链表中的中间结点为:number:%d    data:%d \n", slow->number, slow->data);
    }
}
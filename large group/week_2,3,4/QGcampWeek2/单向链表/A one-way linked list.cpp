#include <stdio.h>
#include <stdlib.h>
#include "A one-way linked list.h"

//����������ṹ��
struct Node {
    int number;  //��ʾ�ǵڼ��������Ľ��
    int data;   //�ṹ����Ÿ�ֵ
    struct Node* next;
};

//ȫ�ֱ���������ͷָ��
struct Node* head = NULL;
int num = 1;   //�������
// ��������
void create() {
    int n, d;     //nΪһ��ʼ����ʱ�ĸ�����dΪdata��ֵ
    struct Node* temp, * newNode;

    printf("������Ҫ�����������н��ĸ�����");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("������� %d ������ֵ��", i + 1);
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

//ɾ�����
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
            printf("ɾ����ɣ�\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("δ�ҵ�ֵΪ %d �Ľ��\n", target);
}

// ������
void add(int target) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->number = num++;
    newNode->data = target;
    newNode->next = head;
    head = newNode;
}

// ��ӡ����
void print() {
    struct Node* current = head;
    printf("�����еĽ��Ϊ��\n");
    while (current != NULL) {
        printf("number:%d    data:%d \n", current->number, current->data);
        current = current->next;
    }
    printf("\n");
}

// ���������е��м���
void findMiddleNode() {
    struct Node* slow = head;
    struct Node* fast = head;

    if (head != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        printf("�����е��м���Ϊ:number:%d    data:%d \n", slow->number, slow->data);
    }
}
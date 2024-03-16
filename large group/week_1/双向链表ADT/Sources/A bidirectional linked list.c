#include <stdio.h>
#include <stdlib.h>

//定义双向链表结点结构体
struct Node {
    int number;  //表示是第几个创建的结点
    int data;    //结点中存储的值
    struct Node* prev;
    struct Node* next;
};

//全局变量，链表头指针和尾指针
struct Node* head = NULL;
struct Node* tail = NULL;
int num = 1;   // 结点的序号

//创建双向链表
void create() {
    int n, d;     //n为一开始创建时的个数，d为data的值
    struct Node *newNode;

    printf("请输入要创建的链表中结点的个数：");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("请输入第 %d 个结点的值：", i + 1);
        scanf("%d", &d);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->number = num++;
        newNode->data = d;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

//删除结点
void delete(int target) {
    struct Node *current = head;

    while (current != NULL) {
        if (current->data == target) {
            if (current == head) {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else if (current == tail) {
                tail = current->prev;
                tail->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("删除完成！\n");
            return;
        }
        current = current->next;
    }

    printf("未找到值为 %d 的结点\n", target);
}

//增添结点
void add(int target) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->number = num++;
    newNode->data = target;
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    printf("增添完成!\n");
}

//打印链表
void print() {
    struct Node* current = head;
    printf("链表中的结点为：\n");
    while (current != NULL) {
        printf("number:%d    data:%d \n", current->number, current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, target;

    while (1) {
        printf("\n双向链表操作菜单：\n");
        printf("1. 创建链表\n");
        printf("2. 删除结点\n");
        printf("3. 增添结点\n");
        printf("4. 打印链表\n");
        printf("5. 退出\n");
        printf("请选择操作：");
        scanf("%d", &choice);
        getchar();    //吸收回车
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                printf("请输入要删除的结点的值：");
                scanf("%d", &target);
                delete(target);
                break;
            case 3:
                printf("请输入要增添的结点的值：");
                scanf("%d", &target);
                add(target);
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
            default:
                printf("无效操作\n");
        }
    }

    return 0;
}

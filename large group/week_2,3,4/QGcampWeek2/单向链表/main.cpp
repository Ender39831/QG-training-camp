#include <stdio.h>
#include "A one-way linked list.h"

int main() {
    int choice, target;

    while (1) {
        printf("\n链表操作菜单：\n");
        printf("1. 创建链表\n");
        printf("2. 删除结点\n");
        printf("3. 增添结点\n");
        printf("4. 打印链表\n");
        printf("5. 查找链表的中间结点\n");
        printf("6. 退出\n");
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
            printf("增添完成!\n");
            break;
        case 4:
            print();
            break;
        case 5:
            findMiddleNode();
            break;
        case 6:
            exit(0);
        default:
            printf("无效操作\n");
        }
    }

    return 0;
}
#include <stdio.h>
#include "A one-way linked list.h"

int main() {
    int choice, target;

    while (1) {
        printf("\n��������˵���\n");
        printf("1. ��������\n");
        printf("2. ɾ�����\n");
        printf("3. ������\n");
        printf("4. ��ӡ����\n");
        printf("5. ����������м���\n");
        printf("6. �˳�\n");
        printf("��ѡ�������");
        scanf("%d", &choice);
        getchar();    //���ջس�
        switch (choice) {
        case 1:
            create();
            break;
        case 2:
            printf("������Ҫɾ���Ľ���ֵ��");
            scanf("%d", &target);
            delete(target);
            break;
        case 3:
            printf("������Ҫ����Ľ���ֵ��");
            scanf("%d", &target);
            add(target);
            printf("�������!\n");
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
            printf("��Ч����\n");
        }
    }

    return 0;
}
#include "LQueue.h"
#include "iostream"

int main() {

    LQueue queue;
	char choice;

    while (true) {
        std::cout << std::endl << "泛型队列操作菜单" << std::endl;
        std::cout << "1.添加节点" << std::endl;
        std::cout << "2.删除节点" << std::endl;
        std::cout << "3.判断队列是否为空" << std::endl;
        std::cout << "4.清空队列" << std::endl;
        std::cout << "5.查看队列长度" << std::endl;
        std::cout << "6.打印队列中的数据" << std::endl;
        std::cout << "7.结束程序" << std::endl;
        std::cout << "请选择操作:";
        std::cin >> choice;

        switch (choice) {
        case '1':
            queue.addNode();
            break;
        case '2':
            queue.deleteNode();
            break;
        case '3':
            queue.IsEmptyLQueue();
            break;
        case '4':
            queue.ClearLQueue();
            break;
        case '5':
            std::cout << "队列的长度为" << queue.LengthLQueue() << std::endl;
            break;
        case '6':
            queue.Print();
            break;
        case '7':
            std::cout << "程序退出！" << std::endl;
            return 0;
        default:
            std::cout << "无效操作!" << std::endl;
        }
    }

	return 0;
}
#include "ChainStack.h"
#include <iostream>
#include <string>

int main() {

    ChainStack Stack;
    char choice;
    std::string expression;  //存储用于计算的表达式

    while (true) {
        std::cout << std::endl << "链栈操作菜单" << std::endl;
        std::cout << "1.添加节点" << std::endl;
        std::cout << "2.删除节点" << std::endl;
        std::cout << "3.判断链栈是否为空" << std::endl;
        std::cout << "4.清空链栈" << std::endl;
        std::cout << "5.计算模式，启动" << std::endl;
        std::cout << "6.打印链栈中的数据" << std::endl;
        std::cout << "7.结束程序" << std::endl;
        std::cout << "请选择操作:";
        std::cin >> choice;

        switch (choice) {
        case '1':
            std::cout << "输入你想要输入的数据(字符):";
            char t;
            std::cin >> t;
            Stack.push(t);
            break;
        case '2':
            Stack.pop();
            break;
        case '3':
            if (Stack.isEmpty())
                std::cout << "栈为空" << std::endl;
            else
                std::cout << "栈不为空" << std::endl;
            break;
        case '4':
            Stack.clearStack();
            break;
        case '5':
            std::cout << "请输入要计算的四则运算表达式：";
            std::cin >> expression;
            std::cout << "计算结果为：" << evaluateExpression(expression,Stack) << std::endl;
            break;
        case '6':
            Stack.printStack();
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

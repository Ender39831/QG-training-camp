#include "iostream"
#include "week4.h"

int main() {

	char cho;
    std::cout << "选择二叉排序树数据类型：" << std::endl;
    std::cout << "1. 整数" << std::endl;
    std::cout << "2. 浮点数" << std::endl;
    std::cout << "3. 字符" << std::endl;
    std::cout << "4. 退出" << std::endl;
    std::cout << "请输入选项编号：";
    std::cin >> cho;
    if (cho == '1') {
        BinarySortTree<int> week4;
        week4.menu();
    }
    else if (cho == '2') {
        BinarySortTree<float> week4;
        week4.menu();
    }
    else if (cho == '3') {
        BinarySortTree<char> week4;
        week4.menu();
    }
    else
        ;
	return 0;
}
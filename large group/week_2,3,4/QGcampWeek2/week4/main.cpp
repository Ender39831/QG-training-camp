#include "iostream"
#include "week4.h"

int main() {

	char cho;
    std::cout << "ѡ������������������ͣ�" << std::endl;
    std::cout << "1. ����" << std::endl;
    std::cout << "2. ������" << std::endl;
    std::cout << "3. �ַ�" << std::endl;
    std::cout << "4. �˳�" << std::endl;
    std::cout << "������ѡ���ţ�";
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
#include "week3.h"
#include "iostream"

int main() {
    
    char choice;   //������
    int size;      // ������������С
    int times;     // ������������
    data QGweek3;  // ʵ������
    const char* filename = "data.txt"; // �ļ���


    while (true) {
        std::cout << std::endl << "�㷨���Բ����˵�" << std::endl;
        std::cout << "1.������ɴ����ݲ���" << std::endl;
        std::cout << "2.���ļ��ж�ȡ���ݽ�������" << std::endl;
        std::cout << "3.����С���ݲ���" << std::endl;
        std::cout << "4.��������" << std::endl;
        std::cout << "��ѡ�����:";
        std::cin >> choice;

        switch (choice) {
        case '1':
            std::cout << "��������Ҫ�����������:";
            std::cin >> size;

            QGweek3.generateTestData(size);
            QGweek3.saveDataToFile(filename);

            std::cout << "���� " << size << " ��Ԫ��:" << std::endl;
            std::cout << "���������ʱ:  " << testSort1(sort::insertSort,QGweek3.testData)<< " ms" << std::endl;
            std::cout << "���������ʱ:  " <<testSort1(sort::countSort, QGweek3.testData)<< " ms" << std::endl;
            std::cout << "�������������ʱ:  " <<testSort1(sort::radixCountSort, QGweek3.testData)<< " ms" << std::endl;
            std::cout << "���������ʱ:  " <<testSort2(sort::quickSort,QGweek3.testData,0, QGweek3.testData.size()-1) << " ms" << std::endl;
            std::cout << "�鲢�����ʱ:  " << testSort2(sort::mergeSort, QGweek3.testData, 0, QGweek3.testData.size() - 1) << " ms" << std::endl;

            QGweek3.testData.resize(0);    //��ն�̬����
            break;
        case '2':
            // ���ļ���ȡ����
            QGweek3.readDataFromFile(filename);

            std::cout << "���ļ��ж�ȡ����������:" << std::endl;
            std::cout << "���������ʱ:  " << testSort1(sort::insertSort, QGweek3.testData) << " ms" << std::endl;
            std::cout << "���������ʱ:  " << testSort1(sort::countSort, QGweek3.testData) << " ms" << std::endl;
            std::cout << "�������������ʱ:  " << testSort1(sort::radixCountSort, QGweek3.testData) << " ms" << std::endl;
            std::cout << "���������ʱ:  " << testSort2(sort::quickSort, QGweek3.testData, 0, QGweek3.testData.size() - 1) << " ms" << std::endl;
            std::cout << "�鲢�����ʱ:  " << testSort2(sort::mergeSort, QGweek3.testData, 0, QGweek3.testData.size() - 1) << " ms" << std::endl;

            QGweek3.testData.resize(0);    //��ն�̬����
            break;
        case '3':
            std::cout << "��������Ҫ�������������:";
            std::cin >> times;
            std::cout << "����������Ҫ�����ÿ�����ݵ���";
            std::cin >> size;

            QGweek3.generateTestData(size);
            QGweek3.saveDataToFile(filename);

            std::cout << "���� " << times <<"��"<<size<< " ��Ԫ��:" << std::endl;
            std::cout << "���������ʱ:  " << majorityTestSort1(sort::insertSort, QGweek3.testData,times,QGweek3) << " ms" << std::endl;
            std::cout << "���������ʱ:  " << majorityTestSort1(sort::countSort, QGweek3.testData,times, QGweek3) << " ms" << std::endl;
            std::cout << "�������������ʱ:  " << majorityTestSort1(sort::radixCountSort, QGweek3.testData,times, QGweek3) << " ms" << std::endl;
            std::cout << "���������ʱ:  " << majorityTestSort2(sort::quickSort, QGweek3.testData, 0, QGweek3.testData.size() - 1,times, QGweek3) << " ms" << std::endl;
            std::cout << "�鲢�����ʱ:  " << majorityTestSort2(sort::mergeSort, QGweek3.testData, 0, QGweek3.testData.size() - 1, times,QGweek3) << " ms" << std::endl;

            QGweek3.testData.resize(0);    //��ն�̬����

            break;
        case '4':
            std::cout << "�����˳���" << std::endl;
            return 0;
        default:
            std::cout << "��Ч����!" << std::endl;
        }
    }

    return 0;
}

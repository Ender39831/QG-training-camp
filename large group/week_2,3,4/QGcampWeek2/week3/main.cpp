#include "week3.h"
#include "iostream"

int main() {
    
    char choice;   //操作符
    int size;      // 测试数据量大小
    int times;     // 排序的数据组次
    data QGweek3;  // 实例化类
    const char* filename = "data.txt"; // 文件名


    while (true) {
        std::cout << std::endl << "算法测试操作菜单" << std::endl;
        std::cout << "1.随机生成大数据测试" << std::endl;
        std::cout << "2.从文件中读取数据进行排序" << std::endl;
        std::cout << "3.大量小数据测试" << std::endl;
        std::cout << "4.结束程序" << std::endl;
        std::cout << "请选择操作:";
        std::cin >> choice;

        switch (choice) {
        case '1':
            std::cout << "输入你想要输入的数据量:";
            std::cin >> size;

            QGweek3.generateTestData(size);
            QGweek3.saveDataToFile(filename);

            std::cout << "排列 " << size << " 个元素:" << std::endl;
            std::cout << "插入排序耗时:  " << testSort1(sort::insertSort,QGweek3.testData)<< " ms" << std::endl;
            std::cout << "计数排序耗时:  " <<testSort1(sort::countSort, QGweek3.testData)<< " ms" << std::endl;
            std::cout << "基数计数排序耗时:  " <<testSort1(sort::radixCountSort, QGweek3.testData)<< " ms" << std::endl;
            std::cout << "快速排序耗时:  " <<testSort2(sort::quickSort,QGweek3.testData,0, QGweek3.testData.size()-1) << " ms" << std::endl;
            std::cout << "归并排序耗时:  " << testSort2(sort::mergeSort, QGweek3.testData, 0, QGweek3.testData.size() - 1) << " ms" << std::endl;

            QGweek3.testData.resize(0);    //清空动态数组
            break;
        case '2':
            // 从文件读取数据
            QGweek3.readDataFromFile(filename);

            std::cout << "从文件中读取数据排序结果:" << std::endl;
            std::cout << "插入排序耗时:  " << testSort1(sort::insertSort, QGweek3.testData) << " ms" << std::endl;
            std::cout << "计数排序耗时:  " << testSort1(sort::countSort, QGweek3.testData) << " ms" << std::endl;
            std::cout << "基数计数排序耗时:  " << testSort1(sort::radixCountSort, QGweek3.testData) << " ms" << std::endl;
            std::cout << "快速排序耗时:  " << testSort2(sort::quickSort, QGweek3.testData, 0, QGweek3.testData.size() - 1) << " ms" << std::endl;
            std::cout << "归并排序耗时:  " << testSort2(sort::mergeSort, QGweek3.testData, 0, QGweek3.testData.size() - 1) << " ms" << std::endl;

            QGweek3.testData.resize(0);    //清空动态数组
            break;
        case '3':
            std::cout << "输入你想要输入的数据组数:";
            std::cin >> times;
            std::cout << "请输入你需要排序的每组数据的量";
            std::cin >> size;

            QGweek3.generateTestData(size);
            QGweek3.saveDataToFile(filename);

            std::cout << "排列 " << times <<"组"<<size<< " 个元素:" << std::endl;
            std::cout << "插入排序耗时:  " << majorityTestSort1(sort::insertSort, QGweek3.testData,times,QGweek3) << " ms" << std::endl;
            std::cout << "计数排序耗时:  " << majorityTestSort1(sort::countSort, QGweek3.testData,times, QGweek3) << " ms" << std::endl;
            std::cout << "基数计数排序耗时:  " << majorityTestSort1(sort::radixCountSort, QGweek3.testData,times, QGweek3) << " ms" << std::endl;
            std::cout << "快速排序耗时:  " << majorityTestSort2(sort::quickSort, QGweek3.testData, 0, QGweek3.testData.size() - 1,times, QGweek3) << " ms" << std::endl;
            std::cout << "归并排序耗时:  " << majorityTestSort2(sort::mergeSort, QGweek3.testData, 0, QGweek3.testData.size() - 1, times,QGweek3) << " ms" << std::endl;

            QGweek3.testData.resize(0);    //清空动态数组

            break;
        case '4':
            std::cout << "程序退出！" << std::endl;
            return 0;
        default:
            std::cout << "无效操作!" << std::endl;
        }
    }

    return 0;
}

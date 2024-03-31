#pragma once
#include <vector>

class data {
public:

	std::vector<int> testData;

	// 测试时用来看看排序正不正确的打印函数
	void print();

	// 生成测试数据
	void generateTestData(int n);
	// 保存测试数据
	void saveDataToFile(const char* filename);
	// 读取测试数据
	void readDataFromFile(const char* filename);
};

namespace sort {
	// 插入排序
	void insertSort(std::vector<int>& vec);
	// 两个用于快速排序的函数

	int partition(std::vector<int>& vec, int low, int high);
	void quickSort(std::vector<int>& vec, int low, int high);
	// 计数排序
	void countSort(std::vector<int>& arr);
	// 基数计数排序
	void radixCountSort(std::vector<int>& arr);
	// 归并排序
	void merge(std::vector<int>& arr, int left, int mid, int right);
	void mergeSort(std::vector<int>& arr, int left, int right);	

}

// 第一种函数，单次时间测试函数
double testSort1(void (*func)(std::vector<int>& vec), std::vector<int>& vec);
// 第二种函数，单次时间测试函数
double testSort2(void(*func)(std::vector<int>& vec, int a, int b), std::vector<int>& vec, int a, int b);
// 第一种函数，多次时间测试函数
double majorityTestSort1(void (*func)(std::vector<int>& vec), std::vector<int>& vec, int n,data d);
// 第二种函数，多次时间测试函数
double majorityTestSort2(void(*func)(std::vector<int>& vec, int a, int b), std::vector<int>& vec, int a, int b, int n,data d);
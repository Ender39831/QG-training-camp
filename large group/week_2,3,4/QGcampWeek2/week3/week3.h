#pragma once
#include <vector>

class data {
public:

	std::vector<int> testData;

	// ����ʱ������������������ȷ�Ĵ�ӡ����
	void print();

	// ���ɲ�������
	void generateTestData(int n);
	// �����������
	void saveDataToFile(const char* filename);
	// ��ȡ��������
	void readDataFromFile(const char* filename);
};

namespace sort {
	// ��������
	void insertSort(std::vector<int>& vec);
	// �������ڿ�������ĺ���

	int partition(std::vector<int>& vec, int low, int high);
	void quickSort(std::vector<int>& vec, int low, int high);
	// ��������
	void countSort(std::vector<int>& arr);
	// ������������
	void radixCountSort(std::vector<int>& arr);
	// �鲢����
	void merge(std::vector<int>& arr, int left, int mid, int right);
	void mergeSort(std::vector<int>& arr, int left, int right);	

}

// ��һ�ֺ���������ʱ����Ժ���
double testSort1(void (*func)(std::vector<int>& vec), std::vector<int>& vec);
// �ڶ��ֺ���������ʱ����Ժ���
double testSort2(void(*func)(std::vector<int>& vec, int a, int b), std::vector<int>& vec, int a, int b);
// ��һ�ֺ��������ʱ����Ժ���
double majorityTestSort1(void (*func)(std::vector<int>& vec), std::vector<int>& vec, int n,data d);
// �ڶ��ֺ��������ʱ����Ժ���
double majorityTestSort2(void(*func)(std::vector<int>& vec, int a, int b), std::vector<int>& vec, int a, int b, int n,data d);
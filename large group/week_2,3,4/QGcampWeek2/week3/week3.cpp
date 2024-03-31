#include "week3.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>

void data::print() {
    int i = 0;
    while (i < testData.size()) {
        std::cout << testData[i] << " ";
        i++;
    }
}

    // ���ɲ�������
void data::generateTestData(int n) {
    srand(time(NULL));      // ʹ��ʱ����Ϊ����  
    testData.resize(n);           // ����vector�Ĵ�С  
    for (int i = 0; i < n; ++i)
        testData[i] = rand() % 10000;    // �������ֵΪ0~9999  
}


// �������ݵ��ļ�
void data::saveDataToFile(const char* filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (size_t i = 0; i < testData.size(); ++i)
            outputFile << testData[i] << " ";
        outputFile.close();
    }
    else {
        std::cout << "�޷����ļ�";
    }
}

// ���ļ���ȡ����  
void data::readDataFromFile( const char* filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int value;
        while (inputFile >> value) {
            testData.push_back(value); // ֱ�ӽ���ȡ��ֵ��ӵ�vector��  
        }
        inputFile.close();
    }
    else {
        std::cout << "�޷����ļ�";
    }
}

// �������Ǹ����㷨

// ��������
void sort::insertSort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; ++i) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

// �����������������
int sort::partition(std::vector<int>& vec, int low, int high) {
    int h = vec[high];    // ѡ�����ұߵ�Ԫ����Ϊ��׼  
    int i = low -1;

    for (int j = low; j <= high; ++j) {  
        if (vec[j] < h) {        // �����ǰԪ��С�ڻ�׼  
            ++i;
            std::swap(vec[i], vec[j]); // ����Ԫ��  
        }
    }
    std::swap(vec[i+1], vec[high]);
    return i + 1;
}

// ����������
void sort::quickSort(std::vector<int>& vec, int low, int high) {
    if (low < high) {           // ���lowС��high��˵������Ԫ����Ҫ����  
        int p = partition(vec, low, high); // ���÷�����������ȡ��׼Ԫ��
        quickSort(vec, low, p - 1);    // �ݹ������׼Ԫ����ߵ�������  
        quickSort(vec, p + 1, high);   // �ݹ������׼Ԫ���ұߵ�������  
    }
}

// ��������
void sort::countSort(std::vector<int>& arr) {
    // �ҵ����ֵ����Сֵ  
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    // ��ʼ������������������  
    int range = max - min + 1;
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());
    // ͳ��ÿ��Ԫ�س��ֵĴ���  
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min]++;
    }
    // �ۼ����  
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    // �����������  
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    // �����������鸴�ƻ�ԭ����  
    arr = output;
}

// ������������
void sort::radixCountSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // ����countSortʱ����arr������  
        sort::countSort(arr);
    }

}

// �鲢����ĺϲ�����  
void sort::merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // ������ʱ����  
    std::vector<int> L(n1 + 1), R(n2 + 1);
    // �������ݵ���ʱ����L[]��R[]  
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // ��ʼ������  
    int i = 0, j = 0;
    // �ϲ���ʱ����
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // ����L[]��ʣ��Ԫ��  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // ����R[]��ʣ��Ԫ��  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// �鲢������  
void sort::mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // �ҵ��м��  
        int mid = left + (right - left) / 2;
        // �������������й鲢����  
        mergeSort(arr, left, mid);
        // ���ұ���������й鲢����  
        mergeSort(arr, mid + 1, right);
        // �ϲ������������������  
        merge(arr, left, mid, right);
    }
}

// ����ʱ�亯��
double testSort1(void (*func)(std::vector<int>& vec), std::vector<int>& vec) {
    // ��ȡ��ǰʱ���  
    auto start = std::chrono::high_resolution_clock::now();
    func(vec);
    // ��ȡ����ʱ���  
    auto end = std::chrono::high_resolution_clock::now();
    // ����ִ��ʱ�䣬��ת��Ϊ����  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count(); // ����ִ��ʱ�䣨���룩  
}

// ���ڿ�������͹鲢�����ʱ����Ժ���
double testSort2(void(*func)(std::vector<int>& vec, int a, int b), std::vector<int>& vec, int a, int b) {
    // ��ȡ��ǰʱ���  
    auto start = std::chrono::high_resolution_clock::now();
    func(vec,a,b);
    // ��ȡ����ʱ���  
    auto end = std::chrono::high_resolution_clock::now();
    // ����ִ��ʱ�䣬��ת��Ϊ����  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count(); // ����ִ��ʱ�䣨���룩  
}

// ���ڶ�β��Ե�ʱ����Ժ���
double majorityTestSort1(void (*func)(std::vector<int>& vec), std::vector<int>& vec, int n,data d) {
    // ��ȡ��ǰʱ���  
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++) {
        //d.generateTestData(d.testData.size());  //�����µ��������,�����ҷ��ֲ���ҪҲ���Եó�����ʱ�䣬ȥ���ܸ��ӽ��㷨����ʱ��
        func(vec);
    }
    // ��ȡ����ʱ���  
    auto end = std::chrono::high_resolution_clock::now();
    // ����ִ��ʱ�䣬��ת��Ϊ����  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count(); // ����ִ��ʱ�䣨���룩  
}

// ���ڿ�������͹鲢����Ķ������ʱ����Ժ���
double majorityTestSort2(void(*func)(std::vector<int>& vec, int a, int b), std::vector<int>& vec, int a, int b,int n,data d) {
    // ��ȡ��ǰʱ���  
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++) {
        //d.generateTestData(d.testData.size());  //�����µ��������,�����ҷ��ֲ���ҪҲ���Եó�����ʱ�䣬ȥ���ܸ��ӽ��㷨����ʱ��
        func(vec, a, b);
    }
    // ��ȡ����ʱ���  
    auto end = std::chrono::high_resolution_clock::now();
    // ����ִ��ʱ�䣬��ת��Ϊ����  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count(); // ����ִ��ʱ�䣨���룩  
}
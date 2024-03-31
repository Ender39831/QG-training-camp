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

    // 生成测试数据
void data::generateTestData(int n) {
    srand(time(NULL));      // 使用时间作为种子  
    testData.resize(n);           // 调整vector的大小  
    for (int i = 0; i < n; ++i)
        testData[i] = rand() % 10000;    // 随机数的值为0~9999  
}


// 保存数据到文件
void data::saveDataToFile(const char* filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (size_t i = 0; i < testData.size(); ++i)
            outputFile << testData[i] << " ";
        outputFile.close();
    }
    else {
        std::cout << "无法打开文件";
    }
}

// 从文件读取数据  
void data::readDataFromFile( const char* filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        int value;
        while (inputFile >> value) {
            testData.push_back(value); // 直接将读取的值添加到vector中  
        }
        inputFile.close();
    }
    else {
        std::cout << "无法打开文件";
    }
}

// 接下来是各种算法

// 插入排序
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

// 快速排序的两个函数
int sort::partition(std::vector<int>& vec, int low, int high) {
    int h = vec[high];    // 选择最右边的元素作为基准  
    int i = low -1;

    for (int j = low; j <= high; ++j) {  
        if (vec[j] < h) {        // 如果当前元素小于基准  
            ++i;
            std::swap(vec[i], vec[j]); // 交换元素  
        }
    }
    std::swap(vec[i+1], vec[high]);
    return i + 1;
}

// 快速排序函数
void sort::quickSort(std::vector<int>& vec, int low, int high) {
    if (low < high) {           // 如果low小于high，说明还有元素需要排序  
        int p = partition(vec, low, high); // 调用分区函数，获取基准元素
        quickSort(vec, low, p - 1);    // 递归排序基准元素左边的子数组  
        quickSort(vec, p + 1, high);   // 递归排序基准元素右边的子数组  
    }
}

// 计数排序
void sort::countSort(std::vector<int>& arr) {
    // 找到最大值和最小值  
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
    // 初始化计数数组和输出数组  
    int range = max - min + 1;
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());
    // 统计每个元素出现的次数  
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min]++;
    }
    // 累加求和  
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    // 构建输出数组  
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    // 将排序后的数组复制回原数组  
    arr = output;
}

// 基数计数排序
void sort::radixCountSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; max / exp > 0; exp *= 10) {
        // 调用countSort时传入arr的引用  
        sort::countSort(arr);
    }

}

// 归并排序的合并函数  
void sort::merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // 创建临时数组  
    std::vector<int> L(n1 + 1), R(n2 + 1);
    // 拷贝数据到临时数组L[]和R[]  
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    // 初始化索引  
    int i = 0, j = 0;
    // 合并临时数组
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
    // 复制L[]的剩余元素  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // 复制R[]的剩余元素  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序函数  
void sort::mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // 找到中间点  
        int mid = left + (right - left) / 2;
        // 对左边子数组进行归并排序  
        mergeSort(arr, left, mid);
        // 对右边子数组进行归并排序  
        mergeSort(arr, mid + 1, right);
        // 合并两个已排序的子数组  
        merge(arr, left, mid, right);
    }
}

// 测试时间函数
double testSort1(void (*func)(std::vector<int>& vec), std::vector<int>& vec) {
    // 获取当前时间点  
    auto start = std::chrono::high_resolution_clock::now();
    func(vec);
    // 获取结束时间点  
    auto end = std::chrono::high_resolution_clock::now();
    // 计算执行时间，并转换为毫秒  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count(); // 返回执行时间（毫秒）  
}

// 用于快速排序和归并排序的时间测试函数
double testSort2(void(*func)(std::vector<int>& vec, int a, int b), std::vector<int>& vec, int a, int b) {
    // 获取当前时间点  
    auto start = std::chrono::high_resolution_clock::now();
    func(vec,a,b);
    // 获取结束时间点  
    auto end = std::chrono::high_resolution_clock::now();
    // 计算执行时间，并转换为毫秒  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count(); // 返回执行时间（毫秒）  
}

// 用于多次测试的时间测试函数
double majorityTestSort1(void (*func)(std::vector<int>& vec), std::vector<int>& vec, int n,data d) {
    // 获取当前时间点  
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++) {
        //d.generateTestData(d.testData.size());  //整个新的随机数组,但是我发现不需要也可以得出差不多的时间，去掉能更接近算法处理时间
        func(vec);
    }
    // 获取结束时间点  
    auto end = std::chrono::high_resolution_clock::now();
    // 计算执行时间，并转换为毫秒  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count(); // 返回执行时间（毫秒）  
}

// 用于快速排序和归并排序的多次排序时间测试函数
double majorityTestSort2(void(*func)(std::vector<int>& vec, int a, int b), std::vector<int>& vec, int a, int b,int n,data d) {
    // 获取当前时间点  
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= n; i++) {
        //d.generateTestData(d.testData.size());  //整个新的随机数组,但是我发现不需要也可以得出差不多的时间，去掉能更接近算法处理时间
        func(vec, a, b);
    }
    // 获取结束时间点  
    auto end = std::chrono::high_resolution_clock::now();
    // 计算执行时间，并转换为毫秒  
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration.count(); // 返回执行时间（毫秒）  
}
#include <iostream>
#include <any>
#include <string>
#pragma once
class Node {
public:
	std::any data;  //可以为任意数据类型
	Node* next;

	Node(std::any value);
};

class LQueue {
private:
	Node* front;
	Node* rear;
	int length;

public:
	LQueue();
	// 添加结点函数
	void addNode();
	// 删除结点函数
	void deleteNode();
	// 判断队列是否为空
	void IsEmptyLQueue();
	// 清空队列
	void ClearLQueue();
	// 返回队列长度
	int LengthLQueue();
	// 打印队列
	void Print();
};
// 判断是否为整数
bool isInteger(const std::string& s);
bool isFloat(const std::string& s);
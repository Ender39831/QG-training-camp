#include "LQueue.h"
#include <iostream>
#include <any>
#include <string>

Node::Node(std::any value) : data(value), next(nullptr) {}

	LQueue::LQueue() : front(nullptr), rear(nullptr),length(0) {}
	// 添加结点函数
	void LQueue::addNode() {
		std::string input;
		std::any value;
		std::cout << "请输入一个数据(可以是字符串，浮点数，整数)：";
		std::cin >> input;
		// 逝逝输入的是不是整数
		if (isInteger(input)) {
			int intValue = std::stoi(input);
			value = intValue;
		}
		else try {
				double doubleValue = std::stod(input);
				value = doubleValue;
			}
			catch (const std::invalid_argument&) {  // 捕获错误信息
				// 都不是，那输入的数据为字符串
				value = input;
			}
		
		Node* newNode = new Node(value);
		if (rear == nullptr) {
			rear = newNode;
			front = newNode;
		}
		else {
			rear->next = newNode;
			rear = rear->next;
		}
		std::cout << "结点添加完成!" << std::endl;

		length++; //记录队列长度
	}
	// 删除结点函数
	void LQueue::deleteNode() {
		if (front == nullptr) {
			std::cout << "队列为空，无法删除结点！" << std::endl;
			return;
		}

		Node* temp = front;
		front = front->next;
		delete temp;

		if (front == nullptr) {
			rear = nullptr;
		}
	
		std::cout << "删除结点完成!" << std::endl;
		length--;
	}
	// 判断队列是否为空
	void LQueue::IsEmptyLQueue() {
		if (front == nullptr) {
			std::cout << "队列为空!" << std::endl;
		}
		else {
			std::cout << "队列不为空!" << std::endl;
		}
	}
	// 清空队列
	void LQueue::ClearLQueue() {
		while (front != nullptr) {
			deleteNode();
			front = front->next;
		}
		length = 0;
	}
	// 返回队列长度
	int LQueue::LengthLQueue() {
		return length;
	}
	// 打印队列
	void LQueue::Print() {
		if (front == nullptr) {
			std::cout << "队列为空" << std::endl;
			return;
		}

		std::cout << std::endl<<"队列中的结点为：" << std::endl;
		Node* current = front;
		while (current != nullptr) {
			// 判断数据类型是啥并输出
			try {
				if (current->data.type() == typeid(int)) {
					std::cout << std::any_cast<int>(current->data) << std::endl;
				}
				else if (current->data.type() == typeid(double)) {
					std::cout << std::any_cast<double>(current->data) << std::endl;
				}
				else if (current->data.type() == typeid(std::string)) {
					std::cout << std::any_cast<std::string>(current->data) << std::endl;
				}
			}
			catch (const std::bad_any_cast&) {   //错误判断
				std::cout << "无法解析数据类型!";
			}
			current = current->next;
		}
		std::cout << std::endl;
	}
	//判断是否为整数(在这里搞了一年)
	bool isInteger(const std::string& s) {
		if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
			return false;
		}

		char* p;
		strtol(s.c_str(), &p, 10);  // 在微软官网查到的一个函数，我也不是很懂，但是成了(

		return (*p == 0);
	}
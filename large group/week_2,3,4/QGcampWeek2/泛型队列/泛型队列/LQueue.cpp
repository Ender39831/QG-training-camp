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

		if (isInteger(input)) {    //是否为整数
			int intValue = std::stoi(input);
			value = intValue;
		}
		else if (isFloat(input)) {  //是否为浮点数
			double doubleValue = std::stod(input);
			value = doubleValue;
		}
		else        // 作为字符串处理
		{
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
	//判断是否为整数
	bool isInteger(const std::string& s) {
		if (s.empty()) {
			return false;
		}

		size_t start = 0;
		if (s[0] == '-' || s[0] == '+') {
			start = 1;
		}

		for (size_t i = start; i < s.length(); i++) {
			if (!isdigit(s[i])) {
				return false;
			}
		}

		if (start == 1 && s.length() == 1) {
			return false; 
		}

		return true;
	}
	// 判断是否为浮点数
	bool isFloat(const std::string& s) {
		if (s.empty()) {
			return false;
		}

		size_t start = 0;
		if (s[0] == '-' || s[0] == '+') {
			start = 1;
		}

		bool sign = false;

		for (size_t i = start; i < s.length(); i++) {
			if (!isdigit(s[i])) {
				if (s[i] == '.' && !sign) {
					sign = true;
				}
				else {
					return false;
				}
			}
		}

		if (start == 1 && s.length() == 1) {
			return false; 
		}

		return sign;
	}
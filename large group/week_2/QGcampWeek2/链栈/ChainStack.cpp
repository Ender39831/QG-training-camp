#include "ChainStack.h"
#include "iostream"
#include <string>
// 压入栈顶
void ChainStack::push(char c) {
    Node* newNode = new Node;
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}
// 弹出栈顶
char ChainStack::pop() {
    if (isEmpty()) {
        return '\0';
    }
    Node* temp = top;
    char c = temp->data;
    top = top->next;
    delete temp;
    return c;
}
// 获取栈顶元素
char ChainStack::peek() {
    if (isEmpty()) {
        return '\0';
    }
    return top->data;
}
// 判断栈是否为空
bool ChainStack::isEmpty() {
    return top == nullptr;
}
// 清空栈
void ChainStack::clearStack() {
    while (top != nullptr) 
        pop();
}
// 输出栈的元素
void ChainStack::printStack() {
    Node* temp = top;
    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

//接下来的函数是用于计算器的函数

// 判断运算符优先级(括号会另外做处理)
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
// 执行单次运算运算
int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return 0;
}
// 计算表达式值
int evaluateExpression(const std::string& expression,ChainStack number) {
    ChainStack operators;     //用来存操作符的栈
    // 开始遍历表达式，处理各种情况
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        // 如果是空格，不管直接下一个
        if (c == ' ') {
            continue;
        }
        else if (isdigit(c)) {  // 判断是不是数字
            int num = 0;
            while (i < expression.size() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');   // 获取多位数的值
                i++;
            }
            i--;
            number.push(num);   // 把获取到的数压入计算的栈
        }
        else if (c == '(') {
            operators.push(c);   // 左括号直接进运算符栈
        }
        else if (c == ')') {     // 右括号则先把括号内的计算先算了
            while (!operators.isEmpty() && operators.peek() != '(') {
                char op = operators.pop();
                int b = number.pop();
                int a = number.pop();
                number.push(applyOp(a, b, op));
            }
            operators.pop();
        }
        else {          // 是加减乘除的运算符情况
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(c)) {
                // 如果栈顶的运算符优先级较高，则先把优先级较高的计算先算了再把低的压入栈
                char op = operators.pop();
                int b = number.pop();
                int a = number.pop();
                number.push(applyOp(a, b, op));
            }
            operators.push(c);
        }
    }

    while (!operators.isEmpty()) {       // 把剩下的一个个拿出来算
        char op = operators.pop();
        int b = number.pop();
        int a = number.pop();
        number.push(applyOp(a, b, op));
    }

    return number.pop();            // 最后返回最后剩下的数（即计算结果）
}

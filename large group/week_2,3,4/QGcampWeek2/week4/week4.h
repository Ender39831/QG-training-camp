#pragma once
#include "iostream"
#include <queue>
#include <stack>

// 二叉树节点定义
template<typename T>
struct TreeNode {
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}

    T val;
    TreeNode* left;
    TreeNode* right;
};

// 二叉树本体(怎么方法几乎都要递归)
template<typename T>
class BinarySortTree {
private:
    TreeNode<T>* root;

    // 在以node为根的二叉搜索树中查找值为val的节点，因为用了递归，public的方法在后面
    TreeNode<T>* findNode(TreeNode<T>* node, T val) {
        if (node == nullptr || node->val == val) {
            return node;
        }
        else if (val < node->val) {
            return findNode(node->left, val);
        }
        else {
            return findNode(node->right, val);
        }
    }
    // 插入值为val的节点到以node为根的二叉搜索树中
    TreeNode<T>* insertNode(TreeNode<T>* node, T val) {
        if (node == nullptr) {
            return new TreeNode<T>(val);
        }
        else if (val < node->val) {
            node->left = insertNode(node->left, val);
        }
        else {
            node->right = insertNode(node->right, val);
        }
        return node;
    }

    // 删除值为val的节点
    TreeNode<T>* deleteNode(TreeNode<T>* node, T val) {
        if (node == nullptr) {
            return nullptr;
        }
        if (val < node->val) {
            node->left = deleteNode(node->left, val);  // 如果小于，递归往左找
        }
        else if (val > node->val) {
            node->right = deleteNode(node->right, val);  // 如果大于，递归往右找
        }
        else {        //找到了需要的结点
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode<T>* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }

    // 找到以node为根的二叉搜索树的最小节点(辅助其他函数用的)
    TreeNode<T>* minValueNode(TreeNode<T>* node) {
        TreeNode<T>* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // 先序遍历辅助函数   递归
    void preOrderE(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->val << " ";
        preOrderE(node->left);
        preOrderE(node->right);
    }

    // 中序遍历辅助函数    递归
    void midOrderE(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        midOrderE(node->left);
        std::cout << node->val << " ";
        midOrderE(node->right);
    }

    // 后序遍历辅助函数    递归
    void postOrderE(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        postOrderE(node->left);
        postOrderE(node->right);
        std::cout << node->val << " ";
    }

public:
    BinarySortTree() : root(nullptr) {}

    void menu() {
        char choice;
        int sign = 1;
        T target;
        while (true) {
            std::cout << std::endl << "操作菜单" << std::endl;
            std::cout << "1.查找结点" << std::endl;
            std::cout << "2.插入结点" << std::endl;
            std::cout << "3.删除结点" << std::endl;
            std::cout << "4.层序遍历\n" << std::endl;

            std::cout << "5.递归前序遍历" << std::endl;
            std::cout << "6.前序遍历\n" << std::endl;

            std::cout << "7.递归中序遍历" << std::endl;
            std::cout << "8.中序遍历\n" << std::endl;

            std::cout << "9.递归后序遍历" << std::endl;
            std::cout << "a.后序遍历" << std::endl;
            std::cout << "b.退出程序" << std::endl;
            std::cout << "请选择操作:";
            std::cin >> choice;

            switch (choice) {
            case '1':
                std::cout << "输入你想要查找的数值:";
                std::cin >> target;
                find(target);
                break;

            case '2':
                std::cout << "输入你想要插入的元素的值";
                std::cin >> target;
                insert(target);
                break;

            case '3':
                std::cout << "输入你想要删除的数值:";
                std::cin >> target;
                deleteVal(target);
                break;

            case '4':
                std::cout << "\n";
                SequenceTraversal();
                std::cout << "\n";
                break;

            case '5':
                std::cout << "\n";
                preOrder();
                std::cout << "\n";
                break;

            case '6':
                std::cout << "\n";
                PreorderTraversal();
                std::cout << "\n";
                break;

            case '7':
                std::cout << "\n";
                midOrder();
                std::cout << "\n";
                break;

            case '8':
                std::cout << "\n";
                MidOrderTraversal();
                std::cout << "\n";
                break;

            case '9':
                std::cout << "\n";
                postOrder();
                std::cout << "\n";
                break;

            case 'a':
                std::cout << "\n";
                postOrderTraversal();
                std::cout << "\n";
                break;

            case 'b':
                std::cout << "程序退出！" << std::endl;
                sign = 0;
                break;
            default:
                std::cout << "无效操作!" << std::endl;
            }
        }
    }

    // 查找值为val的节点
    void find(T val) {
        TreeNode<T>* node = findNode(root, val);
        if (node == nullptr)
            std::cout << "未找到值为" << val << "的结点" << std::endl;
        else
        {
            std::cout << "找到了值为" << val << "的结点" << std::endl;;
        }
    }

    // 插入值为val的节点
    void insert(T val) {
        root = insertNode(root, val);
    }

    //删除值为val的节点
    void deleteVal(T val) {
        root = deleteNode(root, val);
    }

    // 层序遍历函数   非递归
    void SequenceTraversal() {
        TreeNode<T>* temp = root;
        if (temp == nullptr) {
            return;
        }
        std::queue<TreeNode<T>*> q;    // 定义一个队列来辅助
        q.push(temp);
        while (!q.empty()) {
            TreeNode<T>* current = q.front();
            q.pop();
            std::cout << current->val << " ";
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }


    // 先序遍历 递归
    void preOrder() {
        preOrderE(root);
    }

    // 中序遍历 递归
    void midOrder() {
        midOrderE(root);
    }

    // 后序遍历 递归
    void postOrder() {
        postOrderE(root);
    }


    // 先序遍历（非递归）
    void PreorderTraversal() {
        if (root == nullptr) {
            return;
        }
        std::stack<TreeNode<T>*> st;   // 定义一个栈来辅助
        st.push(root);
        while (!st.empty()) {
            TreeNode<T>* current = st.top();
            st.pop();
            std::cout << current->val << " ";
            if (current->right != nullptr) {
                st.push(current->right);
            }
            if (current->left != nullptr) {
                st.push(current->left);
            }
        }
    }

    // 中序遍历（非递归）
    void MidOrderTraversal() {
        std::stack<TreeNode<T>*> st;      // 定义一个栈来辅助
        TreeNode<T>* current = root;
        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            std::cout << current->val << " ";
            current = current->right;
        }
    }

    // 后序遍历（非递归）
    void postOrderTraversal() {
        std::stack<TreeNode<T>*> st1, st2;     // 定义一个栈来辅助
        st1.push(root);
        while (!st1.empty()) {
            TreeNode<T>* current = st1.top();
            st1.pop();
            st2.push(current);
            if (current->left != nullptr) {
                st1.push(current->left);
            }
            if (current->right != nullptr) {
                st1.push(current->right);
            }
        }
        while (!st2.empty()) {
            std::cout << st2.top()->val << " ";
            st2.pop();
        }
    }

};

#pragma once
#include "iostream"
#include <queue>
#include <stack>

// �������ڵ㶨��
template<typename T>
struct TreeNode {
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}

    T val;
    TreeNode* left;
    TreeNode* right;
};

// ����������(��ô����������Ҫ�ݹ�)
template<typename T>
class BinarySortTree {
private:
    TreeNode<T>* root;

    // ����nodeΪ���Ķ����������в���ֵΪval�Ľڵ㣬��Ϊ���˵ݹ飬public�ķ����ں���
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
    // ����ֵΪval�Ľڵ㵽��nodeΪ���Ķ�����������
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

    // ɾ��ֵΪval�Ľڵ�
    TreeNode<T>* deleteNode(TreeNode<T>* node, T val) {
        if (node == nullptr) {
            return nullptr;
        }
        if (val < node->val) {
            node->left = deleteNode(node->left, val);  // ���С�ڣ��ݹ�������
        }
        else if (val > node->val) {
            node->right = deleteNode(node->right, val);  // ������ڣ��ݹ�������
        }
        else {        //�ҵ�����Ҫ�Ľ��
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

    // �ҵ���nodeΪ���Ķ�������������С�ڵ�(�������������õ�)
    TreeNode<T>* minValueNode(TreeNode<T>* node) {
        TreeNode<T>* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // ���������������   �ݹ�
    void preOrderE(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->val << " ";
        preOrderE(node->left);
        preOrderE(node->right);
    }

    // ���������������    �ݹ�
    void midOrderE(TreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        midOrderE(node->left);
        std::cout << node->val << " ";
        midOrderE(node->right);
    }

    // ���������������    �ݹ�
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
            std::cout << std::endl << "�����˵�" << std::endl;
            std::cout << "1.���ҽ��" << std::endl;
            std::cout << "2.������" << std::endl;
            std::cout << "3.ɾ�����" << std::endl;
            std::cout << "4.�������\n" << std::endl;

            std::cout << "5.�ݹ�ǰ�����" << std::endl;
            std::cout << "6.ǰ�����\n" << std::endl;

            std::cout << "7.�ݹ��������" << std::endl;
            std::cout << "8.�������\n" << std::endl;

            std::cout << "9.�ݹ�������" << std::endl;
            std::cout << "a.�������" << std::endl;
            std::cout << "b.�˳�����" << std::endl;
            std::cout << "��ѡ�����:";
            std::cin >> choice;

            switch (choice) {
            case '1':
                std::cout << "��������Ҫ���ҵ���ֵ:";
                std::cin >> target;
                find(target);
                break;

            case '2':
                std::cout << "��������Ҫ�����Ԫ�ص�ֵ";
                std::cin >> target;
                insert(target);
                break;

            case '3':
                std::cout << "��������Ҫɾ������ֵ:";
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
                std::cout << "�����˳���" << std::endl;
                sign = 0;
                break;
            default:
                std::cout << "��Ч����!" << std::endl;
            }
        }
    }

    // ����ֵΪval�Ľڵ�
    void find(T val) {
        TreeNode<T>* node = findNode(root, val);
        if (node == nullptr)
            std::cout << "δ�ҵ�ֵΪ" << val << "�Ľ��" << std::endl;
        else
        {
            std::cout << "�ҵ���ֵΪ" << val << "�Ľ��" << std::endl;;
        }
    }

    // ����ֵΪval�Ľڵ�
    void insert(T val) {
        root = insertNode(root, val);
    }

    //ɾ��ֵΪval�Ľڵ�
    void deleteVal(T val) {
        root = deleteNode(root, val);
    }

    // �����������   �ǵݹ�
    void SequenceTraversal() {
        TreeNode<T>* temp = root;
        if (temp == nullptr) {
            return;
        }
        std::queue<TreeNode<T>*> q;    // ����һ������������
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


    // ������� �ݹ�
    void preOrder() {
        preOrderE(root);
    }

    // ������� �ݹ�
    void midOrder() {
        midOrderE(root);
    }

    // ������� �ݹ�
    void postOrder() {
        postOrderE(root);
    }


    // ����������ǵݹ飩
    void PreorderTraversal() {
        if (root == nullptr) {
            return;
        }
        std::stack<TreeNode<T>*> st;   // ����һ��ջ������
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

    // ����������ǵݹ飩
    void MidOrderTraversal() {
        std::stack<TreeNode<T>*> st;      // ����һ��ջ������
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

    // ����������ǵݹ飩
    void postOrderTraversal() {
        std::stack<TreeNode<T>*> st1, st2;     // ����һ��ջ������
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

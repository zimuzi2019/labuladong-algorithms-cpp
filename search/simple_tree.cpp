// 拿 GPT 写的，不用太纠结，其他树题就不完整实现了

#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;  
    TreeNode* right; 

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}

    TreeNode* insert(TreeNode* root, int value) {
        if (root == nullptr) {
            return new TreeNode(value);
        }

        if (value < root->value) {
            root->left = insert(root->left, value);
        }
        else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    void preorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->value << " "; 
        preorder(root->left); 
        preorder(root->right); 
    }
};

int main() {
    TreeNode* root = nullptr; 
    TreeNode tree(0); 

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);
    root = tree.insert(root, 60);
    root = tree.insert(root, 80);

    cout << "Preorder Traversal: ";
    tree.preorder(root);
    cout << endl;

    return 0;
}

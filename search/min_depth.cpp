#include <bits/stdc++.h>
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

int depth = 0;

void min_depth(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q; //
    q.push(root);
    depth++;  // 不要忘了根节点也算一层

    while(!q.empty()) {
        for(int i = 0; i < q.size(); i++) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->left == nullptr && cur->right == nullptr) { // 不要忘了，不加就是计算最大深度
                return;
            }
            
            if(cur->left != nullptr) {
                q.push(cur->left);
            }

            if(cur->left != nullptr) {
                q.push(cur->right);
            }
        }
        depth++;
    }
}

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

    min_depth(root);
    cout << depth << endl;

    return 0;
}

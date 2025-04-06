#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool checkTree(TreeNode* root) {
            return root->val == root->left->val + root->right->val;
        }
    };

int main() {
    TreeNode* left = new TreeNode(3);
    TreeNode* right = new TreeNode(5);
    TreeNode* root = new TreeNode(8, left, right);

    Solution sol;
    bool result = sol.checkTree(root);
    std::cout << (result ? "true" : "false") << std::endl;
    return 0;
}

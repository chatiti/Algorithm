#include <bits/stdc++.h>

using namespace std;

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
    unordered_map<int, int> in;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();

        for (int i = 0; i < preorder.size(); ++i) {
            in[inorder[i]] = i;
        }

        TreeNode *root = build(0, n - 1, 0, n - 1, preorder, inorder);
        return root;

    }

    TreeNode *build(int pre_l, int pre_r, int in_l, int in_r, vector<int> &preorder, vector<int> &inorder) {
        if (pre_l > pre_r) {  // 添加边界检查，递归终止条件
            return nullptr;
        }

        int in_idx = in[preorder[pre_l]];

        TreeNode *root = new TreeNode(preorder[pre_l]);

        int left_size = in_idx - in_l;

        root->left = build(pre_l + 1, pre_l + left_size, in_l, in_idx - 1, preorder, inorder);
        root->right = build(pre_l + left_size + 1, pre_r, in_idx + 1, in_r, preorder, inorder);
        return root;
    }
};
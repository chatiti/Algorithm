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
    vector<TreeNode *> arr;

    void flatten(TreeNode *root) {
        dfs(root);

        for (int i = 0; i < arr.size(); ++i) {
            if (i == arr.size() - 1) {
                arr[i]->left = arr[i]->right = nullptr;
            } else {
                arr[i]->left = nullptr;
                arr[i]->right = arr[i + 1];
            }
        }
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        arr.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
};
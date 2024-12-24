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

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        for (int i = 0; i < inorder.size(); ++i) {
            in[inorder[i]] = i;
        }

        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int in_l, int in_r, int post_l, int post_r) {
        if (in_l > in_r || post_l> post_r) {
            return nullptr;
        }

        int in_idx = in[postorder[post_r]];

        int left_size = in_idx - in_l;

        TreeNode *root = new TreeNode(postorder[post_r]);
        root->left = build(inorder, postorder, in_l, in_idx - 1, post_l, post_l + left_size - 1);
        root->right = build(inorder, postorder, in_idx + 1, in_r, post_l + left_size, post_r - 1);


        return root;


    }
};
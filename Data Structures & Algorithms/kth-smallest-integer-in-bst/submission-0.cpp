/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& v) {
        if(!root) return;

        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        vector<int> v = {};
        int kthsmall;

        inOrder(root,v);
        kthsmall = v[k-1];
        return kthsmall;
    }
};

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
    int heightBT(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(heightBT(root->left), heightBT(root->right));
    }

    int heightSum(TreeNode* root){
        if(!root) return 0;
        return (heightBT(root->left) + heightBT(root->right));
    }

    void preOrder(TreeNode* root, int& max){
        if(!root) return;
        if(max < heightSum(root)) {
            max = heightSum(root);
        }
        preOrder(root->left, max);
        preOrder(root->right, max);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int max = 0;
        preOrder(root, max);
        return max;
    }
};

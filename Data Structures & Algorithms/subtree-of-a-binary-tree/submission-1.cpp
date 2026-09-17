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
    bool sameTree(TreeNode* root, TreeNode* subRoot){
        bool ret;
        if(!root && !subRoot){
            return true;
        } else if ((root && !subRoot) || (!root && subRoot)){
            return false;
        }

        ret = (sameTree(root->left, subRoot->left)) &&
               (sameTree(root->right, subRoot->right));
        
        return (root->val == subRoot->val) && ret;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

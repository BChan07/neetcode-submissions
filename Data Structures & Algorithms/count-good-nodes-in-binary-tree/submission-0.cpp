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
    int numGoodNodes(TreeNode* node, int max) {
        if(!node) return 0;
        int maxinner = max;
        int good = 0;
        if(maxinner <= node->val) {
            good = 1;
            maxinner = node->val;
        }
        return good + numGoodNodes(node->left, maxinner) + 
                      numGoodNodes(node->right, maxinner);
    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int maxg = root->val;
        int count = 1;

        count = count + numGoodNodes(root->left, maxg) +
                          numGoodNodes(root->right, maxg);
        return count;
    }
};

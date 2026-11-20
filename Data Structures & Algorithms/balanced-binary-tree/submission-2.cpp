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

    void postOrder(TreeNode* root, queue<TreeNode*> &q){
        if(!root) return;
        postOrder(root->left, q);
        postOrder(root->right, q);
        q.push(root);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        queue<TreeNode*> q;
        postOrder(root, q);

        while(!q.empty()) {
            if(!q.front()->left && !q.front()->right) {
                q.pop();
                continue;
            }
            if((abs(heightBT(q.front()->left) - heightBT(q.front()->right)) < 2)) {
                q.pop();
                continue;
            }
            return false;
        }
        return true;
        //return (abs(heightBT(root->left) - heightBT(root->right)) < 2);   
    }
};

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> ret;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* rnode = q.front();
            int n = q.size();
            ret.push_back(rnode->val);

            for(int i = 0; i < n; i++) {
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                q.pop();
            }
        }
        return ret;
    }
};

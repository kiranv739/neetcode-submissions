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
    int count(TreeNode* root,int maxi){
        if(root==nullptr) return 0;
        maxi = max(maxi,root->val);
        int cnt = 0;
        
        if(root->val>=maxi) cnt++;

        int lc = count(root->left,maxi);
        int rc = count(root->right,maxi);

        return cnt + lc + rc;
    }
    
    int goodNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        return count(root,root->val);
    }
};

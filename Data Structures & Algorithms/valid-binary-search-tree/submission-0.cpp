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
    bool bstCheck(TreeNode* root,TreeNode* maxi,TreeNode* mini){
        if(root==nullptr) return true;
        
        if(maxi!=nullptr && root->val >= maxi->val) return false;
        if(mini!=nullptr && root->val <= mini->val) return false;

        return bstCheck(root->left,root,mini) && bstCheck(root->right,maxi,root);
    }

    bool isValidBST(TreeNode* root) {
        TreeNode* maxi = nullptr;
        TreeNode* mini = nullptr;

        bool ans = bstCheck(root,maxi,mini);
        return ans;
    }
};

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
    return new TreeNode(val);
        TreeNode* temp = root;
        TreeNode* temp2 = root;

        while(temp!=nullptr){
            temp2 = temp;
            if(val < temp->val) temp = temp->left;
            else temp = temp->right;
        }
        if(val > temp2->val && temp2->right==nullptr) temp2->right = new TreeNode(val);
        if(val < temp2->val && temp2->left==nullptr) temp2->left = new TreeNode(val); 
        
        return root;
    }
};
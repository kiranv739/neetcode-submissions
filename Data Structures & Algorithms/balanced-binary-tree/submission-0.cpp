/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:
    int height(TreeNode *root){
        if(root == nullptr) return 0;
        int lheight = height(root->left);
        if(lheight==-1) return -1;
        int rheight = height(root->right);
        if(rheight==-1) return -1;
        if(abs(lheight-rheight)>1)return -1;
        return max(lheight,rheight)+1;
    }
    
    bool isBalanced(TreeNode *root){
       return height(root)!= -1;
    }
};
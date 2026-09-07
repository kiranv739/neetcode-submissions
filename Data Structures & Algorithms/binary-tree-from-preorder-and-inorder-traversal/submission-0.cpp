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
    int index(vector<int>& inorder,int k){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==k) return i;
        }
    return -1;
    }

    TreeNode* treemaker(vector<int>& preorder, vector<int>& inorder,int& preIndex,int l,int r){
        if(l>r) return nullptr;
        TreeNode* root = new TreeNode(preorder[preIndex]);
        int inIndex = index(inorder,preorder[preIndex]);
        preIndex++;

        root->left = treemaker(preorder,inorder,preIndex,l,inIndex-1);
        root->right = treemaker(preorder,inorder,preIndex,inIndex+1,r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l = 0;
        int r = preorder.size()-1;
        int preIndex = 0;
        return treemaker(preorder,inorder,preIndex,l,r);
    }
};
